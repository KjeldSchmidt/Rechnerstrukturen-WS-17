#include "NotBaustein.hpp"

NotBaustein::NotBaustein() {
    
}

bool NotBaustein::eval() {
    return true;
}

size_t NotBaustein::getInputSize() const {
    return 2;
}

void NotBaustein::setInput(size_t number,  std::shared_ptr<Schaltbaustein>  input) {

}

std::shared_ptr<Schaltbaustein> NotBaustein::getInput(size_t number) {
    return NULL;
}
