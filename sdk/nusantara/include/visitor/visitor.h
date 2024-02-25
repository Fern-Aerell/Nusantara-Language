#pragma once

#include <memory>
#include <stdexcept>

#include "parser/parser_rule.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"
#include "visitor/context/ekspresi/ekspresi_context.h"
#include "visitor/context/nilai/nilai_context.h"
#include "visitor/context/nilai/nilai_kalimat_context.h"
#include "visitor/context/nusantara/nusantara_context.h"
#include "visitor/context/operasi/operasi_and_bit_context.h"
#include "visitor/context/operasi/operasi_and_bit_sama_dengan_context.h"
#include "visitor/context/operasi/operasi_atau_context.h"
#include "visitor/context/operasi/operasi_bagi_sama_dengan_context.h"
#include "visitor/context/operasi/operasi_dan_context.h"
#include "visitor/context/operasi/operasi_geser_kanan_bit_context.h"
#include "visitor/context/operasi/operasi_geser_kanan_bit_sama_dengan_context.h"
#include "visitor/context/operasi/operasi_geser_kiri_bit_context.h"
#include "visitor/context/operasi/operasi_geser_kiri_bit_sama_dengan_context.h"
#include "visitor/context/operasi/operasi_kali_sama_dengan_context.h"
#include "visitor/context/operasi/operasi_kondisional_context.h"
#include "visitor/context/operasi/operasi_kurang_context.h"
#include "visitor/context/operasi/operasi_kurang_sama_dengan_context.h"
#include "visitor/context/operasi/operasi_kurang_satu_context.h"
#include "visitor/context/operasi/operasi_lebih_besar_context.h"
#include "visitor/context/operasi/operasi_lebih_besar_sama_dengan_context.h"
#include "visitor/context/operasi/operasi_lebih_kecil_context.h"
#include "visitor/context/operasi/operasi_lebih_kecil_sama_dengan_context.h"
#include "visitor/context/operasi/operasi_not_bit_context.h"
#include "visitor/context/operasi/operasi_or_bit_context.h"
#include "visitor/context/operasi/operasi_or_bit_sama_dengan_context.h"
#include "visitor/context/operasi/operasi_pembagian_context.h"
#include "visitor/context/operasi/operasi_perkalian_context.h"
#include "visitor/context/operasi/operasi_sama_context.h"
#include "visitor/context/operasi/operasi_sama_dengan_context.h"
#include "visitor/context/operasi/operasi_sisa_bagi_sama_dengan_context.h"
#include "visitor/context/operasi/operasi_sisa_pembagian.h"
#include "visitor/context/operasi/operasi_tambah_context.h"
#include "visitor/context/operasi/operasi_tambah_sama_dengan_context.h"
#include "visitor/context/operasi/operasi_tambah_satu_context.h"
#include "visitor/context/operasi/operasi_tidak_context.h"
#include "visitor/context/operasi/operasi_tidak_sama_context.h"
#include "visitor/context/operasi/operasi_xor_bit_context.h"
#include "visitor/context/operasi/operasi_xor_bit_sama_dengan_context.h"
#include "visitor/context/pernyataan/pernyataan_context.h"
#include "visitor/context/variable/variable_context.h"

template<typename T>
class Visitor {
  public:
    Visitor() = default;  // constructor
    virtual ~Visitor() =
        default;  // destructor (virtual if X is meant to be a base class)
    Visitor(const Visitor&) = default;                 // copy constructor
    Visitor& operator=(const Visitor&) = default;      // copy assignment
    Visitor(Visitor&&) noexcept = default;             // move constructor
    Visitor& operator=(Visitor&&) noexcept = default;  // move assignment

    T visit(const std::unique_ptr<Context>& ctx) {
      if(const auto* nctx = dynamic_cast<NusantaraContext*>(ctx.get())) {
        return this->visitNusantara(*nctx);
      }
      if(const auto* ectx = dynamic_cast<EkspresiContext*>(ctx.get())) {
        return this->visitEkspresi(*ectx);
      }
      if(const auto* pctx = dynamic_cast<PernyataanContext*>(ctx.get())) {
        return this->visitPernyataan(*pctx);
      }
      if(const auto* vctx = dynamic_cast<VariableContext*>(ctx.get())) {
        return this->visitVariable(*vctx);
      }
      if(const auto* ogkananbsdctx =
             dynamic_cast<OperasiGeserKananBitSamaDenganContext*>(ctx.get())) {
        return this->visitOperasiGeserKananBitSamaDengan(*ogkananbsdctx);
      }
      if(const auto* ogkiribsdctx =
             dynamic_cast<OperasiGeserKiriBitSamaDenganContext*>(ctx.get())) {
        return this->visitOperasiGeserKiriBitSamaDengan(*ogkiribsdctx);
      }
      if(const auto* oxbsdctx =
             dynamic_cast<OperasiXorBitSamaDenganContext*>(ctx.get())) {
        return this->visitOperasiXorBitSamaDengan(*oxbsdctx);
      }
      if(const auto* oobsdctx =
             dynamic_cast<OperasiOrBitSamaDenganContext*>(ctx.get())) {
        return this->visitOperasiOrBitSamaDengan(*oobsdctx);
      }
      if(const auto* oabsdctx =
             dynamic_cast<OperasiAndBitSamaDenganContext*>(ctx.get())) {
        return this->visitOperasiAndBitSamaDengan(*oabsdctx);
      }
      if(const auto* oksdctx =
             dynamic_cast<OperasiKurangSamaDenganContext*>(ctx.get())) {
        return this->visitOperasiKurangSamaDengan(*oksdctx);
      }
      if(const auto* otsdctx =
             dynamic_cast<OperasiTambahSamaDenganContext*>(ctx.get())) {
        return this->visitOperasiTambahSamaDengan(*otsdctx);
      }
      if(const auto* osbsdctx =
             dynamic_cast<OperasiSisaBagiSamaDenganContext*>(ctx.get())) {
        return this->visitOperasiSisaBagiSamaDengan(*osbsdctx);
      }
      if(const auto* obsdctx =
             dynamic_cast<OperasiBagiSamaDenganContext*>(ctx.get())) {
        return this->visitOperasiBagiSamaDengan(*obsdctx);
      }
      if(const auto* oksdctx =
             dynamic_cast<OperasiKaliSamaDenganContext*>(ctx.get())) {
        return this->visitOperasiKaliSamaDengan(*oksdctx);
      }
      if(const auto* osdctx =
             dynamic_cast<OperasiSamaDenganContext*>(ctx.get())) {
        return this->visitOperasiSamaDengan(*osdctx);
      }
      if(const auto* okctx =
             dynamic_cast<OperasiKondisionalContext*>(ctx.get())) {
        return this->visitOperasiKondisional(*okctx);
      }
      if(const auto* oactx = dynamic_cast<OperasiAtauContext*>(ctx.get())) {
        return this->visitOperasiAtau(*oactx);
      }
      if(const auto* odctx = dynamic_cast<OperasiDanContext*>(ctx.get())) {
        return this->visitOperasiDan(*odctx);
      }
      if(const auto* oobtcx = dynamic_cast<OperasiOrBitContext*>(ctx.get())) {
        return this->visitOperasiOrBit(*oobtcx);
      }
      if(const auto* oxbtcx = dynamic_cast<OperasiXorBitContext*>(ctx.get())) {
        return this->visitOperasiXorBit(*oxbtcx);
      }
      if(const auto* oabctx = dynamic_cast<OperasiAndBitContext*>(ctx.get())) {
        return this->visitOperasiAndBit(*oabctx);
      }
      if(const auto* otsctx =
             dynamic_cast<OperasiTidakSamaContext*>(ctx.get())) {
        return this->visitOperasiTidakSama(*otsctx);
      }
      if(const auto* osctx = dynamic_cast<OperasiSamaContext*>(ctx.get())) {
        return this->visitOperasiSama(*osctx);
      }
      if(const auto* olbsdctx =
             dynamic_cast<OperasiLebihBesarSamaDenganContext*>(ctx.get())) {
        return this->visitOperasiLebihBesarSamaDengan(*olbsdctx);
      }
      if(const auto* olbctx =
             dynamic_cast<OperasiLebihBesarContext*>(ctx.get())) {
        return this->visitOperasiLebihBesar(*olbctx);
      }
      if(const auto* olksdctx =
             dynamic_cast<OperasiLebihKecilSamaDenganContext*>(ctx.get())) {
        return this->visitOperasiLebihKecilSamaDengan(*olksdctx);
      }
      if(const auto* olkctx =
             dynamic_cast<OperasiLebihKecilContext*>(ctx.get())) {
        return this->visitOperasiLebihKecil(*olkctx);
      }
      if(const auto* ogkananbctx =
             dynamic_cast<OperasiGeserKananBitContext*>(ctx.get())) {
        return this->visitOperasiGeserKananBit(*ogkananbctx);
      }
      if(const auto* ogkiribctx =
             dynamic_cast<OperasiGeserKiriBitContext*>(ctx.get())) {
        return this->visitOperasiGeserKiriBit(*ogkiribctx);
      }
      if(const auto* okctx = dynamic_cast<OperasiKurangContext*>(ctx.get())) {
        return this->visitOperasiKurang(*okctx);
      }
      if(const auto* otctx = dynamic_cast<OperasiTambahContext*>(ctx.get())) {
        return this->visitOperasiTambah(*otctx);
      }
      if(const auto* ospctx =
             dynamic_cast<OperasiSisaPembagianContext*>(ctx.get())) {
        return this->visitOperasiSisaPembagian(*ospctx);
      }
      if(const auto* opctx =
             dynamic_cast<OperasiPembagianContext*>(ctx.get())) {
        return this->visitOperasiPembagian(*opctx);
      }
      if(const auto* opklianctx =
             dynamic_cast<OperasiPerkalianContext*>(ctx.get())) {
        return this->visitOperasiPerkalian(*opklianctx);
      }
      if(const auto* otdkctx = dynamic_cast<OperasiTidakContext*>(ctx.get())) {
        return this->visitOperasiTidak(*otdkctx);
      }
      if(const auto* onbctx = dynamic_cast<OperasiNotBitContext*>(ctx.get())) {
        return this->visitOperasiNotBit(*onbctx);
      }
      if(const auto* oksctx =
             dynamic_cast<OperasiKurangSatuContext*>(ctx.get())) {
        return this->visitOperasiKurangSatu(*oksctx);
      }
      if(const auto* otsctx =
             dynamic_cast<OperasiTambahSatuContext*>(ctx.get())) {
        return this->visitOperasiTambahSatu(*otsctx);
      }
      if(const auto* nilaictx = dynamic_cast<NilaiContext*>(ctx.get())) {
        return this->visitNilai(*nilaictx);
      }
      if(const auto* nklmtctx = dynamic_cast<NilaiKalimatContext*>(ctx.get())) {
        return this->visitNilaiKalimat(*nklmtctx);
      }
      throw std::runtime_error("Context tidak dapat di cast.");
    }

    T visit(const std::unique_ptr<ParserTree>& tree) {
      if(auto* rule = dynamic_cast<ParserRuleTree*>(tree.get())) {
        switch(rule->getRule()) {
          case ParserRule::nusantara:
            return this->visitNusantara(
                NusantaraContext::generate(rule->getChildren())
            );
          case ParserRule::ekspresi:
            return this->visitEkspresi(
                EkspresiContext::generate(rule->getChildren())
            );
          case ParserRule::pernyataan:
            return this->visitPernyataan(
                PernyataanContext::generate(rule->getChildren())
            );
          case ParserRule::variable:
            return this->visitVariable(
                VariableContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_geser_kanan_bit_sama_dengan:
            return this->visitOperasiGeserKananBitSamaDengan(
                OperasiGeserKananBitSamaDenganContext::generate(
                    rule->getChildren()
                )
            );
          case ParserRule::operasi_geser_kiri_bit_sama_dengan:
            return this->visitOperasiGeserKiriBitSamaDengan(
                OperasiGeserKiriBitSamaDenganContext::generate(
                    rule->getChildren()
                )
            );
          case ParserRule::operasi_xor_bit_sama_dengan:
            return this->visitOperasiXorBitSamaDengan(
                OperasiXorBitSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_or_bit_sama_dengan:
            return this->visitOperasiOrBitSamaDengan(
                OperasiOrBitSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_and_bit_sama_dengan:
            return this->visitOperasiAndBitSamaDengan(
                OperasiAndBitSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_kurang_sama_dengan:
            return this->visitOperasiKurangSamaDengan(
                OperasiKurangSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_tambah_sama_dengan:
            return this->visitOperasiTambahSamaDengan(
                OperasiTambahSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_sisa_bagi_sama_dengan:
            return this->visitOperasiSisaBagiSamaDengan(
                OperasiSisaBagiSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_bagi_sama_dengan:
            return this->visitOperasiBagiSamaDengan(
                OperasiBagiSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_kali_sama_dengan:
            return this->visitOperasiKaliSamaDengan(
                OperasiKaliSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_sama_dengan:
            return this->visitOperasiSamaDengan(
                OperasiSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_kondisional:
            return this->visitOperasiKondisional(
                OperasiKondisionalContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_atau:
            return this->visitOperasiAtau(
                OperasiAtauContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_dan:
            return this->visitOperasiDan(
                OperasiDanContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_or_bit:
            return this->visitOperasiOrBit(
                OperasiOrBitContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_xor_bit:
            return this->visitOperasiXorBit(
                OperasiXorBitContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_and_bit:
            return this->visitOperasiAndBit(
                OperasiAndBitContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_tidak_sama:
            return this->visitOperasiTidakSama(
                OperasiTidakSamaContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_sama:
            return this->visitOperasiSama(
                OperasiSamaContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_lebih_besar_sama_dengan:
            return this->visitOperasiLebihBesarSamaDengan(
                OperasiLebihBesarSamaDenganContext::generate(rule->getChildren()
                )
            );
          case ParserRule::operasi_lebih_besar:
            return this->visitOperasiLebihBesar(
                OperasiLebihBesarContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_lebih_kecil_sama_dengan:
            return this->visitOperasiLebihKecilSamaDengan(
                OperasiLebihKecilSamaDenganContext::generate(rule->getChildren()
                )
            );
          case ParserRule::operasi_lebih_kecil:
            return this->visitOperasiLebihKecil(
                OperasiLebihKecilContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_geser_kanan_bit:
            return this->visitOperasiGeserKananBit(
                OperasiGeserKananBitContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_geser_kiri_bit:
            return this->visitOperasiGeserKiriBit(
                OperasiGeserKiriBitContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_kurang:
            return this->visitOperasiKurang(
                OperasiKurangContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_tambah:
            return this->visitOperasiTambah(
                OperasiTambahContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_sisa_pembagian:
            return this->visitOperasiSisaPembagian(
                OperasiSisaPembagianContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_pembagian:
            return this->visitOperasiPembagian(
                OperasiPembagianContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_perkalian:
            return this->visitOperasiPerkalian(
                OperasiPerkalianContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_tidak:
            return this->visitOperasiTidak(
                OperasiTidakContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_not_bit:
            return this->visitOperasiNotBit(
                OperasiNotBitContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_kurang_satu:
            return this->visitOperasiKurangSatu(
                OperasiKurangSatuContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_tambah_satu:
            return this->visitOperasiTambahSatu(
                OperasiTambahSatuContext::generate(rule->getChildren())
            );
          case ParserRule::nilai:
            return this->visitNilai(NilaiContext::generate(rule->getChildren())
            );
          case ParserRule::nilai_kalimat:
            return this->visitNilaiKalimat(
                NilaiKalimatContext::generate(rule->getChildren())
            );
        }
      }
      throw std::runtime_error("Aturan tidak valid.");
    }

    virtual T visitNusantara(const NusantaraContext& ctx) = 0;
    virtual T visitEkspresi(const EkspresiContext& ctx) = 0;
    virtual T visitPernyataan(const PernyataanContext& ctx) = 0;
    virtual T visitVariable(const VariableContext& ctx) = 0;
    virtual T visitOperasiGeserKananBitSamaDengan(
        const OperasiGeserKananBitSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiGeserKiriBitSamaDengan(
        const OperasiGeserKiriBitSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiXorBitSamaDengan(
        const OperasiXorBitSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiOrBitSamaDengan(
        const OperasiOrBitSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiAndBitSamaDengan(
        const OperasiAndBitSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiKurangSamaDengan(
        const OperasiKurangSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiTambahSamaDengan(
        const OperasiTambahSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiSisaBagiSamaDengan(
        const OperasiSisaBagiSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiBagiSamaDengan(const OperasiBagiSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiKaliSamaDengan(const OperasiKaliSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiSamaDengan(const OperasiSamaDenganContext& ctx) = 0;
    virtual T visitOperasiKondisional(const OperasiKondisionalContext& ctx) = 0;
    virtual T visitOperasiAtau(const OperasiAtauContext& ctx) = 0;
    virtual T visitOperasiDan(const OperasiDanContext& ctx) = 0;
    virtual T visitOperasiOrBit(const OperasiOrBitContext& ctx) = 0;
    virtual T visitOperasiXorBit(const OperasiXorBitContext& ctx) = 0;
    virtual T visitOperasiAndBit(const OperasiAndBitContext& ctx) = 0;
    virtual T visitOperasiTidakSama(const OperasiTidakSamaContext& ctx) = 0;
    virtual T visitOperasiSama(const OperasiSamaContext& ctx) = 0;
    virtual T visitOperasiLebihBesarSamaDengan(
        const OperasiLebihBesarSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiLebihBesar(const OperasiLebihBesarContext& ctx) = 0;
    virtual T visitOperasiLebihKecilSamaDengan(
        const OperasiLebihKecilSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiLebihKecil(const OperasiLebihKecilContext& ctx) = 0;
    virtual T visitOperasiGeserKananBit(const OperasiGeserKananBitContext& ctx
    ) = 0;
    virtual T visitOperasiGeserKiriBit(const OperasiGeserKiriBitContext& ctx
    ) = 0;
    virtual T visitOperasiKurang(const OperasiKurangContext& ctx) = 0;
    virtual T visitOperasiTambah(const OperasiTambahContext& ctx) = 0;
    virtual T visitOperasiSisaPembagian(const OperasiSisaPembagianContext& ctx
    ) = 0;
    virtual T visitOperasiPembagian(const OperasiPembagianContext& ctx) = 0;
    virtual T visitOperasiPerkalian(const OperasiPerkalianContext& ctx) = 0;
    virtual T visitOperasiTidak(const OperasiTidakContext& ctx) = 0;
    virtual T visitOperasiNotBit(const OperasiNotBitContext& ctx) = 0;
    virtual T visitOperasiKurangSatu(const OperasiKurangSatuContext& ctx) = 0;
    virtual T visitOperasiTambahSatu(const OperasiTambahSatuContext& ctx) = 0;
    virtual T visitNilai(const NilaiContext& ctx) = 0;
    virtual T visitNilaiKalimat(const NilaiKalimatContext& ctx) = 0;

  private:
};
