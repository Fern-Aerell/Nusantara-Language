#pragma once

#include "nusantara/core/error_info.h"
#include "nstd/dinamis.h"
#include "nusantara/visitor/context/operasi_logika_tidak_context.h"
#include "nusantara/visitor/context/operator_logika_tidak_context.h"
#include "nusantara/visitor/visitor.h"

class Interpreter: public Visitor<nstd::dinamis> {
  public:
    explicit Interpreter(ErrorInfo errorInfo);

    nstd::dinamis visitNusantara(const NusantaraContext& ctx) override;
    nstd::dinamis visitOperatorPenugasan(
        const OperatorPenugasanContext& ctx
    ) override;
    nstd::dinamis visitOperasiPenugasan(
        const OperasiPenugasanContext& ctx
    ) override;
    nstd::dinamis visitOperatorPenugasanPenjumlahan(
        const OperatorPenugasanPenjumlahanContext& ctx
    ) override;
    nstd::dinamis visitOperasiPenugasanPenjumlahan(
        const OperasiPenugasanPenjumlahanContext& ctx
    ) override;
    nstd::dinamis visitOperatorPenugasanPerkalian(
        const OperatorPenugasanPerkalianContext& ctx
    ) override;
    nstd::dinamis visitOperasiPenugasanPerkalian(
        const OperasiPenugasanPerkalianContext& ctx
    ) override;
    nstd::dinamis visitOperatorLogika(const OperatorLogikaContext& ctx
    ) override;
    nstd::dinamis visitOperasiLogika(const OperasiLogikaContext &ctx
    ) override;
    nstd::dinamis visitOperatorLogikaTidak(
        const OperatorLogikaTidakContext &ctx
    ) override;
    nstd::dinamis visitOperasiLogikaTidak(
        const OperasiLogikaTidakContext &ctx
    ) override;
    nstd::dinamis visitOperatorPerbandingan(
        const OperatorPerbandinganContext &ctx
    ) override;
    nstd::dinamis visitOperasiPerbandingan(
        const OperasiPerbandinganContext &ctx
    ) override;
    nstd::dinamis visitOperatorPrePost(const OperatorPrePostContext &ctx
    ) override;
    nstd::dinamis visitOperasiPrePost(const OperasiPrePostContext &ctx
    ) override;
    nstd::dinamis visitOperatorPenjumlahan(
        const OperatorPenjumlahanContext &ctx
    ) override;
    nstd::dinamis visitOperasiPenjumlahan(
        const OperasiPenjumlahanContext &ctx
    ) override;
    nstd::dinamis visitOperatorPerkalian(
        const OperatorPerkalianContext &ctx
    ) override;
    nstd::dinamis visitOperasiPerkalian(
        const OperasiPerkalianContext &ctx
    ) override;
    nstd::dinamis visitNilai(const NilaiContext &ctx) override;

  private:
    ErrorInfo errorInfo;
    nstd::daftar<Token> tokens;

    nstd::dinamis fragmentVisitOperator(
        const nstd::bisa_kosong<Token> &simbolOp,
        const std::string &opName
    );

    nstd::dinamis operasiAritmatika(
        const nstd::dinamis &left, const std::string &simbolOp,
        const nstd::dinamis &right
    );
    nstd::dinamis operasiPenjumlahan(
        const nstd::dinamis &left, const nstd::dinamis &right
    );
    nstd::dinamis operasiPengurangan(
        const nstd::dinamis &left, const nstd::dinamis &right
    );
    nstd::dinamis operasiPerkalian(
        const nstd::dinamis &left, const nstd::dinamis &right
    );
    nstd::dinamis operasiPembagian(
        const nstd::dinamis &left, const nstd::dinamis &right
    );
    nstd::dinamis operasiSisaPembagian(
        const nstd::dinamis &left, const nstd::dinamis &right
    );

    nstd::dinamis operasiPerbandingan(
        const nstd::dinamis &left, const std::string &simbolOp,
        const nstd::dinamis &right
    );
    nstd::dinamis operasiSama(
        const nstd::dinamis &left, const nstd::dinamis &right
    );
    nstd::dinamis operasiTidakSama(
        const nstd::dinamis &left, const nstd::dinamis &right
    );
    nstd::dinamis operasiLebihBesar(
        const nstd::dinamis &left, const nstd::dinamis &right
    );
    nstd::dinamis operasiLebihKecil(
        const nstd::dinamis &left, const nstd::dinamis &right
    );
    nstd::dinamis operasiLebihBesarSamaDengan(
        const nstd::dinamis &left, const nstd::dinamis &right
    );
    nstd::dinamis operasiLebihKecilSamaDengan(
        const nstd::dinamis &left, const nstd::dinamis &right
    );
};
