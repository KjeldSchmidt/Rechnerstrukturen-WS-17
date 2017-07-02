#include "NotBaustein.hpp"
#include <stdexcept>

NotBaustein::NotBaustein() {

}

bool NotBaustein::eval() {
    return !(this->input->eval());
}

size_t NotBaustein::getInputSize() const {
    return 1;
}

void NotBaustein::setInput(size_t number, std::shared_ptr<Schaltbaustein>  input) {
    if ( number == 0 ) {
        this->input = input;
    } else {
        throw std::out_of_range("0 is the only valid input");
    }
}

std::shared_ptr<Schaltbaustein> NotBaustein::getInput(size_t number) {
    return NULL;
}
