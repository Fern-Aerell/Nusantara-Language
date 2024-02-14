#include <nusantara/interpreter/interpreter.h>

#include <cmath>
#include <cstddef>
#include <format>
#include <memory>
#include <sstream>
#include <string>

#include "nusantara/core/core.h"
#include "nusantara/core/error_info.h"
#include "nusantara/core/konsol.h"
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
    nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::kalimat> &simbolOp,
    nstd::konst<nstd::dinamis> &right
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
    nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::dinamis> &right
) {
  if(nstd::isBulat(left) && nstd::isBulat(right)) {
    return nstd::asBulat(left) + nstd::asBulat(right);
  }
  if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
    return nstd::asDesimal(left) + nstd::asDesimal(right);
  }
  if(nstd::isBulat(left) && nstd::isDesimal(right)) {
    return nstd::asBulat(left) + nstd::asDesimal(right);
  }
  if(nstd::isDesimal(left) && nstd::isBulat(right)) {
    return nstd::asDesimal(left) + nstd::asBulat(right);
  }
  if(nstd::isKalimat(left) && nstd::isKalimat(right)) {
    return nstd::asKalimat(left) + nstd::asKalimat(right);
  }
  if(nstd::isKarakter(left) && nstd::isKarakter(right)) {
    return nstd::kalimat(1, nstd::asKarakter(left)) + nstd::asKarakter(right);
  }
  if(nstd::isKalimat(left) && nstd::isKarakter(right)) {
    return nstd::asKalimat(left) + nstd::asKarakter(right);
  }
  if(nstd::isKarakter(left) && nstd::isKalimat(right)) {
    return nstd::asKarakter(left) + nstd::asKalimat(right);
  }
  throw std::runtime_error(
      this->errorInfo.inLine(this->tokens, "Operasi penjumlahan tidak valid.")
  );
}

nstd::dinamis Interpreter::operasiPengurangan(
    nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::dinamis> &right
) {
  if(nstd::isBulat(left) && nstd::isBulat(right)) {
    return nstd::asBulat(left) - nstd::asBulat(right);
  }
  if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
    return nstd::asDesimal(left) - nstd::asDesimal(right);
  }
  if(nstd::isBulat(left) && nstd::isDesimal(right)) {
    return nstd::asBulat(left) - nstd::asDesimal(right);
  }
  if(nstd::isDesimal(left) && nstd::isBulat(right)) {
    return nstd::asDesimal(left) - nstd::asBulat(right);
  }
  throw std::runtime_error(
      this->errorInfo.inLine(this->tokens, "Operasi pengurangan tidak valid.")
  );
}

nstd::dinamis Interpreter::operasiPerkalian(
    nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::dinamis> &right
) {
  if(nstd::isBulat(left) && nstd::isBulat(right)) {
    return nstd::asBulat(left) * nstd::asBulat(right);
  }
  if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
    return nstd::asDesimal(left) * nstd::asDesimal(right);
  }
  if(nstd::isBulat(left) && nstd::isDesimal(right)) {
    return nstd::asBulat(left) * nstd::asDesimal(right);
  }
  if(nstd::isDesimal(left) && nstd::isBulat(right)) {
    return nstd::asDesimal(left) * nstd::asBulat(right);
  }
  if(nstd::isKalimat(left) && nstd::isBulat(right)) {
    std::ostringstream stream;
    for(size_t index = 0; index < nstd::asBulat(right); ++index) {
      stream << nstd::asKalimat(left);
    }
    return stream.str();
  }
  throw std::runtime_error(
      this->errorInfo.inLine(this->tokens, "Operasi perkalian tidak valid.")
  );
}

nstd::dinamis Interpreter::operasiPembagian(
    nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::dinamis> &right
) {
  if(nstd::isBulat(left) && nstd::isBulat(right)) {
    return (nstd::desimal)nstd::asBulat(left) / nstd::asBulat(right);
  }
  if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
    return nstd::asDesimal(left) / nstd::asDesimal(right);
  }
  if(nstd::isBulat(left) && nstd::isDesimal(right)) {
    return nstd::asBulat(left) / nstd::asDesimal(right);
  }
  if(nstd::isDesimal(left) && nstd::isBulat(right)) {
    return nstd::asDesimal(left) / nstd::asBulat(right);
  }
  throw std::runtime_error(
      this->errorInfo.inLine(this->tokens, "Operasi pembagian tidak valid.")
  );
}

nstd::dinamis Interpreter::operasiSisaPembagian(
    nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::dinamis> &right
) {
  if(nstd::isBulat(left) && nstd::isBulat(right)) {
    return nstd::asBulat(left) % nstd::asBulat(right);
  }
  if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
    return fmod(nstd::asDesimal(left), nstd::asDesimal(right));
  }
  if(nstd::isBulat(left) && nstd::isDesimal(right)) {
    return fmod(nstd::asBulat(left), nstd::asDesimal(right));
  }
  if(nstd::isDesimal(left) && nstd::isBulat(right)) {
    return fmod(nstd::asDesimal(left), nstd::asBulat(right));
  }
  throw std::runtime_error(this->errorInfo.inLine(
      this->tokens, "Operasi sisa pembagian tidak valid."
  ));
}

nstd::dinamis Interpreter::operasiPerbandingan(
    nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::kalimat> &simbolOp,
    nstd::konst<nstd::dinamis> &right
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
    nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::dinamis> &right
) {
  if(nstd::isBulat(left) && nstd::isBulat(right)) {
    return nstd::asBulat(left) == nstd::asBulat(right);
  }
  if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
    return nstd::asDesimal(left) == nstd::asDesimal(right);
  }
  if(nstd::isKalimat(left) && nstd::isKalimat(right)) {
    return nstd::asKalimat(left) == nstd::asKalimat(right);
  }
  if(nstd::isBulat(left) && nstd::isDesimal(right)) {
    return nstd::asBulat(left) == nstd::asDesimal(right);
  }
  if(nstd::isDesimal(left) && nstd::isBulat(right)) {
    return nstd::asDesimal(left) == nstd::asBulat(right);
  }
  throw std::runtime_error(
      this->errorInfo.inLine(this->tokens, "Operasi sama tidak valid.")
  );
}

nstd::dinamis Interpreter::operasiTidakSama(
    nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::dinamis> &right
) {
  if(nstd::isBulat(left) && nstd::isBulat(right)) {
    return nstd::asBulat(left) != nstd::asBulat(right);
  }
  if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
    return nstd::asDesimal(left) != nstd::asDesimal(right);
  }
  if(nstd::isBulat(left) && nstd::isDesimal(right)) {
    return nstd::asBulat(left) != nstd::asDesimal(right);
  }
  if(nstd::isDesimal(left) && nstd::isBulat(right)) {
    return nstd::asDesimal(left) != nstd::asBulat(right);
  }
  throw std::runtime_error(
      this->errorInfo.inLine(this->tokens, "Operasi tidak sama tidak valid.")
  );
}

nstd::dinamis Interpreter::operasiLebihBesar(
    nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::dinamis> &right
) {
  if(nstd::isBulat(left) && nstd::isBulat(right)) {
    return nstd::asBulat(left) > nstd::asBulat(right);
  }
  if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
    return nstd::asDesimal(left) > nstd::asDesimal(right);
  }
  if(nstd::isBulat(left) && nstd::isDesimal(right)) {
    return nstd::asBulat(left) > nstd::asDesimal(right);
  }
  if(nstd::isDesimal(left) && nstd::isBulat(right)) {
    return nstd::asDesimal(left) > nstd::asBulat(right);
  }
  throw std::runtime_error(
      this->errorInfo.inLine(this->tokens, "Operasi lebih besar tidak valid.")
  );
}

nstd::dinamis Interpreter::operasiLebihKecil(
    nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::dinamis> &right
) {
  if(nstd::isBulat(left) && nstd::isBulat(right)) {
    return nstd::asBulat(left) < nstd::asBulat(right);
  }
  if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
    return nstd::asDesimal(left) < nstd::asDesimal(right);
  }
  if(nstd::isBulat(left) && nstd::isDesimal(right)) {
    return nstd::asBulat(left) < nstd::asDesimal(right);
  }
  if(nstd::isDesimal(left) && nstd::isBulat(right)) {
    return nstd::asDesimal(left) < nstd::asBulat(right);
  }
  throw std::runtime_error(
      this->errorInfo.inLine(this->tokens, "Operasi lebih kecil tidak valid.")
  );
}

nstd::dinamis Interpreter::operasiLebihBesarSamaDengan(
    nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::dinamis> &right
) {
  if(nstd::isBulat(left) && nstd::isBulat(right)) {
    return nstd::asBulat(left) >= nstd::asBulat(right);
  }
  if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
    return nstd::asDesimal(left) >= nstd::asDesimal(right);
  }
  if(nstd::isBulat(left) && nstd::isDesimal(right)) {
    return nstd::asBulat(left) >= nstd::asDesimal(right);
  }
  if(nstd::isDesimal(left) && nstd::isBulat(right)) {
    return nstd::asDesimal(left) >= nstd::asBulat(right);
  }
  throw std::runtime_error(this->errorInfo.inLine(
      this->tokens, "Operasi lebih besar sama dengan tidak valid."
  ));
}

nstd::dinamis Interpreter::operasiLebihKecilSamaDengan(
    nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::dinamis> &right
) {
  if(nstd::isBulat(left) && nstd::isBulat(right)) {
    return nstd::asBulat(left) <= nstd::asBulat(right);
  }
  if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
    return nstd::asDesimal(left) <= nstd::asDesimal(right);
  }
  if(nstd::isBulat(left) && nstd::isDesimal(right)) {
    return nstd::asBulat(left) <= nstd::asDesimal(right);
  }
  if(nstd::isDesimal(left) && nstd::isBulat(right)) {
    return nstd::asDesimal(left) <= nstd::asBulat(right);
  }
  throw std::runtime_error(this->errorInfo.inLine(
      this->tokens, "Operasi lebih kecil sama dengan tidak valid."
  ));
}

nstd::dinamis Interpreter::fragmentVisitOperator(
    nstd::konst<nstd::bisa_kosong<Token>> &simbolOp,
    nstd::konst<nstd::kalimat> &opName
) {
  if(!nstd::isKosong(simbolOp)) {
    this->tokens.push_back(simbolOp.value());
    return simbolOp.value().getValue();
  }
  throw std::runtime_error(this->errorInfo.inLine(
      this->tokens, std::format("Operator {} tidak valid.", opName)
  ));
}

nstd::dinamis Interpreter::visitNusantara(nstd::konst<NusantaraContext> &ctx) {
  const auto &context = ctx.getKumpulanOperasiPenugasanContext();
  if(!nstd::isKosong(context)) {
    for(nstd::konst<std::unique_ptr<Context>> &child : context.value()) {
      auto *childPtr = dynamic_cast<OperasiPenugasanContext *>(child.get());
      if(childPtr != nullptr) {
        nstd::dinamis result = this->visitOperasiPenugasan(*childPtr);
        nstd::Konsol::cetak(result);
      }
      this->tokens.clear();
    }
  }
  return {};
}

nstd::dinamis Interpreter::visitOperatorPenugasan(
    nstd::konst<OperatorPenugasanContext> &ctx
) {
  return this->fragmentVisitOperator(ctx.getSimbolOp(), "penugasan");
}

nstd::dinamis Interpreter::visitOperasiPenugasan(
    nstd::konst<OperasiPenugasanContext> &ctx
) {
  const auto &nilai = ctx.getKumpulanOperasiPenugasanPenjumlahanContext();
  const auto &simbolOp = ctx.getKumpulanOperatorPenugasanContext();
  if(nstd::isKosong(nilai) || nilai.value().empty()) {
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
  if(nstd::isKosong(simbolOp)) { return left; }
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
    nstd::konst<nstd::kalimat> simbolOp =
        nstd::asKalimat(this->visitOperatorPenugasan(*simbolOpPtr));
    nstd::konst<nstd::dinamis> right =
        this->visitOperasiPenugasanPenjumlahan(*rightPtr);
    throw std::runtime_error("Operasi penugasan tidak valid.");
  }
  return left;
}

nstd::dinamis Interpreter::visitOperatorPenugasanPenjumlahan(
    nstd::konst<OperatorPenugasanPenjumlahanContext> &ctx
) {
  return this->fragmentVisitOperator(
      ctx.getSimbolOp(), "penugasan penjumlahan"
  );
}

nstd::dinamis Interpreter::visitOperasiPenugasanPenjumlahan(
    nstd::konst<OperasiPenugasanPenjumlahanContext> &ctx
) {
  const auto &nilai = ctx.getKumpulanOperasiPenugasanPerkalianContext();
  const auto &simbolOp = ctx.getKumpulanOperatorPenugasanPenjumlahanContext();
  if(nstd::isKosong(nilai) || nilai.value().empty()) {
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
  if(nstd::isKosong(simbolOp)) { return left; }
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
    nstd::konst<nstd::kalimat> simbolOp =
        nstd::asKalimat(this->visitOperatorPenugasanPenjumlahan(*simbolOpPtr));
    nstd::konst<nstd::dinamis> right =
        this->visitOperasiPenugasanPerkalian(*rightPtr);
    throw std::runtime_error("Operasi penugasan penjumlahan tidak valid.");
  }
  return left;
}

nstd::dinamis Interpreter::visitOperatorPenugasanPerkalian(
    nstd::konst<OperatorPenugasanPerkalianContext> &ctx
) {
  return this->fragmentVisitOperator(ctx.getSimbolOp(), "penugasan perkalian");
}

nstd::dinamis Interpreter::visitOperasiPenugasanPerkalian(
    nstd::konst<OperasiPenugasanPerkalianContext> &ctx
) {
  const auto &nilai = ctx.getKumpulanOperasiLogikaContext();
  const auto &simbolOp = ctx.getKumpulanOperatorPenugasanPerkalianContext();
  if(nstd::isKosong(nilai) || nilai.value().empty()) {
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
  if(nstd::isKosong(simbolOp)) { return left; }
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
    nstd::konst<nstd::kalimat> simbolOp =
        nstd::asKalimat(this->visitOperatorPenugasanPerkalian(*simbolOpPtr));
    nstd::konst<nstd::dinamis> right = this->visitOperasiLogika(*rightPtr);
    throw std::runtime_error("Operasi penugasan perkalian tidak valid.");
  }
  return left;
}

nstd::dinamis Interpreter::visitOperatorLogika(
    nstd::konst<OperatorLogikaContext> &ctx
) {
  return this->fragmentVisitOperator(ctx.getSimbolOp(), "logika");
}

nstd::dinamis Interpreter::visitOperasiLogika(
    nstd::konst<OperasiLogikaContext> &ctx
) {
  const auto &nilai = ctx.getKumpulanOperasiLogikaTidakContext();
  const auto &simbolOp = ctx.getKumpulanOperatorLogikaContext();
  if(nstd::isKosong(nilai) || nilai.value().empty()) {
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
  if(nstd::isKosong(simbolOp)) { return left; }
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
    nstd::konst<nstd::kalimat> simbolOp =
        nstd::asKalimat(this->visitOperatorLogika(*simbolOpPtr));
    nstd::konst<nstd::dinamis> right = this->visitOperasiLogikaTidak(*rightPtr);
    if(simbolOp == "&&") {
      if(nstd::isBenarSalah(left) && nstd::isBenarSalah(right)) {
        left = nstd::asBenarSalah(left) && nstd::asBenarSalah(right);
      } else {
        throw std::runtime_error(this->errorInfo.inLine(
            this->tokens, "Operasi logika dan tidak valid."
        ));
      }
    } else if(simbolOp == "||") {
      if(nstd::isBenarSalah(left) && nstd::isBenarSalah(right)) {
        left = nstd::asBenarSalah(left) || nstd::asBenarSalah(right);
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
    nstd::konst<OperatorLogikaTidakContext> &ctx
) {
  return this->fragmentVisitOperator(ctx.getSimbolOp(), "logika tidak");
}

nstd::dinamis Interpreter::visitOperasiLogikaTidak(
    nstd::konst<OperasiLogikaTidakContext> &ctx
) {
  const auto &simbolOp = ctx.getOperatorLogikaTidakContext();
  const auto &nilai = ctx.getOperasiPerbandinganContext();
  if(nstd::isKosong(nilai)) {
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
  if(!nstd::isKosong(simbolOp)) {
    const auto &simbolOpPtr =
        dynamic_cast<OperatorLogikaTidakContext *>(simbolOp.value().get());
    if(simbolOpPtr == nullptr) {
      throw std::runtime_error(
          "Gagal mengubah Context menjadi OperatorLogikaTidakContext"
      );
    }
    nstd::konst<nstd::kalimat> simbolOp =
        nstd::asKalimat(this->visitOperatorLogikaTidak(*simbolOpPtr));
    if(simbolOp == "!") {
      if(nstd::isBenarSalah(left)) {
        left = !nstd::asBenarSalah(left);
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
    nstd::konst<OperatorPerbandinganContext> &ctx
) {
  return this->fragmentVisitOperator(ctx.getSimbolOp(), "perbandingan");
}

nstd::dinamis Interpreter::visitOperasiPerbandingan(
    nstd::konst<OperasiPerbandinganContext> &ctx
) {
  const auto &nilai = ctx.getKumpulanOperasiPrePostContext();
  const auto &simbolOp = ctx.getKumpulanOperatorPerbandinganContext();
  if(nstd::isKosong(nilai) || nilai.value().empty()) {
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
  if(nstd::isKosong(simbolOp)) { return left; }
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
    nstd::konst<nstd::kalimat> simbolOp =
        nstd::asKalimat(this->visitOperatorPerbandingan(*simbolOpPtr));
    nstd::konst<nstd::dinamis> right = this->visitOperasiPrePost(*rightPtr);
    left = Interpreter::operasiPerbandingan(left, simbolOp, right);
  }
  return left;
}

nstd::dinamis Interpreter::visitOperatorPrePost(
    nstd::konst<OperatorPrePostContext> &ctx
) {
  return this->fragmentVisitOperator(ctx.getSimbolOp(), "pre post");
}

nstd::dinamis Interpreter::visitOperasiPrePost(
    nstd::konst<OperasiPrePostContext> &ctx
) {
  const auto &nilai = ctx.getOperasiPenjumlahanContext();
  const auto &simbolOp = ctx.getOperatorPrePostContext();
  const auto &isPre = ctx.getIsPre();
  if(nstd::isKosong(nilai)) {
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
  if(nstd::isKosong(simbolOp)) { return left; }
  if(nstd::isBulat(left)) {
    if(isPre) { return 1 + nstd::asBulat(left); }
    return nstd::asBulat(left) + 1;
  } else if(nstd::isDesimal(left)) {
    if(isPre) { return 1 + nstd::asDesimal(left); }
    return nstd::asDesimal(left) + 1;
  }
  throw std::runtime_error("Operasi pre post tidak valid.");
}

nstd::dinamis Interpreter::visitOperatorPenjumlahan(
    nstd::konst<OperatorPenjumlahanContext> &ctx
) {
  return this->fragmentVisitOperator(ctx.getSimbolOp(), "penjumlahan");
}

nstd::dinamis Interpreter::visitOperasiPenjumlahan(
    nstd::konst<OperasiPenjumlahanContext> &ctx
) {
  const auto &nilai = ctx.getKumpulanOperasiPerkalianContext();
  const auto &simbolOp = ctx.getKumpulanOperatorPenjumlahanContext();
  if(nstd::isKosong(nilai) || nilai.value().empty()) {
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
  if(nstd::isKosong(simbolOp)) { return left; }
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
    nstd::konst<nstd::kalimat> simbolOp =
        nstd::asKalimat(this->visitOperatorPenjumlahan(*simbolOpPtr));
    nstd::konst<nstd::dinamis> right = this->visitOperasiPerkalian(*rightPtr);
    left = Interpreter::operasiAritmatika(left, simbolOp, right);
  }
  return left;
}

nstd::dinamis Interpreter::visitOperatorPerkalian(
    nstd::konst<OperatorPerkalianContext> &ctx
) {
  return this->fragmentVisitOperator(ctx.getSimbolOp(), "perkalian");
}

nstd::dinamis Interpreter::visitOperasiPerkalian(
    nstd::konst<OperasiPerkalianContext> &ctx
) {
  const auto &nilai = ctx.getKumpulanNilaiContext();
  const auto &simbolOp = ctx.getKumpulanOperatorPerkalianContext();
  if(nstd::isKosong(nilai) || nilai.value().empty()) {
    throw std::runtime_error("Nilai tidak boleh kosong.");
  }
  const auto &leftPtr =
      dynamic_cast<NilaiContext *>(nilai.value().front().get());
  if(leftPtr == nullptr) {
    throw std::runtime_error("Gagal mengubah Context menjadi NilaiContext");
  }
  nstd::dinamis left = this->visitNilai(*leftPtr);
  if(nstd::isKosong(simbolOp)) { return left; }
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
    nstd::konst<nstd::kalimat> simbolOp =
        nstd::asKalimat(this->visitOperatorPerkalian(*simbolOpPtr));
    nstd::konst<nstd::dinamis> right = this->visitNilai(*rightPtr);
    left = Interpreter::operasiAritmatika(left, simbolOp, right);
  }
  return left;
}

nstd::dinamis Interpreter::visitNilai(nstd::konst<NilaiContext> &ctx) {
  if(!nstd::isKosong(ctx.getNilai())) {
    nstd::konst<Token> token = ctx.getNilai().value();
    this->tokens.push_back(token);
    nstd::konst<TokenType> &type = token.getType();
    nstd::kalimat nilai = token.getValue();
    if(type == TokenType::BILANGAN) {
      return std::stoi(nilai);
    } else if(type == TokenType::DESIMAL) {
      nilai.replace(nilai.find(','), 1, ".");
      return std::stod(nilai);
    } else if(type == TokenType::KALIMAT) {
      nilai.pop_back();
      nilai = nilai.substr(1);
      return nilai;
    } else if(type == TokenType::BENAR) {
      return benar;
    } else if(type == TokenType::SALAH) {
      return salah;
    }
    throw std::runtime_error("Nilai tidak valid.");
  }
  if(!nstd::isKosong(ctx.getKurungBuka())) {
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
