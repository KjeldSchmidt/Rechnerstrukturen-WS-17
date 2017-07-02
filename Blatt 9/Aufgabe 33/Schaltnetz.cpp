#include "Schaltnetz.hpp"

Schaltnetz::Schaltnetz() {
    std::shared_ptr<Schalterbaustein> i1( new Schalterbaustein() ); 
    std::shared_ptr<Schalterbaustein> i2( new Schalterbaustein() );
    this->s1 = i1;
    this->s2 = i2;
}

void Schaltnetz::setOutput(std::shared_ptr<Schaltbaustein> baustein) {
    this->output = baustein;
}

std::shared_ptr<Schaltbaustein> Schaltnetz::getInputX() {
    return this->s1;
}

std::shared_ptr<Schaltbaustein> Schaltnetz::getInputY() {
    return this->s2;
}

void Schaltnetz::setValueX(bool value) {
    this->s1->setValue( value );
}

void Schaltnetz::setValueY(bool value) {
    this->s2->setValue( value );
}

bool Schaltnetz::eval() {
    return true;
}

bool Schaltnetz::eval(bool x, bool y) {
    this->setValueX( x );
    this->setValueY( y );
    return this->output->eval();
}
