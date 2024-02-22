#pragma once

#include <memory>
#include <stdexcept>
#include <string>

#include "error/error_info.h"
#include "lexer/token.h"
#include "nstd/daftar.h"
#include "nstd/dinamis.h"
#include "visitor/context/context.h"
#include "visitor/context/operasi/operasi_kondisional_context.h"
#include "visitor/visitor.h"

class Interpreter: public Visitor<nstd::dinamis> {
  public:
    explicit Interpreter(ErrorInfo errorInfo);
    nstd::dinamis visitNusantara(const NusantaraContext& ctx) override;
    nstd::dinamis visitEkspresi(const EkspresiContext& ctx) override;
    nstd::dinamis visitOperasiGeserKananBitSamaDengan(
        const OperasiGeserKananBitSamaDenganContext& ctx
    ) override;
    nstd::dinamis visitOperasiGeserKiriBitSamaDengan(
        const OperasiGeserKiriBitSamaDenganContext& ctx
    ) override;
    nstd::dinamis visitOperasiXorBitSamaDengan(
        const OperasiXorBitSamaDenganContext& ctx
    ) override;
    nstd::dinamis visitOperasiOrBitSamaDengan(
        const OperasiOrBitSamaDenganContext& ctx
    ) override;
    nstd::dinamis visitOperasiAndBitSamaDengan(
        const OperasiAndBitSamaDenganContext& ctx
    ) override;
    nstd::dinamis visitOperasiKurangSamaDengan(
        const OperasiKurangSamaDenganContext& ctx
    ) override;
    nstd::dinamis visitOperasiTambahSamaDengan(
        const OperasiTambahSamaDenganContext& ctx
    ) override;
    nstd::dinamis visitOperasiSisaBagiSamaDengan(
        const OperasiSisaBagiSamaDenganContext& ctx
    ) override;
    nstd::dinamis visitOperasiBagiSamaDengan(
        const OperasiBagiSamaDenganContext& ctx
    ) override;
    nstd::dinamis visitOperasiKaliSamaDengan(
        const OperasiKaliSamaDenganContext& ctx
    ) override;
    nstd::dinamis visitOperasiSamaDengan(const OperasiSamaDenganContext& ctx
    ) override;
    nstd::dinamis visitOperasiKondisional(const OperasiKondisionalContext& ctx
    ) override;
    nstd::dinamis visitOperasiAtau(const OperasiAtauContext& ctx) override;
    nstd::dinamis visitOperasiDan(const OperasiDanContext& ctx) override;
    nstd::dinamis visitOperasiOrBit(const OperasiOrBitContext& ctx) override;
    nstd::dinamis visitOperasiXorBit(const OperasiXorBitContext& ctx) override;
    nstd::dinamis visitOperasiAndBit(const OperasiAndBitContext& ctx) override;
    nstd::dinamis visitOperasiTidakSama(const OperasiTidakSamaContext& ctx
    ) override;
    nstd::dinamis visitOperasiSama(const OperasiSamaContext& ctx) override;
    nstd::dinamis visitOperasiLebihBesarSamaDengan(
        const OperasiLebihBesarSamaDenganContext& ctx
    ) override;
    nstd::dinamis visitOperasiLebihBesar(const OperasiLebihBesarContext& ctx
    ) override;
    nstd::dinamis visitOperasiLebihKecilSamaDengan(
        const OperasiLebihKecilSamaDenganContext& ctx
    ) override;
    nstd::dinamis visitOperasiLebihKecil(const OperasiLebihKecilContext& ctx
    ) override;
    nstd::dinamis visitOperasiGeserKananBit(
        const OperasiGeserKananBitContext& ctx
    ) override;
    nstd::dinamis visitOperasiGeserKiriBit(const OperasiGeserKiriBitContext& ctx
    ) override;
    nstd::dinamis visitOperasiKurang(const OperasiKurangContext& ctx) override;
    nstd::dinamis visitOperasiTambah(const OperasiTambahContext& ctx) override;
    nstd::dinamis visitOperasiSisaPembagian(
        const OperasiSisaPembagianContext& ctx
    ) override;
    nstd::dinamis visitOperasiPembagian(const OperasiPembagianContext& ctx
    ) override;
    nstd::dinamis visitOperasiPerkalian(const OperasiPerkalianContext& ctx
    ) override;
    nstd::dinamis visitOperasiTidak(const OperasiTidakContext& ctx) override;
    nstd::dinamis visitOperasiNotBit(const OperasiNotBitContext& ctx) override;
    nstd::dinamis visitOperasiKurangSatu(const OperasiKurangSatuContext& ctx
    ) override;
    nstd::dinamis visitOperasiTambahSatu(const OperasiTambahSatuContext& ctx
    ) override;
    nstd::dinamis visitNilai(const NilaiContext& ctx) override;
    nstd::dinamis visitNilaiKalimat(const NilaiKalimatContext& ctx) override;

  private:
    ErrorInfo errorInfo;
    nstd::daftar<Token> tokens;
    std::runtime_error error(const std::string& msg);
    nstd::dinamis fragmentMultiOperasiLeftRight(
        const nstd::daftar<std::unique_ptr<Context>>& kumpulanContext,
        const nstd::daftar<Token>& kumpulanOperator
    );
    nstd::dinamis fragmentOperasiPrePost(
        const std::unique_ptr<Context>& context,
        const nstd::bisa_kosong<Token>& satuOperator, const bool& isPre,
        const bool& isPost
    );
};
