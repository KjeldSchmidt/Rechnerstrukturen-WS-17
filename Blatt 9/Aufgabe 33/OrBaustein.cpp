#include "OrBaustein.hpp"

OrBaustein::OrBaustein() {
    
}

bool OrBaustein::eval() {
    return true;
}

size_t OrBaustein::getInputSize() const {
    return 2;
}

void OrBaustein::setInput(size_t number,  std::shared_ptr<Schaltbaustein>  input) {

}

std::shared_ptr<Schaltbaustein> OrBaustein::getInput(size_t number) {
    return NULL;
}
