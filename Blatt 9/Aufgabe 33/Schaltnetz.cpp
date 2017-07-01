#include "Schaltnetz.h"

Schaltnetz::Schaltnetz() {

}

void Schaltnetz::setOutput(std::shared_ptr<Schaltbaustein> baustein) {

}

std::shared_ptr<Schaltbaustein> Schaltnetz::getInputX() {
    return this->s1;
}

std::shared_ptr<Schaltbaustein> Schaltnetz::getInputY() {
    return this->s2;
}

void Schaltnetz::setValueX(bool value) {

}

void Schaltnetz::setValueY(bool value) {

}

bool Schaltnetz::eval() {
    return true;
}

bool Schaltnetz::eval(bool x, bool y) {
    return true;
}
