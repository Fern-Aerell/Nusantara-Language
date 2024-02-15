#include <nusantara/interpreter/interpreter.h>

#include <cmath>
#include <cstddef>
#include <format>
#include <memory>
#include <sstream>
#include <string>

#include "nstd/dinamis.h"
#include "nstd/kalimat.h"
#include "nstd/konsol.h"
#include "nstd/kosong.h"
#include "nusantara/core/error_info.h"
#include "nusantara/lexer/token_type.h"
#include "nusantara/visitor/context/context.h"
#include "nusantara/visitor/context/nilai_context.h"
#include "nusantara/visitor/context/operasi_logika_context.h"
#include "nusantara/visitor/context/operasi_logika_tidak_context.h"
#include "nusantara/visitor/context/operasi_penjumlahan_context.h"
#include "nusantara/visitor/context/operasi_penugasan_context.h"
#include "nusantara/visitor/context/operasi_penugasan_penjumlahan_context.h"
#include "nusantara/visitor/context/operasi_penugasan_perkalian_context.h"
#include "nusantara/visitor/context/operasi_perbandingan_context.h"
#include "nusantara/visitor/context/operasi_perkalian_context.h"
#include "nusantara/visitor/context/operasi_pre_post_context.h"
#include "nusantara/visitor/context/operator_logika_context.h"
#include "nusantara/visitor/context/operator_penjumlahan_context.h"
#include "nusantara/visitor/context/operator_penugasan_context.h"
#include "nusantara/visitor/context/operator_penugasan_penjumlahan_context.h"
#include "nusantara/visitor/context/operator_penugasan_perkalian_context.h"
#include "nusantara/visitor/context/operator_perbandingan_context.h"
#include "nusantara/visitor/context/operator_perkalian_context.h"

Interpreter::Interpreter(ErrorInfo errorInfo):
    errorInfo(std::move(errorInfo)) {}

nstd::dinamis Interpreter::operasiAritmatika(
    const nstd::dinamis &left, const std::string &simbolOp,
    const nstd::dinamis &right
) {
  if(simbolOp == "+") { return Interpreter::operasiPenjumlahan(left, right); }
  if(simbolOp == "-") { return Interpreter::operasiPengurangan(left, right); }
  if(simbolOp == "*") { return Interpreter::operasiPerkalian(left, right); }
  if(simbolOp == "/") { return Interpreter::operasiPembagian(left, right); }
  if(simbolOp == "%") { return Interpreter::operasiSisaPembagian(left, right); }
  throw std::runtime_error(
      this->errorInfo.inLine(this->tokens, "Operator aritmatika tidak valid.")
  );
}

nstd::dinamis Interpreter::operasiPenjumlahan(
    const nstd::dinamis &left, const nstd::dinamis &right
) {
  if(nstd::is<int>(left) && nstd::is<int>(right)) {
    return nstd::as<int>(left) + nstd::as<int>(right);
  }
  if(nstd::is<double>(left) && nstd::is<double>(right)) {
    return nstd::as<double>(left) + nstd::as<double>(right);
  }
  if(nstd::is<int>(left) && nstd::is<double>(right)) {
    return nstd::as<int>(left) + nstd::as<double>(right);
  }
  if(nstd::is<double>(left) && nstd::is<int>(right)) {
    return nstd::as<double>(left) + nstd::as<int>(right);
  }
  if(nstd::is<std::string>(left) && nstd::is<std::string>(right)) {
    return nstd::as<std::string>(left) + nstd::as<std::string>(right);
  }
  if(nstd::is<char>(left) && nstd::is<char>(right)) {
    return std::string(1, nstd::as<char>(left)) + nstd::as<char>(right);
  }
  if(nstd::is<std::string>(left) && nstd::is<char>(right)) {
    return nstd::as<std::string>(left) + nstd::as<char>(right);
  }
  if(nstd::is<char>(left) && nstd::is<std::string>(right)) {
    return nstd::as<char>(left) + nstd::as<std::string>(right);
  }
  throw std::runtime_error(
      this->errorInfo.inLine(this->tokens, "Operasi penjumlahan tidak valid.")
  );
}

nstd::dinamis Interpreter::operasiPengurangan(
    const nstd::dinamis &left, const nstd::dinamis &right
) {
  if(nstd::is<int>(left) && nstd::is<int>(right)) {
    return nstd::as<int>(left) - nstd::as<int>(right);
  }
  if(nstd::is<double>(left) && nstd::is<double>(right)) {
    return nstd::as<double>(left) - nstd::as<double>(right);
  }
  if(nstd::is<int>(left) && nstd::is<double>(right)) {
    return nstd::as<int>(left) - nstd::as<double>(right);
  }
  if(nstd::is<double>(left) && nstd::is<int>(right)) {
    return nstd::as<double>(left) - nstd::as<int>(right);
  }
  throw std::runtime_error(
      this->errorInfo.inLine(this->tokens, "Operasi pengurangan tidak valid.")
  );
}

nstd::dinamis Interpreter::operasiPerkalian(
    const nstd::dinamis &left, const nstd::dinamis &right
) {
  if(nstd::is<int>(left) && nstd::is<int>(right)) {
    return nstd::as<int>(left) * nstd::as<int>(right);
  }
  if(nstd::is<double>(left) && nstd::is<double>(right)) {
    return nstd::as<double>(left) * nstd::as<double>(right);
  }
  if(nstd::is<int>(left) && nstd::is<double>(right)) {
    return nstd::as<int>(left) * nstd::as<double>(right);
  }
  if(nstd::is<double>(left) && nstd::is<int>(right)) {
    return nstd::as<double>(left) * nstd::as<int>(right);
  }
  if(nstd::is<std::string>(left) && nstd::is<int>(right)) {
    std::ostringstream stream;
    for(size_t index = 0; index < nstd::as<int>(right); ++index) {
      stream << nstd::as<std::string>(left);
    }
    return stream.str();
  }
  throw std::runtime_error(
      this->errorInfo.inLine(this->tokens, "Operasi perkalian tidak valid.")
  );
}

nstd::dinamis Interpreter::operasiPembagian(
    const nstd::dinamis &left, const nstd::dinamis &right
) {
  if(nstd::is<int>(left) && nstd::is<int>(right)) {
    return (double)nstd::as<int>(left) / nstd::as<int>(right);
  }
  if(nstd::is<double>(left) && nstd::is<double>(right)) {
    return nstd::as<double>(left) / nstd::as<double>(right);
  }
  if(nstd::is<int>(left) && nstd::is<double>(right)) {
    return nstd::as<int>(left) / nstd::as<double>(right);
  }
  if(nstd::is<double>(left) && nstd::is<int>(right)) {
    return nstd::as<double>(left) / nstd::as<int>(right);
  }
  throw std::runtime_error(
      this->errorInfo.inLine(this->tokens, "Operasi pembagian tidak valid.")
  );
}

nstd::dinamis Interpreter::operasiSisaPembagian(
    const nstd::dinamis &left, const nstd::dinamis &right
) {
  if(nstd::is<int>(left) && nstd::is<int>(right)) {
    return nstd::as<int>(left) % nstd::as<int>(right);
  }
  if(nstd::is<double>(left) && nstd::is<double>(right)) {
    return fmod(nstd::as<double>(left), nstd::as<double>(right));
  }
  if(nstd::is<int>(left) && nstd::is<double>(right)) {
    return fmod(nstd::as<int>(left), nstd::as<double>(right));
  }
  if(nstd::is<double>(left) && nstd::is<int>(right)) {
    return fmod(nstd::as<double>(left), nstd::as<int>(right));
  }
  throw std::runtime_error(this->errorInfo.inLine(
      this->tokens, "Operasi sisa pembagian tidak valid."
  ));
}

nstd::dinamis Interpreter::operasiPerbandingan(
    const nstd::dinamis &left, const std::string &simbolOp,
    const nstd::dinamis &right
) {
  if(simbolOp == "==") { return Interpreter::operasiSama(left, right); }
  if(simbolOp == "!=") { return Interpreter::operasiTidakSama(left, right); }
  if(simbolOp == ">") { return Interpreter::operasiLebihBesar(left, right); }
  if(simbolOp == "<") { return Interpreter::operasiLebihKecil(left, right); }
  if(simbolOp == ">=") {
    return Interpreter::operasiLebihBesarSamaDengan(left, right);
  }
  if(simbolOp == "<=") {
    return Interpreter::operasiLebihKecilSamaDengan(left, right);
  }
  throw std::runtime_error(
      this->errorInfo.inLine(this->tokens, "Operator perbandingan tidak valid.")
  );
}

nstd::dinamis Interpreter::operasiSama(
    const nstd::dinamis &left, const nstd::dinamis &right
) {
  if(nstd::is<int>(left) && nstd::is<int>(right)) {
    return nstd::as<int>(left) == nstd::as<int>(right);
  }
  if(nstd::is<double>(left) && nstd::is<double>(right)) {
    return nstd::as<double>(left) == nstd::as<double>(right);
  }
  if(nstd::is<std::string>(left) && nstd::is<std::string>(right)) {
    return nstd::as<std::string>(left) == nstd::as<std::string>(right);
  }
  if(nstd::is<int>(left) && nstd::is<double>(right)) {
    return nstd::as<int>(left) == nstd::as<double>(right);
  }
  if(nstd::is<double>(left) && nstd::is<int>(right)) {
    return nstd::as<double>(left) == nstd::as<int>(right);
  }
  throw std::runtime_error(
      this->errorInfo.inLine(this->tokens, "Operasi sama tidak valid.")
  );
}

nstd::dinamis Interpreter::operasiTidakSama(
    const nstd::dinamis &left, const nstd::dinamis &right
) {
  if(nstd::is<int>(left) && nstd::is<int>(right)) {
    return nstd::as<int>(left) != nstd::as<int>(right);
  }
  if(nstd::is<double>(left) && nstd::is<double>(right)) {
    return nstd::as<double>(left) != nstd::as<double>(right);
  }
  if(nstd::is<int>(left) && nstd::is<double>(right)) {
    return nstd::as<int>(left) != nstd::as<double>(right);
  }
  if(nstd::is<double>(left) && nstd::is<int>(right)) {
    return nstd::as<double>(left) != nstd::as<int>(right);
  }
  throw std::runtime_error(
      this->errorInfo.inLine(this->tokens, "Operasi tidak sama tidak valid.")
  );
}

nstd::dinamis Interpreter::operasiLebihBesar(
    const nstd::dinamis &left, const nstd::dinamis &right
) {
  if(nstd::is<int>(left) && nstd::is<int>(right)) {
    return nstd::as<int>(left) > nstd::as<int>(right);
  }
  if(nstd::is<double>(left) && nstd::is<double>(right)) {
    return nstd::as<double>(left) > nstd::as<double>(right);
  }
  if(nstd::is<int>(left) && nstd::is<double>(right)) {
    return nstd::as<int>(left) > nstd::as<double>(right);
  }
  if(nstd::is<double>(left) && nstd::is<int>(right)) {
    return nstd::as<double>(left) > nstd::as<int>(right);
  }
  throw std::runtime_error(
      this->errorInfo.inLine(this->tokens, "Operasi lebih besar tidak valid.")
  );
}

nstd::dinamis Interpreter::operasiLebihKecil(
    const nstd::dinamis &left, const nstd::dinamis &right
) {
  if(nstd::is<int>(left) && nstd::is<int>(right)) {
    return nstd::as<int>(left) < nstd::as<int>(right);
  }
  if(nstd::is<double>(left) && nstd::is<double>(right)) {
    return nstd::as<double>(left) < nstd::as<double>(right);
  }
  if(nstd::is<int>(left) && nstd::is<double>(right)) {
    return nstd::as<int>(left) < nstd::as<double>(right);
  }
  if(nstd::is<double>(left) && nstd::is<int>(right)) {
    return nstd::as<double>(left) < nstd::as<int>(right);
  }
  throw std::runtime_error(
      this->errorInfo.inLine(this->tokens, "Operasi lebih kecil tidak valid.")
  );
}

nstd::dinamis Interpreter::operasiLebihBesarSamaDengan(
    const nstd::dinamis &left, const nstd::dinamis &right
) {
  if(nstd::is<int>(left) && nstd::is<int>(right)) {
    return nstd::as<int>(left) >= nstd::as<int>(right);
  }
  if(nstd::is<double>(left) && nstd::is<double>(right)) {
    return nstd::as<double>(left) >= nstd::as<double>(right);
  }
  if(nstd::is<int>(left) && nstd::is<double>(right)) {
    return nstd::as<int>(left) >= nstd::as<double>(right);
  }
  if(nstd::is<double>(left) && nstd::is<int>(right)) {
    return nstd::as<double>(left) >= nstd::as<int>(right);
  }
  throw std::runtime_error(this->errorInfo.inLine(
      this->tokens, "Operasi lebih besar sama dengan tidak valid."
  ));
}

nstd::dinamis Interpreter::operasiLebihKecilSamaDengan(
    const nstd::dinamis &left, const nstd::dinamis &right
) {
  if(nstd::is<int>(left) && nstd::is<int>(right)) {
    return nstd::as<int>(left) <= nstd::as<int>(right);
  }
  if(nstd::is<double>(left) && nstd::is<double>(right)) {
    return nstd::as<double>(left) <= nstd::as<double>(right);
  }
  if(nstd::is<int>(left) && nstd::is<double>(right)) {
    return nstd::as<int>(left) <= nstd::as<double>(right);
  }
  if(nstd::is<double>(left) && nstd::is<int>(right)) {
    return nstd::as<double>(left) <= nstd::as<int>(right);
  }
  throw std::runtime_error(this->errorInfo.inLine(
      this->tokens, "Operasi lebih kecil sama dengan tidak valid."
  ));
}

nstd::dinamis Interpreter::fragmentVisitOperator(
    const nstd::bisa_kosong<Token> &simbolOp, const std::string &opName
) {
  if(!nstd::kosong(simbolOp)) {
    this->tokens.push_back(simbolOp.value());
    return simbolOp.value().getValue();
  }
  throw std::runtime_error(this->errorInfo.inLine(
      this->tokens, std::format("Operator {} tidak valid.", opName)
  ));
}

nstd::dinamis Interpreter::visitNusantara(const NusantaraContext &ctx) {
  const auto &context = ctx.getKumpulanOperasiPenugasanContext();
  if(!nstd::kosong(context)) {
    for(const std::unique_ptr<Context> &child : context.value()) {
      auto *childPtr = dynamic_cast<OperasiPenugasanContext *>(child.get());
      if(childPtr != nullptr) {
        nstd::dinamis result = this->visitOperasiPenugasan(*childPtr);
        nstd::cetak(result);
      }
      this->tokens.clear();
    }
  }
  return {};
}

nstd::dinamis Interpreter::visitOperatorPenugasan(
    const OperatorPenugasanContext &ctx
) {
  return this->fragmentVisitOperator(ctx.getSimbolOp(), "penugasan");
}

nstd::dinamis Interpreter::visitOperasiPenugasan(
    const OperasiPenugasanContext &ctx
) {
  const auto &nilai = ctx.getKumpulanOperasiPenugasanPenjumlahanContext();
  const auto &simbolOp = ctx.getKumpulanOperatorPenugasanContext();
  if(nstd::kosong(nilai) || nilai.value().empty()) {
    throw std::runtime_error("Nilai tidak boleh kosong.");
  }
  const auto &leftPtr = dynamic_cast<OperasiPenugasanPenjumlahanContext *>(
      nilai.value().front().get()
  );
  if(leftPtr == nullptr) {
    throw std::runtime_error(
        "Gagal mengubah Context menjadi "
        "OperasiPenugasanPenjumlahanContext"
    );
  }
  nstd::dinamis left = this->visitOperasiPenugasanPenjumlahan(*leftPtr);
  if(nstd::kosong(simbolOp)) { return left; }
  for(size_t index = 0; index < simbolOp.value().size(); ++index) {
    const auto &simbolOpPtr =
        dynamic_cast<OperatorPenugasanContext *>(simbolOp.value()[index].get());
    const auto &rightPtr = dynamic_cast<OperasiPenugasanPenjumlahanContext *>(
        nilai.value()[index + 1].get()
    );
    if(simbolOpPtr == nullptr || rightPtr == nullptr) {
      throw std::runtime_error(
          "Gagal mengubah Context menjadi OperatorPenugasanContext "
          "atau "
          "OperasiPenugasanPenjumlahanContext"
      );
    }
    const auto simbolOp =
        nstd::as<std::string>(this->visitOperatorPenugasan(*simbolOpPtr));
    const nstd::dinamis right =
        this->visitOperasiPenugasanPenjumlahan(*rightPtr);
    throw std::runtime_error("Operasi penugasan tidak valid.");
  }
  return left;
}

nstd::dinamis Interpreter::visitOperatorPenugasanPenjumlahan(
    const OperatorPenugasanPenjumlahanContext &ctx
) {
  return this->fragmentVisitOperator(
      ctx.getSimbolOp(), "penugasan penjumlahan"
  );
}

nstd::dinamis Interpreter::visitOperasiPenugasanPenjumlahan(
    const OperasiPenugasanPenjumlahanContext &ctx
) {
  const auto &nilai = ctx.getKumpulanOperasiPenugasanPerkalianContext();
  const auto &simbolOp = ctx.getKumpulanOperatorPenugasanPenjumlahanContext();
  if(nstd::kosong(nilai) || nilai.value().empty()) {
    throw std::runtime_error("Nilai tidak boleh kosong.");
  }
  const auto &leftPtr = dynamic_cast<OperasiPenugasanPerkalianContext *>(
      nilai.value().front().get()
  );
  if(leftPtr == nullptr) {
    throw std::runtime_error(
        "Gagal mengubah Context menjadi "
        "OperasiPenugasanPerkalianContext"
    );
  }
  nstd::dinamis left = this->visitOperasiPenugasanPerkalian(*leftPtr);
  if(nstd::kosong(simbolOp)) { return left; }
  for(size_t index = 0; index < simbolOp.value().size(); ++index) {
    const auto &simbolOpPtr =
        dynamic_cast<OperatorPenugasanPenjumlahanContext *>(
            simbolOp.value()[index].get()
        );
    const auto &rightPtr = dynamic_cast<OperasiPenugasanPerkalianContext *>(
        nilai.value()[index + 1].get()
    );
    if(simbolOpPtr == nullptr || rightPtr == nullptr) {
      throw std::runtime_error(
          "Gagal mengubah Context menjadi "
          "OperatorPenugasanPenjumlahanContext atau "
          "OperasiPenugasanPerkalianContext"
      );
    }
    const auto simbolOp = nstd::as<std::string>(
        this->visitOperatorPenugasanPenjumlahan(*simbolOpPtr)
    );
    const nstd::dinamis right = this->visitOperasiPenugasanPerkalian(*rightPtr);
    throw std::runtime_error("Operasi penugasan penjumlahan tidak valid.");
  }
  return left;
}

nstd::dinamis Interpreter::visitOperatorPenugasanPerkalian(
    const OperatorPenugasanPerkalianContext &ctx
) {
  return this->fragmentVisitOperator(ctx.getSimbolOp(), "penugasan perkalian");
}

nstd::dinamis Interpreter::visitOperasiPenugasanPerkalian(
    const OperasiPenugasanPerkalianContext &ctx
) {
  const auto &nilai = ctx.getKumpulanOperasiLogikaContext();
  const auto &simbolOp = ctx.getKumpulanOperatorPenugasanPerkalianContext();
  if(nstd::kosong(nilai) || nilai.value().empty()) {
    throw std::runtime_error("Nilai tidak boleh kosong.");
  }
  const auto &leftPtr =
      dynamic_cast<OperasiLogikaContext *>(nilai.value().front().get());
  if(leftPtr == nullptr) {
    throw std::runtime_error(
        "Gagal mengubah Context menjadi OperasiLogikaContext"
    );
  }
  nstd::dinamis left = this->visitOperasiLogika(*leftPtr);
  if(nstd::kosong(simbolOp)) { return left; }
  for(size_t index = 0; index < simbolOp.value().size(); ++index) {
    const auto &simbolOpPtr = dynamic_cast<OperatorPenugasanPerkalianContext *>(
        simbolOp.value()[index].get()
    );
    const auto &rightPtr =
        dynamic_cast<OperasiLogikaContext *>(nilai.value()[index + 1].get());
    if(simbolOpPtr == nullptr || rightPtr == nullptr) {
      throw std::runtime_error(
          "Gagal mengubah Context menjadi "
          "OperatorPenugasanPerkalianContext "
          "atau OperasiLogikaContext"
      );
    }
    const auto simbolOp =
        nstd::as<std::string>(this->visitOperatorPenugasanPerkalian(*simbolOpPtr
        ));
    const nstd::dinamis right = this->visitOperasiLogika(*rightPtr);
    throw std::runtime_error("Operasi penugasan perkalian tidak valid.");
  }
  return left;
}

nstd::dinamis Interpreter::visitOperatorLogika(const OperatorLogikaContext &ctx
) {
  return this->fragmentVisitOperator(ctx.getSimbolOp(), "logika");
}

nstd::dinamis Interpreter::visitOperasiLogika(const OperasiLogikaContext &ctx) {
  const auto &nilai = ctx.getKumpulanOperasiLogikaTidakContext();
  const auto &simbolOp = ctx.getKumpulanOperatorLogikaContext();
  if(nstd::kosong(nilai) || nilai.value().empty()) {
    throw std::runtime_error("Nilai tidak boleh kosong.");
  }
  const auto &leftPtr =
      dynamic_cast<OperasiLogikaTidakContext *>(nilai.value().front().get());
  if(leftPtr == nullptr) {
    throw std::runtime_error(
        "Gagal mengubah Context menjadi OperasiLogikaTidakContext"
    );
  }
  nstd::dinamis left = this->visitOperasiLogikaTidak(*leftPtr);
  if(nstd::kosong(simbolOp)) { return left; }
  for(size_t index = 0; index < simbolOp.value().size(); ++index) {
    const auto &simbolOpPtr =
        dynamic_cast<OperatorLogikaContext *>(simbolOp.value()[index].get());
    const auto &rightPtr =
        dynamic_cast<OperasiLogikaTidakContext *>(nilai.value()[index + 1].get()
        );
    if(simbolOpPtr == nullptr || rightPtr == nullptr) {
      throw std::runtime_error(
          "Gagal mengubah Context menjadi OperatorPerbandinganContext "
          "atau "
          "OperasiPrePostContext"
      );
    }
    const auto simbolOp =
        nstd::as<std::string>(this->visitOperatorLogika(*simbolOpPtr));
    const nstd::dinamis right = this->visitOperasiLogikaTidak(*rightPtr);
    if(simbolOp == "&&") {
      if(nstd::is<bool>(left) && nstd::is<bool>(right)) {
        left = nstd::as<bool>(left) && nstd::as<bool>(right);
      } else {
        throw std::runtime_error(this->errorInfo.inLine(
            this->tokens, "Operasi logika dan tidak valid."
        ));
      }
    } else if(simbolOp == "||") {
      if(nstd::is<bool>(left) && nstd::is<bool>(right)) {
        left = nstd::as<bool>(left) || nstd::as<bool>(right);
      } else {
        throw std::runtime_error(this->errorInfo.inLine(
            this->tokens, "Operasi logika atau tidak valid."
        ));
      }
    } else {
      throw std::runtime_error(
          this->errorInfo.inLine(this->tokens, "Operator logika tidak valid.")
      );
    }
  }
  return left;
}

nstd::dinamis Interpreter::visitOperatorLogikaTidak(
    const OperatorLogikaTidakContext &ctx
) {
  return this->fragmentVisitOperator(ctx.getSimbolOp(), "logika tidak");
}

nstd::dinamis Interpreter::visitOperasiLogikaTidak(
    const OperasiLogikaTidakContext &ctx
) {
  const auto &simbolOp = ctx.getOperatorLogikaTidakContext();
  const auto &nilai = ctx.getOperasiPerbandinganContext();
  if(nstd::kosong(nilai)) {
    throw std::runtime_error("Nilai tidak boleh kosong.");
  }
  const auto &leftPtr =
      dynamic_cast<OperasiPerbandinganContext *>(nilai.value().get());
  if(leftPtr == nullptr) {
    throw std::runtime_error(
        "Gagal mengubah Context menjadi OperasiPerbandinganContext."
    );
  }
  nstd::dinamis left = this->visitOperasiPerbandingan(*leftPtr);
  if(!nstd::kosong(simbolOp)) {
    const auto &simbolOpPtr =
        dynamic_cast<OperatorLogikaTidakContext *>(simbolOp.value().get());
    if(simbolOpPtr == nullptr) {
      throw std::runtime_error(
          "Gagal mengubah Context menjadi OperatorLogikaTidakContext"
      );
    }
    const auto simbolOp =
        nstd::as<std::string>(this->visitOperatorLogikaTidak(*simbolOpPtr));
    if(simbolOp == "!") {
      if(nstd::is<bool>(left)) {
        left = !nstd::as<bool>(left);
      } else {
        throw std::runtime_error(
            this->errorInfo.inLine(this->tokens, "Operasi logika tidak valid.")
        );
      }
    } else {
      throw std::runtime_error(
          this->errorInfo.inLine(this->tokens, "Operator logika tidak valid.")
      );
    }
  }
  return left;
}

nstd::dinamis Interpreter::visitOperatorPerbandingan(
    const OperatorPerbandinganContext &ctx
) {
  return this->fragmentVisitOperator(ctx.getSimbolOp(), "perbandingan");
}

nstd::dinamis Interpreter::visitOperasiPerbandingan(
    const OperasiPerbandinganContext &ctx
) {
  const auto &nilai = ctx.getKumpulanOperasiPrePostContext();
  const auto &simbolOp = ctx.getKumpulanOperatorPerbandinganContext();
  if(nstd::kosong(nilai) || nilai.value().empty()) {
    throw std::runtime_error("Nilai tidak boleh kosong.");
  }
  const auto &leftPtr =
      dynamic_cast<OperasiPrePostContext *>(nilai.value().front().get());
  if(leftPtr == nullptr) {
    throw std::runtime_error(
        "Gagal mengubah Context menjadi OperasiPrePostContext"
    );
  }
  nstd::dinamis left = this->visitOperasiPrePost(*leftPtr);
  if(nstd::kosong(simbolOp)) { return left; }
  for(size_t index = 0; index < simbolOp.value().size(); ++index) {
    const auto &simbolOpPtr = dynamic_cast<OperatorPerbandinganContext *>(
        simbolOp.value()[index].get()
    );
    const auto &rightPtr =
        dynamic_cast<OperasiPrePostContext *>(nilai.value()[index + 1].get());
    if(simbolOpPtr == nullptr || rightPtr == nullptr) {
      throw std::runtime_error(
          "Gagal mengubah Context menjadi OperatorPerbandinganContext "
          "atau "
          "OperasiPrePostContext"
      );
    }
    const auto simbolOp =
        nstd::as<std::string>(this->visitOperatorPerbandingan(*simbolOpPtr));
    const nstd::dinamis right = this->visitOperasiPrePost(*rightPtr);
    left = Interpreter::operasiPerbandingan(left, simbolOp, right);
  }
  return left;
}

nstd::dinamis Interpreter::visitOperatorPrePost(
    const OperatorPrePostContext &ctx
) {
  return this->fragmentVisitOperator(ctx.getSimbolOp(), "pre post");
}

nstd::dinamis Interpreter::visitOperasiPrePost(const OperasiPrePostContext &ctx
) {
  const auto &nilai = ctx.getOperasiPenjumlahanContext();
  const auto &simbolOp = ctx.getOperatorPrePostContext();
  const auto &isPre = ctx.getIsPre();
  if(nstd::kosong(nilai)) {
    throw std::runtime_error("Nilai tidak boleh kosong.");
  }
  const auto &leftPtr =
      dynamic_cast<OperasiPenjumlahanContext *>(nilai.value().get());
  if(leftPtr == nullptr) {
    throw std::runtime_error(
        "Gagal mengubah Context menjadi OperasiPenjumlahanContext"
    );
  }
  nstd::dinamis left = this->visitOperasiPenjumlahan(*leftPtr);
  if(nstd::kosong(simbolOp)) { return left; }
  if(nstd::is<int>(left)) {
    if(isPre) { return 1 + nstd::as<int>(left); }
    return nstd::as<int>(left) + 1;
  } else if(nstd::is<double>(left)) {
    if(isPre) { return 1 + nstd::as<double>(left); }
    return nstd::as<double>(left) + 1;
  }
  throw std::runtime_error("Operasi pre post tidak valid.");
}

nstd::dinamis Interpreter::visitOperatorPenjumlahan(
    const OperatorPenjumlahanContext &ctx
) {
  return this->fragmentVisitOperator(ctx.getSimbolOp(), "penjumlahan");
}

nstd::dinamis Interpreter::visitOperasiPenjumlahan(
    const OperasiPenjumlahanContext &ctx
) {
  const auto &nilai = ctx.getKumpulanOperasiPerkalianContext();
  const auto &simbolOp = ctx.getKumpulanOperatorPenjumlahanContext();
  if(nstd::kosong(nilai) || nilai.value().empty()) {
    throw std::runtime_error("Nilai tidak boleh kosong.");
  }
  const auto &leftPtr =
      dynamic_cast<OperasiPerkalianContext *>(nilai.value().front().get());
  if(leftPtr == nullptr) {
    throw std::runtime_error(
        "Gagal mengubah Context menjadi OperasiPerkalianContext"
    );
  }
  nstd::dinamis left = this->visitOperasiPerkalian(*leftPtr);
  if(nstd::kosong(simbolOp)) { return left; }
  for(size_t index = 0; index < simbolOp.value().size(); ++index) {
    const auto &simbolOpPtr =
        dynamic_cast<OperatorPenjumlahanContext *>(simbolOp.value()[index].get()
        );
    const auto &rightPtr =
        dynamic_cast<OperasiPerkalianContext *>(nilai.value()[index + 1].get());
    if(simbolOpPtr == nullptr || rightPtr == nullptr) {
      throw std::runtime_error(
          "Gagal mengubah Context menjadi OperatorPenjumlahanContext "
          "atau "
          "OperasiPerkalianContext"
      );
    }
    const auto simbolOp =
        nstd::as<std::string>(this->visitOperatorPenjumlahan(*simbolOpPtr));
    const nstd::dinamis right = this->visitOperasiPerkalian(*rightPtr);
    left = Interpreter::operasiAritmatika(left, simbolOp, right);
  }
  return left;
}

nstd::dinamis Interpreter::visitOperatorPerkalian(
    const OperatorPerkalianContext &ctx
) {
  return this->fragmentVisitOperator(ctx.getSimbolOp(), "perkalian");
}

nstd::dinamis Interpreter::visitOperasiPerkalian(
    const OperasiPerkalianContext &ctx
) {
  const auto &nilai = ctx.getKumpulanNilaiContext();
  const auto &simbolOp = ctx.getKumpulanOperatorPerkalianContext();
  if(nstd::kosong(nilai) || nilai.value().empty()) {
    throw std::runtime_error("Nilai tidak boleh kosong.");
  }
  const auto &leftPtr =
      dynamic_cast<NilaiContext *>(nilai.value().front().get());
  if(leftPtr == nullptr) {
    throw std::runtime_error("Gagal mengubah Context menjadi NilaiContext");
  }
  nstd::dinamis left = this->visitNilai(*leftPtr);
  if(nstd::kosong(simbolOp)) { return left; }
  for(size_t index = 0; index < simbolOp.value().size(); ++index) {
    const auto &simbolOpPtr =
        dynamic_cast<OperatorPerkalianContext *>(simbolOp.value()[index].get());
    const auto &rightPtr =
        dynamic_cast<NilaiContext *>(nilai.value()[index + 1].get());
    if(simbolOpPtr == nullptr || rightPtr == nullptr) {
      throw std::runtime_error(
          "Gagal mengubah Context menjadi OperatorPerkalianContext "
          "atau "
          "NilaiContext"
      );
    }
    const auto simbolOp =
        nstd::as<std::string>(this->visitOperatorPerkalian(*simbolOpPtr));
    const nstd::dinamis right = this->visitNilai(*rightPtr);
    left = Interpreter::operasiAritmatika(left, simbolOp, right);
  }
  return left;
}

nstd::dinamis Interpreter::visitNilai(const NilaiContext &ctx) {
  if(!nstd::kosong(ctx.getNilai())) {
    const Token token = ctx.getNilai().value();
    this->tokens.push_back(token);
    const TokenType &type = token.getType();
    std::string nilai = token.getValue();
    if(type == TokenType::BILANGAN) {
      if(nstd::isInt(nilai)) { return nstd::asInt(nilai); }
      if(nstd::isDouble(nilai)) { return nstd::asDouble(nilai); }
    } else if(type == TokenType::KALIMAT) {
      if(nstd::isChar(nilai)) { return nstd::asChar(nilai); }
      return nstd::formatString(nilai);
    } else if(type == TokenType::BENAR) {
      return true;
    } else if(type == TokenType::SALAH) {
      return false;
    }
    throw std::runtime_error("Nilai tidak valid.");
  }
  if(!nstd::kosong(ctx.getKurungBuka())) {
    const auto &nilaiPtr = dynamic_cast<OperasiPenugasanContext *>(
        ctx.getOperasiPenugasanContext().value().get()
    );
    if(nilaiPtr != nullptr) { return this->visitOperasiPenugasan(*nilaiPtr); }
    throw std::runtime_error(
        "Gagal mengubah Context menjadi OperasiPenugasanContext"
    );
  }
  throw std::runtime_error("Nilai tidak boleh kosong.");
}
