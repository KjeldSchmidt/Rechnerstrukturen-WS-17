#include "Schaltbaustein.hpp"

bool Schaltbaustein::eval() {
    return true;
}

size_t Schaltbaustein::getInputSize() const {
    return 2;
}

void Schaltbaustein::setInput(size_t number,  std::shared_ptr<Schaltbaustein>  input) {

}

std::shared_ptr<Schaltbaustein> Schaltbaustein::getInput(size_t number) {
    return NULL;
}
