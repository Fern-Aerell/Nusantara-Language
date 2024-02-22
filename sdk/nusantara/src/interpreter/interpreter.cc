#include "interpreter/interpreter.h"

#include <format>
#include <stdexcept>
#include <string>

#include "error/error_info.h"
#include "lexer/token.h"
#include "lexer/token_type.h"
#include "nstd/daftar.h"
#include "nstd/dinamis.h"
#include "nstd/kalimat.h"
#include "nstd/konsol.h"
#include "nstd/kosong.h"
#include "nstd/peta.h"

Interpreter::Interpreter(ErrorInfo errorInfo):
    errorInfo(std::move(errorInfo)) {}

std::runtime_error Interpreter::error(const std::string& msg) {
  return std::runtime_error(this->errorInfo.inLine(this->tokens, msg));
}

void Interpreter::createVariable(const std::string& name) {
  this->variables[name] = {};
}

void Interpreter::setVariable(
    const std::string& name, const nstd::dinamis& value
) {
  nstd::cetak(std::format(
      "Membuat variable '{}' dengan value '{}'.", name, nstd::toString(value)
  ));
  this->variables[name] = value;
}

nstd::dinamis Interpreter::getVariable(const std::string& name) {
  if(!nstd::containsKey(this->variables, name)) {
    throw std::runtime_error(std::format("Variable '{}' belum dibuat.", name));
  }
  return this->variables[name];
}

nstd::dinamis Interpreter::fragmentMultiOperasiLeftRight(
    const nstd::daftar<std::unique_ptr<Context>>& kumpulanContext,
    const nstd::daftar<Token>& kumpulanOperator
) {
  if(nstd::kosong(kumpulanContext)) {
    throw std::runtime_error("Nilai tidak boleh kosong.");
  }
  nstd::dinamis left = this->visit(kumpulanContext[0]);
  size_t index = 1;
  for(const Token& optr : kumpulanOperator) {
    this->tokens.push_back(optr);
    nstd::dinamis right = this->visit(kumpulanContext[index]);
    const TokenType& type = optr.getType();
    using namespace nstd;
    try {
      if(type == TokenType::TAMBAH) {
        left = left + right;
      } else if(type == TokenType::KURANG) {
        left = left - right;
      } else if(type == TokenType::KALI) {
        left = left * right;
      } else if(type == TokenType::BAGI) {
        left = left / right;
      } else if(type == TokenType::SISA_BAGI) {
        left = left % right;
      } else if(type == TokenType::SAMA) {
        left = left == right;
      } else if(type == TokenType::TIDAK_SAMA) {
        left = left != right;
      } else if(type == TokenType::LEBIH_BESAR) {
        left = left > right;
      } else if(type == TokenType::LEBIH_KECIL) {
        left = left < right;
      } else if(type == TokenType::LEBIH_BESAR_SAMA_DENGAN) {
        left = left >= right;
      } else if(type == TokenType::LEBIH_KECIL_SAMA_DENGAN) {
        left = left <= right;
      } else if(type == TokenType::DAN) {
        left = left && right;
      } else if(type == TokenType::ATAU) {
        left = left || right;
      } else if(type == TokenType::AND_BIT) {
        left = left & right;
      } else if(type == TokenType::OR_BIT) {
        left = left | right;
      } else if(type == TokenType::XOR_BIT) {
        left = left ^ right;
      } else if(type == TokenType::GESER_KIRI_BIT) {
        left = left << right;
      } else if(type == TokenType::GESER_KANAN_BIT) {
        left = left >> right;
      } else {
        throw this->error("Operator tidak valid.");
      }
    } catch(const std::exception& error) { throw this->error(error.what()); }
    ++index;
  }
  return left;
}

nstd::dinamis Interpreter::fragmentOperasiPrePost(
    const std::unique_ptr<Context>& context,
    const nstd::bisa_kosong<Token>& satuOperator, const bool& isPre,
    const bool& isPost
) {
  nstd::dinamis left = this->visit(context);
  if(nstd::tidakKosong(satuOperator)) {
    const Token& token = satuOperator.value();
    const TokenType& type = token.getType();
    this->tokens.push_back(token);
    using namespace nstd;
    try {
      if(type == TokenType::TAMBAH_SATU) {
        if(isPre) {
          left = 1 + left;
        } else if(isPost) {
          left = left + 1;
        }
      } else if(type == TokenType::KURANG_SATU) {
        if(isPre) {
          left = 1 - left;
        } else if(isPost) {
          left = left - 1;
        }
      } else if(type == TokenType::TIDAK) {
        if(isPre) { left = !left; }
      } else if(type == TokenType::NOT_BIT) {
        if(isPre) { left = ~left; }
      } else {
        throw this->error("Operator tidak valid.");
      }
    } catch(const std::exception& error) { throw this->error(error.what()); }
  }
  return left;
}

nstd::dinamis Interpreter::visitNusantara(const NusantaraContext& ctx) {
  for(const auto& ekspresi : ctx.getKumpulanEkspresi()) {
    nstd::dinamis hasil = this->visit(ekspresi);
    if(nstd::is<Token>(hasil)) {
      const Token& token = nstd::as<Token>(hasil);
      const TokenType& type = token.getType();
      if(type == TokenType::IDENTIFIKASI) {
        try {
          nstd::cetak(this->getVariable(token.getValue()));
        } catch(const std::exception& error) {
          throw this->error(error.what());
        }
      }
    } else {
      nstd::cetak(hasil);
    }
    this->tokens.clear();
  }
  return {};
}

nstd::dinamis Interpreter::visitEkspresi(const EkspresiContext& ctx) {
  return this->visit(ctx.getOperasiGeserKananBitSamaDenganContext());
}

nstd::dinamis Interpreter::visitOperasiGeserKananBitSamaDengan(
    const OperasiGeserKananBitSamaDenganContext& ctx
) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiGeserKiriBitSamaDenganContext(),
      ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiGeserKiriBitSamaDengan(
    const OperasiGeserKiriBitSamaDenganContext& ctx
) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiXorBitSamaDenganContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiXorBitSamaDengan(
    const OperasiXorBitSamaDenganContext& ctx
) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiOrBitSamaDenganContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiOrBitSamaDengan(
    const OperasiOrBitSamaDenganContext& ctx
) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiAndBitSamaDenganContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiAndBitSamaDengan(
    const OperasiAndBitSamaDenganContext& ctx
) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiKurangSamaDenganContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiKurangSamaDengan(
    const OperasiKurangSamaDenganContext& ctx
) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiTambahSamaDenganContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiTambahSamaDengan(
    const OperasiTambahSamaDenganContext& ctx
) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiSisaBagiSamaDenganContext(),
      ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiSisaBagiSamaDengan(
    const OperasiSisaBagiSamaDenganContext& ctx
) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiBagiSamaDenganContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiBagiSamaDengan(
    const OperasiBagiSamaDenganContext& ctx
) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiKaliSamaDenganContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiKaliSamaDengan(
    const OperasiKaliSamaDenganContext& ctx
) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiSamaDenganContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiSamaDengan(
    const OperasiSamaDenganContext& ctx
) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiKondisionalContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiKondisional(
    const OperasiKondisionalContext& ctx
) {
  const auto& kondisiPtr = ctx.getKondisiOperasiAtauContext();
  const auto& tandaTanya = ctx.getTandaTanya();
  const auto& nilaiBenarPtr = ctx.getNilaiBenarEkspresiContext();
  const auto& titikDua = ctx.getTitikDua();
  const auto& nilaiSalahPtr = ctx.getNilaiSalahEkspresiContext();
  nstd::dinamis kondisi = this->visit(kondisiPtr);
  if(nstd::tidakKosong(tandaTanya)) {
    this->tokens.push_back(tandaTanya.value());
    if(nstd::is<bool>(kondisi)) {
      if(nstd::as<bool>(kondisi)) {
        if(nstd::kosong(nilaiBenarPtr)) {
          throw std::runtime_error("Nilai benar tidak boleh kosong.");
        }
        nstd::dinamis nilaiBenar = this->visit(nilaiBenarPtr.value());
        return nilaiBenar;
      } else {
        if(nstd::kosong(nilaiSalahPtr)) {
          throw std::runtime_error("Nilai salah tidak boleh kosong.");
        }
        if(nstd::tidakKosong(titikDua)) {
          this->tokens.push_back(titikDua.value());
        }
        nstd::dinamis nilaiSalah = this->visit(nilaiSalahPtr.value());
        return nilaiSalah;
      }
    } else {
      throw this->error("Kondisi harus bernilai benar atau salah.");
    }
  }
  return kondisi;
}

nstd::dinamis Interpreter::visitOperasiAtau(const OperasiAtauContext& ctx) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiDanContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiDan(const OperasiDanContext& ctx) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiOrBitContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiOrBit(const OperasiOrBitContext& ctx) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiXorBitContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiXorBit(const OperasiXorBitContext& ctx) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiAndBitContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiAndBit(const OperasiAndBitContext& ctx) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiTidakSamaContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiTidakSama(
    const OperasiTidakSamaContext& ctx
) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiSamaContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiSama(const OperasiSamaContext& ctx) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiLebihBesarSamaDenganContext(),
      ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiLebihBesarSamaDengan(
    const OperasiLebihBesarSamaDenganContext& ctx
) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiLebihBesarContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiLebihBesar(
    const OperasiLebihBesarContext& ctx
) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiLebihKecilSamaDenganContext(),
      ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiLebihKecilSamaDengan(
    const OperasiLebihKecilSamaDenganContext& ctx
) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiLebihKecilContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiLebihKecil(
    const OperasiLebihKecilContext& ctx
) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiGeserKananBitContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiGeserKananBit(
    const OperasiGeserKananBitContext& ctx
) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiGeserKiriBitContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiGeserKiriBit(
    const OperasiGeserKiriBitContext& ctx
) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiKurangContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiKurang(const OperasiKurangContext& ctx) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiTambahContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiTambah(const OperasiTambahContext& ctx) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiSisaPembagianContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiSisaPembagian(
    const OperasiSisaPembagianContext& ctx
) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiPembagianContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiPembagian(
    const OperasiPembagianContext& ctx
) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiPerkalianContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiPerkalian(
    const OperasiPerkalianContext& ctx
) {
  return this->fragmentMultiOperasiLeftRight(
      ctx.getKumpulanOperasiTidakContext(), ctx.getKumpulanOperator()
  );
}

nstd::dinamis Interpreter::visitOperasiTidak(const OperasiTidakContext& ctx) {
  return this->fragmentOperasiPrePost(
      ctx.getOperasiNotBitContext(), ctx.getSatuOperator(), ctx.getIsPre(),
      false
  );
}

nstd::dinamis Interpreter::visitOperasiNotBit(const OperasiNotBitContext& ctx) {
  return this->fragmentOperasiPrePost(
      ctx.getOperasiKurangSatuContext(), ctx.getSatuOperator(), ctx.getIsPre(),
      false
  );
}

nstd::dinamis Interpreter::visitOperasiKurangSatu(
    const OperasiKurangSatuContext& ctx
) {
  return this->fragmentOperasiPrePost(
      ctx.getOperasiTambahSatuContext(), ctx.getSatuOperator(), ctx.getIsPre(),
      ctx.getIsPost()
  );
}

nstd::dinamis Interpreter::visitOperasiTambahSatu(
    const OperasiTambahSatuContext& ctx
) {
  return this->fragmentOperasiPrePost(
      ctx.getNilaiContext(), ctx.getSatuOperator(), ctx.getIsPre(),
      ctx.getIsPost()
  );
}

nstd::dinamis Interpreter::visitNilai(const NilaiContext& ctx) {
  const auto& nilai = ctx.getNilai();
  const auto& nilaiKalimat = ctx.getNilaiKalimatContext();
  const auto& ekspresi = ctx.getEkspresiContext();
  if(nstd::tidakKosong(nilai)) {
    const Token& token = nilai.value();
    const TokenType& type = token.getType();
    std::string klmt = token.getValue();
    this->tokens.push_back(token);
    if(type == TokenType::BILANGAN) {
      if(nstd::isFloat(klmt)) {
        return nstd::toFloat(klmt);
      } else if(nstd::isDouble(klmt)) {
        return nstd::toDouble(klmt);
      } else if(nstd::isInt(klmt)) {
        return nstd::toInt(klmt);
      }
    } else if(type == TokenType::BENAR || type == TokenType::SALAH) {
      if(nstd::isBool(klmt)) { return nstd::toBool(klmt); }
    } else if(type == TokenType::IDENTIFIKASI) {
      return token;
    }
  } else if(nstd::tidakKosong(nilaiKalimat)) {
    return this->visit(nilaiKalimat.value());
  } else if(nstd::tidakKosong(ekspresi)) {
    return this->visit(ekspresi.value());
  }
  throw this->error("Nilai tidak valid.");
}

nstd::dinamis Interpreter::visitNilaiKalimat(const NilaiKalimatContext& ctx) {
  const auto& kumpulanToken = ctx.getKumpulanToken();
  const auto& kumpulanEkspresi = ctx.getkumpulanEkspresiContext();
  std::string klmt;
  size_t ekspresiIndex = 0;
  for(size_t index = 0; index < kumpulanToken.size(); ++index) {
    const Token& token = kumpulanToken[index];
    const TokenType& type = token.getType();
    this->tokens.push_back(token);
    if(type == TokenType::GARIS_MIRING_KEBALIK) {
      ++index;
      const Token& token = kumpulanToken[index];
      const std::string& value = token.getValue();
      if(value == "n") {
        klmt += "\n";
      } else if(value == "t") {
        klmt += "\t";
      } else {
        klmt += value;
      }
    } else if(type == TokenType::DOLAR) {
      ++index;
      const Token& token = kumpulanToken[index];
      const TokenType& type = token.getType();
      this->tokens.push_back(token);
      if(type == TokenType::KURUNG_KURAWAL_BUKA) {
        if(nstd::tidakKosong(kumpulanEkspresi)) {
          klmt += nstd::toString(this->visit(kumpulanEkspresi[ekspresiIndex]));
          ++ekspresiIndex;
        }
      } else if(type == TokenType::IDENTIFIKASI) {
        klmt += nstd::toString(this->getVariable(token.getValue()));
      }
      ++index;
    } else {
      klmt += token.getValue();
    }
  }
  return klmt;
}
