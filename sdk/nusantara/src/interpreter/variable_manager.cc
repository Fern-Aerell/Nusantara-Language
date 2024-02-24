#include "interpreter/variable_manager.h"
#include "nstd/peta.h"
#include "interpreter/variable.h"

VariableManager::VariableManager(
    nstd::peta<std::string, Variable> storage
):
    storage(std::move(storage)) 
{}

bool VariableManager::containsVariable(const std::string& nama) const {
    return nstd::containsKey(storage, nama);
}

const nstd::dinamis& VariableManager::get(const std::string& nama) const {
    if(this->containsVariable(nama)) {
        
    }
}

void VariableManager::set(const std::string& nama, const nstd::dinamis& nilai) {

}