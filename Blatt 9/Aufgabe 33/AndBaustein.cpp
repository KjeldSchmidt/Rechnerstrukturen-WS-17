#include "AndBaustein.hpp"

AndBaustein::AndBaustein() {
    
}

bool AndBaustein::eval() {
    return true;
}

size_t AndBaustein::getInputSize() const {
    return 2;
}

void AndBaustein::setInput(size_t number, std::shared_ptr<Schaltbaustein>  input) {

}

std::shared_ptr<Schaltbaustein> AndBaustein::getInput(size_t number) {
    return NULL;
}
