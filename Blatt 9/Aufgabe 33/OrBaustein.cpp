#include "OrBaustein.hpp"
#include <iostream>

OrBaustein::OrBaustein() {

}

bool OrBaustein::eval() {
    for ( auto p = this->inputs.begin(); p != this->inputs.end(); ++p ) {
        if ( (*p)->eval() ) {
            return true;
        }
    }
    return false;
}

size_t OrBaustein::getInputSize() const {
    return this->inputs.size();
}

void OrBaustein::setInput(size_t number,  std::shared_ptr<Schaltbaustein>  input) {
    this->inputs.push_back( input );
}

std::shared_ptr<Schaltbaustein> OrBaustein::getInput(size_t number) {
    return NULL;
}
