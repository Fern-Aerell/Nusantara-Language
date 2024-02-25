#pragma once

#include <algorithm>
#include <exception>
#include <memory>
#include <regex>
#include <string>
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/tipe_data.h"

#define TIPE_DATA_BILANGAN_BULAT long long int
#define TIPE_DATA_BILANGAN_DESIMAL long double

namespace nstd {
    class nilai_bilangan_tidak_valid_exception: public std::exception {
        public:
            [[nodiscard]] const char * what() const override {
                return "nilai bilangan tidak valid.";
            }
    };

    class nilai_bilangan {
        public:
            nilai_bilangan() = default;
            virtual ~nilai_bilangan() = default;
            nilai_bilangan(const nilai_bilangan &) = default;
            nilai_bilangan &operator=(const nilai_bilangan &) = default;
            nilai_bilangan(nilai_bilangan &&) noexcept = default;
            nilai_bilangan &operator=(nilai_bilangan &&) noexcept = default;
    };

    class bilangan_bulat: public nilai_bilangan{
        public:
            explicit bilangan_bulat(const TIPE_DATA_BILANGAN_BULAT& nilai): nilai(nilai) {}
            [[nodiscard]] const TIPE_DATA_BILANGAN_BULAT& getNilai() const {
                return this->nilai;
            }
        private:
            TIPE_DATA_BILANGAN_BULAT nilai;
    };

    class bilangan_desimal: public nilai_bilangan {
        public:
            explicit bilangan_desimal(const TIPE_DATA_BILANGAN_DESIMAL& nilai): nilai(nilai) {}
            [[nodiscard]] const TIPE_DATA_BILANGAN_DESIMAL& getNilai() const {
                return this->nilai;
            }
        private:
            TIPE_DATA_BILANGAN_DESIMAL nilai;
    };

    class bilangan: public tipe_data {
        public:
            explicit bilangan(const TIPE_DATA_BILANGAN_BULAT& nilai): nilai(std::make_unique<bilangan_bulat>(nilai)) {}
            explicit bilangan(const TIPE_DATA_BILANGAN_DESIMAL& nilai): nilai(std::make_unique<bilangan_desimal>(nilai)) {}
            [[nodiscard]] const std::unique_ptr<nilai_bilangan>& ambilNilai() const {
                return this->nilai;
            }
            [[nodiscard]] bool bulat() const {
                return isBulat() && !isBulat();
            }
            [[nodiscard]] bool desimal() const {
                return isDesimal() && !isBulat();
            }
            [[nodiscard]] kalimat ubahKeKalimat() const {
                if(const auto* ptr = dynamic_cast<bilangan_bulat*>(this->nilai.get())) {
                    return kalimat(std::to_string(ptr->getNilai()));
                }else if(const auto* ptr = dynamic_cast<bilangan_desimal*>(this->nilai.get())) {
                    std::string str = std::to_string(ptr->getNilai());
                    size_t pos = str.find('.');
                    if(pos != std::string::npos) {
                        size_t end = str.find_last_not_of('0');
                        if(end == pos) {
                            str.erase(pos);  // Hapus koma
                        } else if(end != std::string::npos && end > pos) {
                            str.erase(end + 1);
                        }
                    }
                    std::replace(str.begin(), str.end(), '.', ',');
                    return kalimat(str);
                }
                throw nilai_bilangan_tidak_valid_exception();
            }
            static bilangan ubah(const kalimat& nilai) {
                const std::regex patternBulat("^-?[0-9]+$");
                const std::regex patternDesimal("-?[0-9]+,[0-9]+$");
                const std::string str = nilai.ubahKeString();
                if(std::regex_match(str, patternBulat)) {
                    return bilangan(std::stoll(str));
                }else if(std::regex_match(str, patternDesimal)) {
                    return bilangan(std::stold(str));
                }
                throw nilai_bilangan_tidak_valid_exception();
            }
            bilangan operator-(const int& nilaiX) {
                if(const auto* ptr = dynamic_cast<bilangan_bulat*>(this->nilai.get())) {
                    return bilangan(ptr->getNilai() - nilaiX);
                }else if(const auto* ptr = dynamic_cast<bilangan_desimal*>(this->nilai.get())) {
                    return bilangan(ptr->getNilai() - nilaiX);
                }
                throw nilai_bilangan_tidak_valid_exception();
            }
        private:
            std::unique_ptr<nilai_bilangan> nilai;
            void setBulat(const TIPE_DATA_BILANGAN_BULAT& nilai) {
                this->nilai = std::make_unique<bilangan_bulat>(nilai);
            }
            void setDesimal(const TIPE_DATA_BILANGAN_DESIMAL& nilai) {
                this->nilai = std::make_unique<bilangan_desimal>(nilai);
            }
            [[nodiscard]] bool isBulat() const {
                if(const auto* ptr = dynamic_cast<bilangan_bulat*>(this->nilai.get())) {
                    return true;
                }
                return false;
            }
            [[nodiscard]] bool isDesimal() const {
                if(const auto* ptr = dynamic_cast<bilangan_desimal*>(this->nilai.get())) {
                    return true;
                }
                return false;
            }
            friend std::ostream& operator<<(std::ostream& ost, const bilangan& obj) {
                return ost << obj.ubahKeKalimat();
            }
    };
}