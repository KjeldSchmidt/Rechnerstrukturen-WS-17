#include "NotBaustein.hpp"

NotBaustein::NotBaustein() {

}

bool NotBaustein::eval() {
    for ( auto p = this->inputs.begin(); p != this->inputs.end(); ++p ) {
        if ( !((*p)->eval()) ) {
            return false;
        }
    }
    return true;
}

size_t NotBaustein::getInputSize() const {
    return this->inputs.size();
}

void NotBaustein::setInput(size_t number,  std::shared_ptr<Schaltbaustein>  input) {
    this->inputs.push_back( input );
}

std::shared_ptr<Schaltbaustein> NotBaustein::getInput(size_t number) {
    return NULL;
}
