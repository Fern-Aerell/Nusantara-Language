#pragma once

#include "nusantara/core/core.h"
#include "nusantara/core/error_info.h"
#include "nusantara/lexer/token.h"
#include "nusantara/visitor/visitor.h"

class Interpreter: public Visitor<nstd::dinamis> {
  public:
    explicit Interpreter(ErrorInfo errorInfo);

    nstd::dinamis visitNusantara(nstd::konst<NusantaraContext> &ctx) override;
    nstd::dinamis visitOperatorPenugasan(
        nstd::konst<OperatorPenugasanContext> &ctx
    ) override;
    nstd::dinamis visitOperasiPenugasan(
        nstd::konst<OperasiPenugasanContext> &ctx
    ) override;
    nstd::dinamis visitOperatorPenugasanPenjumlahan(
        nstd::konst<OperatorPenugasanPenjumlahanContext> &ctx
    ) override;
    nstd::dinamis visitOperasiPenugasanPenjumlahan(
        nstd::konst<OperasiPenugasanPenjumlahanContext> &ctx
    ) override;
    nstd::dinamis visitOperatorPenugasanPerkalian(
        nstd::konst<OperatorPenugasanPerkalianContext> &ctx
    ) override;
    nstd::dinamis visitOperasiPenugasanPerkalian(
        nstd::konst<OperasiPenugasanPerkalianContext> &ctx
    ) override;
    nstd::dinamis visitOperatorLogika(nstd::konst<OperatorLogikaContext> &ctx
    ) override;
    nstd::dinamis visitOperasiLogika(nstd::konst<OperasiLogikaContext> &ctx
    ) override;
    nstd::dinamis visitOperatorPerbandingan(
        nstd::konst<OperatorPerbandinganContext> &ctx
    ) override;
    nstd::dinamis visitOperasiPerbandingan(
        nstd::konst<OperasiPerbandinganContext> &ctx
    ) override;
    nstd::dinamis visitOperatorPrePost(nstd::konst<OperatorPrePostContext> &ctx
    ) override;
    nstd::dinamis visitOperasiPrePost(nstd::konst<OperasiPrePostContext> &ctx
    ) override;
    nstd::dinamis visitOperatorPenjumlahan(
        nstd::konst<OperatorPenjumlahanContext> &ctx
    ) override;
    nstd::dinamis visitOperasiPenjumlahan(
        nstd::konst<OperasiPenjumlahanContext> &ctx
    ) override;
    nstd::dinamis visitOperatorPerkalian(
        nstd::konst<OperatorPerkalianContext> &ctx
    ) override;
    nstd::dinamis visitOperasiPerkalian(
        nstd::konst<OperasiPerkalianContext> &ctx
    ) override;
    nstd::dinamis visitNilai(nstd::konst<NilaiContext> &ctx) override;

  private:
    ErrorInfo errorInfo;
    nstd::daftar<Token> tokens;

    nstd::dinamis fragmentVisitOperator(
        nstd::konst<nstd::bisa_kosong<Token>> &simbolOp,
        nstd::konst<nstd::kalimat> &opName
    );

    nstd::dinamis operasiAritmatika(
        nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::kalimat> &simbolOp,
        nstd::konst<nstd::dinamis> &right
    );
    nstd::dinamis operasiPenjumlahan(
        nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::dinamis> &right
    );
    nstd::dinamis operasiPengurangan(
        nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::dinamis> &right
    );
    nstd::dinamis operasiPerkalian(
        nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::dinamis> &right
    );
    nstd::dinamis operasiPembagian(
        nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::dinamis> &right
    );
    nstd::dinamis operasiSisaPembagian(
        nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::dinamis> &right
    );

    nstd::dinamis operasiPerbandingan(
        nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::kalimat> &simbolOp,
        nstd::konst<nstd::dinamis> &right
    );
    nstd::dinamis operasiSama(
        nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::dinamis> &right
    );
    nstd::dinamis operasiTidakSama(
        nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::dinamis> &right
    );
    nstd::dinamis operasiLebihBesar(
        nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::dinamis> &right
    );
    nstd::dinamis operasiLebihKecil(
        nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::dinamis> &right
    );
    nstd::dinamis operasiLebihBesarSamaDengan(
        nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::dinamis> &right
    );
    nstd::dinamis operasiLebihKecilSamaDengan(
        nstd::konst<nstd::dinamis> &left, nstd::konst<nstd::dinamis> &right
    );
};
