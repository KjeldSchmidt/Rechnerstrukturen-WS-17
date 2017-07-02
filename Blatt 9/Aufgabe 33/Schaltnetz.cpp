#include "Schaltnetz.hpp"

/*
 *	Die Funktionen in dieser Datei sollten selbsterklärend sein. Interessant ist, bestenfalls, nur eval()
 *	Diese Funktion Funktion wird, wenn man sich etwas informell ausdrücken darf, durch Rekursives evaluieren der verbundenen Bausteine durchgeführt.
 *  Der Ausgabebaustein evauliert all seine Eingänge, die wiederum deren EIngänge evaluieren... die schließlich die Schalterbausteine s1 und s2 referenzieren müssen.
 */

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
    return this->output->eval();;
}

/*
 * Damit das Netz in diesem Aufruf seinen Zustand nicht verändert, aber der Programmieraufwand hinreichend gering bleibt
 * wird der ursprüngliche Zustand der Eingabeschalter gespeichert und nach evaluierung zurückgesetzt.
 */

bool Schaltnetz::eval(bool x, bool y) {
    bool ret;
    bool oldX = this->s1->eval();
    bool oldY = this->s2->eval();
    this->setValueX( x );
    this->setValueY( y );
    ret = this->output->eval();
    this->setValueX( oldX );
    this->setValueY( oldY );

    return ret;
}
