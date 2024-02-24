#include "interpreter/variable.h"
#include <format>
#include <stdexcept>
#include <string>

Variable::Variable(
    const TokenType& tipe,
    nstd::dinamis nilai
):
    tipe(tipe),
    nilai(std::move(nilai))
{}

const nstd::dinamis& Variable::getNilai() const  {
    return this->nilai;
}

void Variable::setNilai(const nstd::dinamis& nilai) {
    if(this->tipe == TokenType::TIPE_DATA_BILANGAN && !nstd::isBilangan(nilai)) {
        throw std::runtime_error(std::format("'{}' bukanlah sebuah bilangan.", nstd::toString(nilai)));
    }else if(this->tipe == TokenType::TIPE_DATA_KALIMAT && !nstd::is<std::string>(nilai)) {
        throw std::runtime_error(std::format("'{}' bukanlah sebuah kalimat.", nstd::toString(nilai)));
    }else if(this->tipe == TokenType::TIPE_DATA_BENARSALAH && !nstd::is<bool>(nilai)) {
        throw std::runtime_error(std::format("'{}' bukanlah sebuah benar atau salah.", nstd::toString(nilai)));
    }
    this->nilai = nilai;
}