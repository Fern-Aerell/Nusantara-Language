#include "interpreter/variable_manager.h"
#include <format>
#include <stdexcept>
#include "nstd/peta.h"
#include "interpreter/variable.h"

VariableManager::VariableManager(
    nstd::peta<std::string, Variable> storage
):
    storage(std::move(storage)) 
{}

bool VariableManager::containsVariableWithName(const std::string& nama) {
    return nstd::containsKey(storage, nama);
}

Variable& VariableManager::get(const std::string& nama) {
    if(this->containsVariableWithName(nama)) {
        return this->storage[nama];
    }
    throw std::runtime_error(std::format("Variable '{}' belum dibuat.", nama));
}

const nstd::dinamis& VariableManager::getNilai(const std::string& nama) {
    return this->get(nama).getNilai();
}

void VariableManager::set(const std::string& nama, const nstd::dinamis& nilai) {
    this->get(nama).setNilai(nilai);
}

void VariableManager::create(const TokenType& tipe, const std::string& nama) {
    if(!this->containsVariableWithName(nama)) {
        this->storage[nama] = Variable(tipe, {});
    }else{
        throw std::runtime_error(std::format("Variable '{}' sudah dibuat.", nama));
    }
}