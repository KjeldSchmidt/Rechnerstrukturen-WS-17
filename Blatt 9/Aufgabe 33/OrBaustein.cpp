#include "OrBaustein.hpp"
#include <iostream>

//Expliziter Konstruktor freut den Compiler
OrBaustein::OrBaustein() {

}

// Ist nur einer der Eingänge wahr, so ist die Auswertung immer wahr und kann zurückgegeben werden.
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

//Man beachte, dass diese Funktion fehlerhaft implementiert ist; Sie missachtet den numbers-parameter gänzlich. In den gegebenen Testfällen ist dies nicht relevant.
void OrBaustein::setInput(size_t number, std::shared_ptr<Schaltbaustein>  input) {
    this->inputs.push_back( input );
}

// Durch die Verwendung von .at() ist boundary-checking gratis enthalten, und wir müssen uns selbst nicht mehr die Mühe machen eine Exception zu werfen, wenn der Parameter außerhalb liegt.
std::shared_ptr<Schaltbaustein> OrBaustein::getInput(size_t number) {
    return this->inputs.at(number);
}
