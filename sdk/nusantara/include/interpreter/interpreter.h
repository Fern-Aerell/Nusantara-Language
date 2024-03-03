#pragma once

#include <memory>
#include <optional>
#include <vector>

#include "core/core.h"
#include "core/pointer.h"
#include "error/error_info.h"
#include "lexer/token.h"
#include "nstd/manager/variable_manager.h"
#include "nstd/tipe_data/dinamis.h"
#include "visitor/context/context.h"
#include "visitor/context/operasi/operasi_kondisional_context.h"
#include "visitor/context/pernyataan/pernyataan_context.h"
#include "visitor/context/variable/variable_context.h"
#include "visitor/visitor.h"

class Interpreter: public Visitor<NSTD dinamis> {
  public:
    explicit Interpreter(ErrorInfo errorInfo);
    NSTD dinamis visitNusantara(const NusantaraContext& ctx) override;
    NSTD dinamis visitEkspresi(const EkspresiContext& ctx) override;
    NSTD dinamis visitPernyataan(const PernyataanContext& ctx) override;
    NSTD dinamis visitVariable(const VariableContext& ctx) override;
    NSTD dinamis visitOperasiGeserKananBitSamaDengan(
        const OperasiGeserKananBitSamaDenganContext& ctx
    ) override;
    NSTD dinamis visitOperasiGeserKiriBitSamaDengan(
        const OperasiGeserKiriBitSamaDenganContext& ctx
    ) override;
    NSTD dinamis visitOperasiXorBitSamaDengan(
        const OperasiXorBitSamaDenganContext& ctx
    ) override;
    NSTD dinamis visitOperasiOrBitSamaDengan(
        const OperasiOrBitSamaDenganContext& ctx
    ) override;
    NSTD dinamis visitOperasiAndBitSamaDengan(
        const OperasiAndBitSamaDenganContext& ctx
    ) override;
    NSTD dinamis visitOperasiKurangSamaDengan(
        const OperasiKurangSamaDenganContext& ctx
    ) override;
    NSTD dinamis visitOperasiTambahSamaDengan(
        const OperasiTambahSamaDenganContext& ctx
    ) override;
    NSTD dinamis visitOperasiSisaBagiSamaDengan(
        const OperasiSisaBagiSamaDenganContext& ctx
    ) override;
    NSTD dinamis visitOperasiBagiSamaDengan(
        const OperasiBagiSamaDenganContext& ctx
    ) override;
    NSTD dinamis visitOperasiKaliSamaDengan(
        const OperasiKaliSamaDenganContext& ctx
    ) override;
    NSTD dinamis visitOperasiSamaDengan(const OperasiSamaDenganContext& ctx
    ) override;
    NSTD dinamis visitOperasiKondisional(const OperasiKondisionalContext& ctx
    ) override;
    NSTD dinamis visitOperasiAtau(const OperasiAtauContext& ctx) override;
    NSTD dinamis visitOperasiDan(const OperasiDanContext& ctx) override;
    NSTD dinamis visitOperasiOrBit(const OperasiOrBitContext& ctx) override;
    NSTD dinamis visitOperasiXorBit(const OperasiXorBitContext& ctx) override;
    NSTD dinamis visitOperasiAndBit(const OperasiAndBitContext& ctx) override;
    NSTD dinamis visitOperasiTidakSama(const OperasiTidakSamaContext& ctx
    ) override;
    NSTD dinamis visitOperasiSama(const OperasiSamaContext& ctx) override;
    NSTD dinamis visitOperasiLebihBesarSamaDengan(
        const OperasiLebihBesarSamaDenganContext& ctx
    ) override;
    NSTD dinamis visitOperasiLebihBesar(const OperasiLebihBesarContext& ctx
    ) override;
    NSTD dinamis visitOperasiLebihKecilSamaDengan(
        const OperasiLebihKecilSamaDenganContext& ctx
    ) override;
    NSTD dinamis visitOperasiLebihKecil(const OperasiLebihKecilContext& ctx
    ) override;
    NSTD dinamis visitOperasiGeserKananBit(
        const OperasiGeserKananBitContext& ctx
    ) override;
    NSTD dinamis visitOperasiGeserKiriBit(const OperasiGeserKiriBitContext& ctx
    ) override;
    NSTD dinamis visitOperasiKurang(const OperasiKurangContext& ctx) override;
    NSTD dinamis visitOperasiTambah(const OperasiTambahContext& ctx) override;
    NSTD dinamis visitOperasiSisaPembagian(
        const OperasiSisaPembagianContext& ctx
    ) override;
    NSTD dinamis visitOperasiPembagian(const OperasiPembagianContext& ctx
    ) override;
    NSTD dinamis visitOperasiPerkalian(const OperasiPerkalianContext& ctx
    ) override;
    NSTD dinamis visitOperasiTidak(const OperasiTidakContext& ctx) override;
    NSTD dinamis visitOperasiNotBit(const OperasiNotBitContext& ctx) override;
    NSTD dinamis visitOperasiKurangSatu(const OperasiKurangSatuContext& ctx
    ) override;
    NSTD dinamis visitOperasiTambahSatu(const OperasiTambahSatuContext& ctx
    ) override;
    NSTD dinamis visitNilai(const NilaiContext& ctx) override;
    NSTD dinamis visitNilaiKalimat(const NilaiKalimatContext& ctx) override;

  private:
    ErrorInfo errorInfo;
    STD vector<Token> tokens;
    SPTR(NSTD variable_manager) variables;
    STD runtime_error error(const STD string& msg);
    NSTD dinamis fragmentMultiOperasiLeftRight(
        const STD vector<STD unique_ptr<Context>>& kumpulanContext,
        const STD vector<Token>& kumpulanOperator
    );
    NSTD dinamis fragmentMultiOperasiRightLeft(
        const STD vector<STD unique_ptr<Context>>& kumpulanContext,
        const STD vector<Token>& kumpulanOperator
    );
    NSTD dinamis fragmentOperasiPrePost(
        const STD unique_ptr<Context>& context,
        const STD optional<Token>& satuOperator, const bool& isPre,
        const bool& isPost
    );
};
