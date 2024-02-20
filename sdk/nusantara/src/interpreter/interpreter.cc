#include "interpreter/interpreter.h"

#include <stdexcept>

#include "nstd/daftar.h"
#include "nstd/dinamis.h"
#include "nstd/konsol.h"
#include "visitor/context/ekspresi/ekspresi_context.h"
#include "visitor/context/operasi/operasi_geser_kanan_bit_sama_dengan_context.h"

std::runtime_error Interpreter::error(const std::string& msg) {
  return std::runtime_error(this->errorInfo.inLine(this->tokens, msg));
}

nstd::dinamis Interpreter::visitNusantara(const NusantaraContext& ctx) {
  for(const auto& ekspresi : ctx.getKumpulanEkspresi()) {
    nstd::dinamis hasil = this->visit(ekspresi);
    nstd::cetak(hasil);
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
  return {};
}

nstd::dinamis Interpreter::visitOperasiGeserKiriBitSamaDengan(
    const OperasiGeserKiriBitSamaDenganContext& ctx
) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiXorBitSamaDengan(
    const OperasiXorBitSamaDenganContext& ctx
) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiOrBitSamaDengan(
    const OperasiOrBitSamaDenganContext& ctx
) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiAndBitSamaDengan(
    const OperasiAndBitSamaDenganContext& ctx
) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiKurangSamaDengan(
    const OperasiKurangSamaDenganContext& ctx
) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiTambahSamaDengan(
    const OperasiTambahSamaDenganContext& ctx
) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiSisaBagiSamaDengan(
    const OperasiSisaBagiSamaDenganContext& ctx
) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiBagiSamaDengan(
    const OperasiBagiSamaDenganContext& ctx
) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiKaliSamaDengan(
    const OperasiKaliSamaDenganContext& ctx
) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiSamaDengan(
    const OperasiSamaDenganContext& ctx
) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiAtau(const OperasiAtauContext& ctx) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiDan(const OperasiDanContext& ctx) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiOrBit(const OperasiOrBitContext& ctx) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiXorBit(const OperasiXorBitContext& ctx) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiAndBit(const OperasiAndBitContext& ctx) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiTidakSama(
    const OperasiTidakSamaContext& ctx
) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiSama(const OperasiSamaContext& ctx) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiLebihBesarSamaDengan(
    const OperasiLebihBesarSamaDenganContext& ctx
) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiLebihBesar(
    const OperasiLebihBesarContext& ctx
) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiLebihKecilSamaDengan(
    const OperasiLebihKecilSamaDenganContext& ctx
) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiLebihKecil(
    const OperasiLebihKecilContext& ctx
) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiGeserKananBit(
    const OperasiGeserKananBitContext& ctx
) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiGeserKiriBit(
    const OperasiGeserKiriBitContext& ctx
) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiKurang(const OperasiKurangContext& ctx) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiTambah(const OperasiTambahContext& ctx) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiSisaPembagian(
    const OperasiSisaPembagianContext& ctx
) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiPembagian(
    const OperasiPembagianContext& ctx
) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiPerkalian(
    const OperasiPerkalianContext& ctx
) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiTidak(const OperasiTidakContext& ctx) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiNotBit(const OperasiNotBitContext& ctx) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiKurangSatu(
    const OperasiKurangSatuContext& ctx
) {
  return {};
}

nstd::dinamis Interpreter::visitOperasiTambahSatu(
    const OperasiTambahSatuContext& ctx
) {
  return {};
}

nstd::dinamis Interpreter::visitNilai(const NilaiContext& ctx) { return {}; }

nstd::dinamis Interpreter::visitNilaiKalimat(const NilaiKalimatContext& ctx) {
  return {};
}
