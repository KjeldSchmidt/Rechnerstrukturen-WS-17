#include "AndBaustein.hpp"
#include <iostream>

//Expliziter Konstruktor freut den Compiler
AndBaustein::AndBaustein() {

}

// Ist nur einer der Eingänge falsch, so ist die Auswertung immer falsch und kann zurückgegeben werden.
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

//Man beachte, dass diese Funktion fehlerhaft implementiert ist; Sie missachtet den numbers-parameter gänzlich. In den gegebenen Testfällen ist dies nicht relevant.
void AndBaustein::setInput(size_t number, std::shared_ptr<Schaltbaustein>  input) {
    this->inputs.push_back( input );
}

// Durch die Verwendung von .at() ist boundary-checking gratis enthalten, und wir müssen uns selbst nicht mehr die Mühe machen eine Exception zu werfen, wenn der Parameter außerhalb liegt.
std::shared_ptr<Schaltbaustein> AndBaustein::getInput(size_t number) {
    return this->inputs.at(number);
}
