#include "AndBaustein.hpp"
#include <iostream>

AndBaustein::AndBaustein() {

}

bool AndBaustein::eval() {
    for ( auto p = this->inputs.begin(); p != this->inputs.end(); ++p ) {
        if ( !((*p)->eval()) ) {
            return false;
        }
    }
    return true;
}

size_t AndBaustein::getInputSize() const {
    return this->inputs.size();
}

void AndBaustein::setInput(size_t number, std::shared_ptr<Schaltbaustein>  input) {
    this->inputs.push_back( input );
}

std::shared_ptr<Schaltbaustein> AndBaustein::getInput(size_t number) {
    return NULL;
}
