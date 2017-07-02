#include "Schalterbaustein.hpp"

Schalterbaustein::Schalterbaustein() {
    this->value = false;
}

bool Schalterbaustein::eval() {
    return this->value;
}

size_t Schalterbaustein::getInputSize() const {
    return 0;
}

void Schalterbaustein::setValue( bool value ) {
    this->value = value;
}

void Schalterbaustein::setInput(size_t number,  std::shared_ptr<Schaltbaustein> input) {

}

std::shared_ptr<Schaltbaustein> Schalterbaustein::getInput(size_t number) {
    return NULL;
}