#include "nusantara/core/core.h"
#include "nusantara/lexer/token.h"
#include "nusantara/visitor/context/context.h"
#include "nusantara/visitor/context/nilai_context.h"
#include "nusantara/visitor/context/operasi_penugasan_context.h"
#include "nusantara/visitor/context/operasi_penugasan_penjumlahan_context.h"
#include "nusantara/visitor/context/operator_perkalian_context.h"
#include <cstddef>
#include <iostream>
#include <memory>
#include <nusantara/visitor/visitor_dinamis.h>
#include <stdexcept>
#include <string>

nstd::dinamis VisitorDinamis::visitNusantara(nstd::konst<NusantaraContext>& ctx) {
    std::cout << "VisitNusantara" << "\n";
    const auto& context = ctx.getKumpulanOperasiPenugasanContext();
    if(!nstd::isKosong(context)) {
        for(nstd::konst<std::unique_ptr<Context>>& contextChild : context.value()) {
            auto* operasiPenugasanContext = dynamic_cast<OperasiPenugasanContext*>(contextChild.get());
            nstd::dinamis nilai = this->visitOperasiPenugasan(*operasiPenugasanContext);
            if(nstd::isBulat(nilai)) {
                std::cout << "Hasil : " << nstd::asBulat(nilai);
            }else if(nstd::isDesimal(nilai)) {
                std::cout << "Hasil : " << nstd::asDesimal(nilai);
            }else if(nstd::isKarakter(nilai)) {
                std::cout << "Hasil : " << nstd::asKarakter(nilai);
            }else if(nstd::isKalimat(nilai)) {
                std::cout << "Hasil : " << nstd::asKalimat(nilai);
            }else if(nstd::isBenarSalah(nilai)) {
                std::cout << "Hasil : " << nstd::asBenarSalah(nilai);
            }else{
                throw std::runtime_error("Hasil Tidak Valid");
            }
        }
    }
    return {};
}

nstd::dinamis VisitorDinamis::visitOperatorPenugasan(nstd::konst<OperatorPenugasanContext>& ctx) {
    std::cout << "visitOperatorPenugasan" << "\n";
    nstd::konst<nstd::bisa_kosong<Token>>& token = ctx.getSimbolOp();
    if(!nstd::isKosong(token)) {
        nstd::konst<Token>& tokenValue = token.value();
        return tokenValue.getValue();
    }
    throw std::runtime_error("Operator Penugasan Tidak Valid");
}

nstd::dinamis VisitorDinamis::visitOperasiPenugasan(nstd::konst<OperasiPenugasanContext>& ctx) {
    std::cout << "visitOperasiPenugasan" << "\n";
    const auto& nilaiContexts = ctx.getKumpulanOperasiPenugasanPenjumlahanContext();
    const auto& operatorContexts = ctx.getKumpulanOperatorPenugasanContext();
    if(nstd::isKosong(nilaiContexts)) {
        throw std::runtime_error("Nilai tidak boleh kosong.");
    }
    auto* nilaiContextLeft = dynamic_cast<NilaiContext*>(nilaiContexts->front().get());
    nstd::dinamis left = this->visitNilai(*nilaiContextLeft);
    if(!nstd::isKosong(operatorContexts)) {
        if(!operatorContexts->empty()) {
            for(size_t index = 0; index < operatorContexts->size(); ++index) {
                auto* operatorPerkalianContext = dynamic_cast<OperatorPerkalianContext*>(operatorContexts.value()[index].get());
                nstd::kalimat simbolOp = nstd::asKalimat(this->visitOperatorPerkalian(*operatorPerkalianContext));
                auto* nilaiContextRight = dynamic_cast<NilaiContext*>(nilaiContexts.value()[index + 1].get());
                nstd::dinamis right = this->visitNilai(*nilaiContextRight);
                throw std::runtime_error("Operasi belum dapat di lakukan");
            }
        }
    }
    return left;
}

nstd::dinamis VisitorDinamis::visitOperatorPenugasanPenjumlahan(nstd::konst<OperatorPenugasanPenjumlahanContext>& ctx) {
    std::cout << "visitOperatorPenugasanPenjumlahan" << "\n";
    nstd::konst<nstd::bisa_kosong<Token>>& token = ctx.getSimbolOp();
    if(!nstd::isKosong(token)) {
        nstd::konst<Token>& tokenValue = token.value();
        return tokenValue.getValue();
    }
    throw std::runtime_error("Operator Penugasan Penjumlahan Tidak Valid");
}

nstd::dinamis VisitorDinamis::visitOperasiPenugasanPenjumlahan(nstd::konst<OperasiPenugasanPenjumlahanContext>& ctx) {
    std::cout << "visitOperasiPenugasanPenjumlahan" << "\n";
    const auto& nilaiContexts = ctx.getKumpulanOperasiPenugasanPerkalianContext();
    const auto& operatorContexts = ctx.getKumpulanOperatorPenugasanPenjumlahanContext();
    if(nstd::isKosong(nilaiContexts)) {
        throw std::runtime_error("Nilai tidak boleh kosong.");
    }
    auto* nilaiContextLeft = dynamic_cast<NilaiContext*>(nilaiContexts->front().get());
    nstd::dinamis left = this->visitNilai(*nilaiContextLeft);
    if(!nstd::isKosong(operatorContexts)) {
        if(!operatorContexts->empty()) {
            for(size_t index = 0; index < operatorContexts->size(); ++index) {
                auto* operatorPerkalianContext = dynamic_cast<OperatorPerkalianContext*>(operatorContexts.value()[index].get());
                nstd::kalimat simbolOp = nstd::asKalimat(this->visitOperatorPerkalian(*operatorPerkalianContext));
                auto* nilaiContextRight = dynamic_cast<NilaiContext*>(nilaiContexts.value()[index + 1].get());
                nstd::dinamis right = this->visitNilai(*nilaiContextRight);
                if(simbolOp == "+=") {
                    if(nstd::isBulat(left) && nstd::isBulat(right)) {
                        left = nstd::asBulat(left) + nstd::asBulat(right);

                    }else if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
                        left = nstd::asDesimal(left) + nstd::asDesimal(right);

                    }else if(nstd::isBulat(left) && nstd::isDesimal(right)) {
                        left = nstd::asBulat(left) + nstd::asDesimal(right);

                    }else if(nstd::isDesimal(left) && nstd::isBulat(right)) {
                        left = nstd::asDesimal(left) + nstd::asBulat(right);
                    }
                }else if(simbolOp == "-=") {
                    if(nstd::isBulat(left) && nstd::isBulat(right)) {
                        left = nstd::asBulat(left) - nstd::asBulat(right);
                        
                    }else if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
                        left = nstd::asDesimal(left) - nstd::asDesimal(right);

                    }else if(nstd::isBulat(left) && nstd::isDesimal(right)) {
                        left = nstd::asBulat(left) - nstd::asDesimal(right);

                    }else if(nstd::isDesimal(left) && nstd::isBulat(right)) {
                        left = nstd::asDesimal(left) - nstd::asBulat(right);
                    }
                }else{
                    throw std::runtime_error("Operasi tidak valid");
                }
            }
        }
    }
    return left;
}

nstd::dinamis VisitorDinamis::visitOperatorPenugasanPerkalian(nstd::konst<OperatorPenugasanPerkalianContext>& ctx) {
    std::cout << "visitOperatorPenugasanPerkalian" << "\n";
    nstd::konst<nstd::bisa_kosong<Token>>& token = ctx.getSimbolOp();
    if(!nstd::isKosong(token)) {
        nstd::konst<Token>& tokenValue = token.value();
        return tokenValue.getValue();
    }
    throw std::runtime_error("Operator Penugasan Perkalian Tidak Valid");
}

nstd::dinamis VisitorDinamis::visitOperasiPenugasanPerkalian(nstd::konst<OperasiPenugasanPerkalianContext>& ctx) {
    std::cout << "visitOperasiPenugasanPerkalian" << "\n";
    const auto& nilaiContexts = ctx.getKumpulanOperasiLogikaContext();
    const auto& operatorContexts = ctx.getKumpulanOperatorPenugasanPerkalianContext();
    if(nstd::isKosong(nilaiContexts)) {
        throw std::runtime_error("Nilai tidak boleh kosong.");
    }
    auto* nilaiContextLeft = dynamic_cast<NilaiContext*>(nilaiContexts->front().get());
    nstd::dinamis left = this->visitNilai(*nilaiContextLeft);
    if(!nstd::isKosong(operatorContexts)) {
        if(!operatorContexts->empty()) {
            for(size_t index = 0; index < operatorContexts->size(); ++index) {
                auto* operatorPerkalianContext = dynamic_cast<OperatorPerkalianContext*>(operatorContexts.value()[index].get());
                nstd::kalimat simbolOp = nstd::asKalimat(this->visitOperatorPerkalian(*operatorPerkalianContext));
                auto* nilaiContextRight = dynamic_cast<NilaiContext*>(nilaiContexts.value()[index + 1].get());
                nstd::dinamis right = this->visitNilai(*nilaiContextRight);
                if(simbolOp == "*=") {
                    if(nstd::isBulat(left) && nstd::isBulat(right)) {
                        left = nstd::asBulat(left) * nstd::asBulat(right);

                    }else if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
                        left = nstd::asDesimal(left) * nstd::asDesimal(right);

                    }else if(nstd::isBulat(left) && nstd::isDesimal(right)) {
                        left = nstd::asBulat(left) * nstd::asDesimal(right);

                    }else if(nstd::isDesimal(left) && nstd::isBulat(right)) {
                        left = nstd::asDesimal(left) * nstd::asBulat(right);
                    }
                }else if(simbolOp == "/=") {
                    if(nstd::isBulat(left) && nstd::isBulat(right)) {
                        left = nstd::asBulat(left) / nstd::asBulat(right);
                        
                    }else if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
                        left = nstd::asDesimal(left) / nstd::asDesimal(right);

                    }else if(nstd::isBulat(left) && nstd::isDesimal(right)) {
                        left = nstd::asBulat(left) / nstd::asDesimal(right);

                    }else if(nstd::isDesimal(left) && nstd::isBulat(right)) {
                        left = nstd::asDesimal(left) / nstd::asBulat(right);
                    }
                }else if(simbolOp == "%=") {
                    if(nstd::isBulat(left) && nstd::isBulat(right)) {
                        left = nstd::asBulat(left) % nstd::asBulat(right);
                        
                    }else if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
                        throw std::runtime_error("Tidak dapat melakukan operasi '%' antara desimal dengan desimal");

                    }else if(nstd::isBulat(left) && nstd::isDesimal(right)) {
                        throw std::runtime_error("Tidak dapat melakukan operasi '%' antara bulat dengan desimal");

                    }else if(nstd::isDesimal(left) && nstd::isBulat(right)) {
                        throw std::runtime_error("Tidak dapat melakukan operasi '%' desimal bulat dengan bulat");
                    }
                }else{
                    throw std::runtime_error("Operasi tidak valid");
                }
            }
        }
    }
    return left;
}

nstd::dinamis VisitorDinamis::visitOperatorLogika(nstd::konst<OperatorLogikaContext>& ctx) {
    std::cout << "visitOperatorLogika" << "\n";
    nstd::konst<nstd::bisa_kosong<Token>>& token = ctx.getSimbolOp();
    if(!nstd::isKosong(token)) {
        nstd::konst<Token>& tokenValue = token.value();
        return tokenValue.getValue();
    }
    throw std::runtime_error("Operator Logika Tidak Valid");
}

nstd::dinamis VisitorDinamis::visitOperasiLogika(nstd::konst<OperasiLogikaContext>& ctx) {
    std::cout << "visitOperasiLogika" << "\n";
    const auto& nilaiContexts = ctx.getKumpulanOperasiPerbandinganContext();
    const auto& operatorContexts = ctx.getKumpulanOperatorLogikaContext();
    if(nstd::isKosong(nilaiContexts)) {
        throw std::runtime_error("Nilai tidak boleh kosong.");
    }
    auto* nilaiContextLeft = dynamic_cast<NilaiContext*>(nilaiContexts->front().get());
    nstd::dinamis left = this->visitNilai(*nilaiContextLeft);
    if(!nstd::isKosong(operatorContexts)) {
        if(!operatorContexts->empty()) {
            for(size_t index = 0; index < operatorContexts->size(); ++index) {
                auto* operatorPerkalianContext = dynamic_cast<OperatorPerkalianContext*>(operatorContexts.value()[index].get());
                nstd::kalimat simbolOp = nstd::asKalimat(this->visitOperatorPerkalian(*operatorPerkalianContext));
                auto* nilaiContextRight = dynamic_cast<NilaiContext*>(nilaiContexts.value()[index + 1].get());
                nstd::dinamis right = this->visitNilai(*nilaiContextRight);
                if(simbolOp == "&&") {
                    if(nstd::isBenarSalah(left) && nstd::isBenarSalah(right)) {
                        left = nstd::asBenarSalah(left) == nstd::asBenarSalah(right);
                    }
                }else if(simbolOp == "||") {
                    if(nstd::isBenarSalah(left) && nstd::isBenarSalah(right)) {
                        left = nstd::asBenarSalah(left) || nstd::asBenarSalah(right);
                    }
                }else{
                    throw std::runtime_error("Operasi tidak valid");
                }
            }
        }
    }
    return left;
}

nstd::dinamis VisitorDinamis::visitOperatorPerbandingan(nstd::konst<OperatorPerbandinganContext>& ctx) {
    std::cout << "visitOperatorPerbandingan" << "\n";
    nstd::konst<nstd::bisa_kosong<Token>>& token = ctx.getSimbolOp();
    if(!nstd::isKosong(token)) {
        nstd::konst<Token>& tokenValue = token.value();
        return tokenValue.getValue();
    }
    throw std::runtime_error("Operator Perbandingan Tidak Valid");
}

nstd::dinamis VisitorDinamis::visitOperasiPerbandingan(nstd::konst<OperasiPerbandinganContext>& ctx) {
    std::cout << "visitOperasiPerbandingan" << "\n";
    const auto& nilaiContexts = ctx.getKumpulanOperasiPrePostContext();
    const auto& operatorContexts = ctx.getKumpulanOperatorPerbandinganContext();
    if(nstd::isKosong(nilaiContexts)) {
        throw std::runtime_error("Nilai tidak boleh kosong.");
    }
    auto* nilaiContextLeft = dynamic_cast<NilaiContext*>(nilaiContexts->front().get());
    nstd::dinamis left = this->visitNilai(*nilaiContextLeft);
    if(!nstd::isKosong(operatorContexts)) {
        if(!operatorContexts->empty()) {
            for(size_t index = 0; index < operatorContexts->size(); ++index) {
                auto* operatorPerkalianContext = dynamic_cast<OperatorPerkalianContext*>(operatorContexts.value()[index].get());
                nstd::kalimat simbolOp = nstd::asKalimat(this->visitOperatorPerkalian(*operatorPerkalianContext));
                auto* nilaiContextRight = dynamic_cast<NilaiContext*>(nilaiContexts.value()[index + 1].get());
                nstd::dinamis right = this->visitNilai(*nilaiContextRight);
                if(simbolOp == "==") {
                    if(nstd::isBulat(left) && nstd::isBulat(right)) {
                        left = nstd::asBulat(left) == nstd::asBulat(right);

                    }else if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
                        left = nstd::asDesimal(left) == nstd::asDesimal(right);

                    }else if(nstd::isBulat(left) && nstd::isDesimal(right)) {
                        left = nstd::asBulat(left) == nstd::asDesimal(right);

                    }else if(nstd::isDesimal(left) && nstd::isBulat(right)) {
                        left = nstd::asDesimal(left) == nstd::asBulat(right);
                    }
                }else if(simbolOp == "!=") {
                    if(nstd::isBulat(left) && nstd::isBulat(right)) {
                        left = nstd::asBulat(left) != nstd::asBulat(right);
                        
                    }else if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
                        left = nstd::asDesimal(left) != nstd::asDesimal(right);

                    }else if(nstd::isBulat(left) && nstd::isDesimal(right)) {
                        left = nstd::asBulat(left) != nstd::asDesimal(right);

                    }else if(nstd::isDesimal(left) && nstd::isBulat(right)) {
                        left = nstd::asDesimal(left) != nstd::asBulat(right);
                    }
                }else if(simbolOp == ">") {
                    if(nstd::isBulat(left) && nstd::isBulat(right)) {
                        left = nstd::asBulat(left) > nstd::asBulat(right);
                        
                    }else if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
                        left = nstd::asDesimal(left) > nstd::asDesimal(right);

                    }else if(nstd::isBulat(left) && nstd::isDesimal(right)) {
                        left = nstd::asBulat(left) > nstd::asDesimal(right);

                    }else if(nstd::isDesimal(left) && nstd::isBulat(right)) {
                        left = nstd::asDesimal(left) > nstd::asBulat(right);
                    }
                }else if(simbolOp == "<") {
                    if(nstd::isBulat(left) && nstd::isBulat(right)) {
                        left = nstd::asBulat(left) < nstd::asBulat(right);
                        
                    }else if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
                        left = nstd::asDesimal(left) < nstd::asDesimal(right);

                    }else if(nstd::isBulat(left) && nstd::isDesimal(right)) {
                        left = nstd::asBulat(left) < nstd::asDesimal(right);

                    }else if(nstd::isDesimal(left) && nstd::isBulat(right)) {
                        left = nstd::asDesimal(left) < nstd::asBulat(right);
                    }
                }else if(simbolOp == ">=") {
                    if(nstd::isBulat(left) && nstd::isBulat(right)) {
                        left = nstd::asBulat(left) >= nstd::asBulat(right);
                        
                    }else if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
                        left = nstd::asDesimal(left) >= nstd::asDesimal(right);

                    }else if(nstd::isBulat(left) && nstd::isDesimal(right)) {
                        left = nstd::asBulat(left) >= nstd::asDesimal(right);

                    }else if(nstd::isDesimal(left) && nstd::isBulat(right)) {
                        left = nstd::asDesimal(left) >= nstd::asBulat(right);
                    }
                }else if(simbolOp == "<=") {
                    if(nstd::isBulat(left) && nstd::isBulat(right)) {
                        left = nstd::asBulat(left) <= nstd::asBulat(right);
                        
                    }else if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
                        left = nstd::asDesimal(left) <= nstd::asDesimal(right);

                    }else if(nstd::isBulat(left) && nstd::isDesimal(right)) {
                        left = nstd::asBulat(left) <= nstd::asDesimal(right);

                    }else if(nstd::isDesimal(left) && nstd::isBulat(right)) {
                        left = nstd::asDesimal(left) <= nstd::asBulat(right);
                    }
                }else{
                    throw std::runtime_error("Operasi tidak valid");
                }
            }
        }
    }
    return left;
}

nstd::dinamis VisitorDinamis::visitOperatorPrePost(nstd::konst<OperatorPrePostContext>& ctx) {
    std::cout << "visitOperatorPrePost" << "\n";
    nstd::konst<nstd::bisa_kosong<Token>>& token = ctx.getSimbolOp();
    if(!nstd::isKosong(token)) {
        nstd::konst<Token>& tokenValue = token.value();
        return tokenValue.getValue();
    }
    throw std::runtime_error("Operator Pre Post Tidak Valid");
}

nstd::dinamis VisitorDinamis::visitOperasiPrePost(nstd::konst<OperasiPrePostContext>& ctx) {
    std::cout << "visitOperasiPrePost" << "\n";
    const auto& nilaiContexts = ctx.getOperasiPenjumlahanContext();
    const auto& operatorContexts = ctx.getOperatorPrePostContext();
    bool isPre = ctx.getIsPre();
    if(nstd::isKosong(nilaiContexts)) {
        throw std::runtime_error("Nilai tidak boleh kosong.");
    }
    auto* nilaiContextLeft = dynamic_cast<NilaiContext*>(nilaiContexts->get());
    nstd::dinamis left = this->visitNilai(*nilaiContextLeft);
    if(!nstd::isKosong(operatorContexts)) {
        auto* operatorPerkalianContext = dynamic_cast<OperatorPerkalianContext*>(operatorContexts->get());
        nstd::kalimat simbolOp = nstd::asKalimat(this->visitOperatorPerkalian(*operatorPerkalianContext));
        if(simbolOp == "++") {
            if(nstd::isBulat(left)) {
                if(isPre) {
                    left = nstd::asBulat(left) + 1;
                }else{
                    left = 1 + nstd::asBulat(left);
                }

            }else if(nstd::isDesimal(left)) {
                if(isPre) {
                    left = nstd::asDesimal(left) + 1;
                }else{
                    left = 1 + nstd::asDesimal(left);
                }

            }
        }else if(simbolOp == "--") {
            if(nstd::isBulat(left)) {
                if(isPre) {
                    left = nstd::asDesimal(left) - 1;
                }else{
                    left = 1 - nstd::asDesimal(left);
                }

            }else if(nstd::isDesimal(left)) {
                if(isPre) {
                    left = nstd::asDesimal(left) - 1;
                }else{
                    left = 1 - nstd::asDesimal(left);
                }
            }
        }else{
            throw std::runtime_error("Operasi tidak valid");
        }
    }
    return left;
}

nstd::dinamis VisitorDinamis::visitOperatorPenjumlahan(nstd::konst<OperatorPenjumlahanContext>& ctx) {
    std::cout << "visitOperatorPenjumlahan" << "\n";
    nstd::konst<nstd::bisa_kosong<Token>>& token = ctx.getSimbolOp();
    if(!nstd::isKosong(token)) {
        nstd::konst<Token>& tokenValue = token.value();
        return tokenValue.getValue();
    }
    throw std::runtime_error("Operator Penjumlahan Tidak Valid");
}

nstd::dinamis VisitorDinamis::visitOperasiPenjumlahan(nstd::konst<OperasiPenjumlahanContext>& ctx) {
    std::cout << "visitOperasiPenjumlahan" << "\n";
    const auto& nilaiContexts = ctx.getKumpulanOperasiPerkalianContext();
    const auto& operatorContexts = ctx.getKumpulanOperatorPenjumlahanContext();
    if(nstd::isKosong(nilaiContexts)) {
        throw std::runtime_error("Nilai tidak boleh kosong.");
    }
    auto* nilaiContextLeft = dynamic_cast<NilaiContext*>(nilaiContexts->front().get());
    nstd::dinamis left = this->visitNilai(*nilaiContextLeft);
    if(!nstd::isKosong(operatorContexts)) {
        if(!operatorContexts->empty()) {
            for(size_t index = 0; index < operatorContexts->size(); ++index) {
                auto* operatorPerkalianContext = dynamic_cast<OperatorPerkalianContext*>(operatorContexts.value()[index].get());
                nstd::kalimat simbolOp = nstd::asKalimat(this->visitOperatorPerkalian(*operatorPerkalianContext));
                auto* nilaiContextRight = dynamic_cast<NilaiContext*>(nilaiContexts.value()[index + 1].get());
                nstd::dinamis right = this->visitNilai(*nilaiContextRight);
                if(simbolOp == "+") {
                    if(nstd::isBulat(left) && nstd::isBulat(right)) {
                        left = nstd::asBulat(left) + nstd::asBulat(right);

                    }else if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
                        left = nstd::asDesimal(left) + nstd::asDesimal(right);

                    }else if(nstd::isBulat(left) && nstd::isDesimal(right)) {
                        left = nstd::asBulat(left) + nstd::asDesimal(right);

                    }else if(nstd::isDesimal(left) && nstd::isBulat(right)) {
                        left = nstd::asDesimal(left) + nstd::asBulat(right);
                    }
                }else if(simbolOp == "-") {
                    if(nstd::isBulat(left) && nstd::isBulat(right)) {
                        left = nstd::asBulat(left) - nstd::asBulat(right);
                        
                    }else if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
                        left = nstd::asDesimal(left) - nstd::asDesimal(right);

                    }else if(nstd::isBulat(left) && nstd::isDesimal(right)) {
                        left = nstd::asBulat(left) - nstd::asDesimal(right);

                    }else if(nstd::isDesimal(left) && nstd::isBulat(right)) {
                        left = nstd::asDesimal(left) - nstd::asBulat(right);
                    }
                }else{
                    throw std::runtime_error("Operasi tidak valid");
                }
            }
        }
    }
    return left;
}

nstd::dinamis VisitorDinamis::visitOperatorPerkalian(nstd::konst<OperatorPerkalianContext>& ctx) {
    std::cout << "visitOperatorPerkalian" << "\n";
    nstd::konst<nstd::bisa_kosong<Token>>& token = ctx.getSimbolOp();
    if(!nstd::isKosong(token)) {
        nstd::konst<Token>& tokenValue = token.value();
        return tokenValue.getValue();
    }
    throw std::runtime_error("Operator Perkalian Tidak Valid");
}

nstd::dinamis VisitorDinamis::visitOperasiPerkalian(nstd::konst<OperasiPerkalianContext>& ctx) {
    std::cout << "visitOperasiPerkalian" << "\n";
    const auto& nilaiContexts = ctx.getKumpulanNilaiContext();
    const auto& operatorContexts = ctx.getKumpulanOperatorPerkalianContext();
    if(nstd::isKosong(nilaiContexts)) {
        throw std::runtime_error("Nilai tidak boleh kosong.");
    }
    auto* nilaiContextLeft = dynamic_cast<NilaiContext*>(nilaiContexts->front().get());
    nstd::dinamis left = this->visitNilai(*nilaiContextLeft);
    if(!nstd::isKosong(operatorContexts)) {
        if(!operatorContexts->empty()) {
            for(size_t index = 0; index < operatorContexts->size(); ++index) {
                auto* operatorPerkalianContext = dynamic_cast<OperatorPerkalianContext*>(operatorContexts.value()[index].get());
                nstd::kalimat simbolOp = nstd::asKalimat(this->visitOperatorPerkalian(*operatorPerkalianContext));
                auto* nilaiContextRight = dynamic_cast<NilaiContext*>(nilaiContexts.value()[index + 1].get());
                nstd::dinamis right = this->visitNilai(*nilaiContextRight);
                if(simbolOp == "*") {
                    if(nstd::isBulat(left) && nstd::isBulat(right)) {
                        left = nstd::asBulat(left) * nstd::asBulat(right);

                    }else if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
                        left = nstd::asDesimal(left) * nstd::asDesimal(right);

                    }else if(nstd::isBulat(left) && nstd::isDesimal(right)) {
                        left = nstd::asBulat(left) * nstd::asDesimal(right);

                    }else if(nstd::isDesimal(left) && nstd::isBulat(right)) {
                        left = nstd::asDesimal(left) * nstd::asBulat(right);
                    }
                }else if(simbolOp == "/") {
                    if(nstd::isBulat(left) && nstd::isBulat(right)) {
                        left = nstd::asBulat(left) / nstd::asBulat(right);
                        
                    }else if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
                        left = nstd::asDesimal(left) / nstd::asDesimal(right);

                    }else if(nstd::isBulat(left) && nstd::isDesimal(right)) {
                        left = nstd::asBulat(left) / nstd::asDesimal(right);

                    }else if(nstd::isDesimal(left) && nstd::isBulat(right)) {
                        left = nstd::asDesimal(left) / nstd::asBulat(right);
                    }
                }else if(simbolOp == "%") {
                    if(nstd::isBulat(left) && nstd::isBulat(right)) {
                        left = nstd::asBulat(left) % nstd::asBulat(right);
                        
                    }else if(nstd::isDesimal(left) && nstd::isDesimal(right)) {
                        throw std::runtime_error("Tidak dapat melakukan operasi '%' antara desimal dengan desimal");

                    }else if(nstd::isBulat(left) && nstd::isDesimal(right)) {
                        throw std::runtime_error("Tidak dapat melakukan operasi '%' antara bulat dengan desimal");

                    }else if(nstd::isDesimal(left) && nstd::isBulat(right)) {
                        throw std::runtime_error("Tidak dapat melakukan operasi '%' desimal bulat dengan bulat");
                    }
                }else{
                    throw std::runtime_error("Operasi tidak valid");
                }
            }
        }
    }
    return left;
}

nstd::dinamis VisitorDinamis::visitNilai(nstd::konst<NilaiContext>& ctx) {
    std::cout << "visitNilai" << "\n";
    if(!nstd::isKosong(ctx.getNilai())) {
        const TokenType& type = ctx.getNilai().value().getType();
        nstd::kalimat value = ctx.getNilai().value().getValue();
        if(type == TokenType::BULAT) {
            return std::stoi(value);
        }else if(type == TokenType::DESIMAL) {
            value.replace(value.find(','), 1, ".");
            return std::stod(value);
        }else if(type == TokenType::KARAKTER) {
            return value[0];
        }else if(type == TokenType::KALIMAT) {
            return value;
        }else if(type == TokenType::BENAR) {
            return benar;
        }else if(type == TokenType::SALAH) {
            return salah;
        }
    }else if(!nstd::isKosong(ctx.getKurungBuka())) {
        auto* value = dynamic_cast<OperasiPenugasanContext*>(ctx.getOperasiPenugasanContext().value().get());
        if(value != nullptr) {
            return this->visitOperasiPenugasan(*value);
        }
    }
    throw std::runtime_error("Nilai tidak valid.");
}