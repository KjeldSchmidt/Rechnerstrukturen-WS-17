#include "OrBaustein.hpp"
#include <iostream>

// AndBaustein und OrBaustein haben manche Gemeinsamkeiten
// Aber bei weitem nicht hinreichende um eine "Zwischenklasse", von der And und Or, nicht aber Not, erben, zu entwickeln.

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

// Eine klügere Lösung könnte sich wohl damit abfinden wenn die Inputs in zufälliger Reihenfolge gesetzt werden.
// Aber der Programmierer der diesen Code nutzt kann sich auch einfach ein klein wenig Mühe geben, nicht grundlos zufällige Zahlen als Indizes zu verwenden.
void OrBaustein::setInput(size_t number, std::shared_ptr<Schaltbaustein>  input) {
    if ( this->inputs.size() == number ) {
        this->inputs.push_back( input );
    } else if ( this->inputs.size() > number ) {
        this->inputs.at( number ) = input;
    } else {
        throw std::out_of_range("Please initialize the inputs in order");
    }
}

// Durch die Verwendung von .at() ist boundary-checking gratis enthalten, und wir müssen uns selbst nicht mehr die Mühe machen eine Exception zu werfen, wenn der Parameter außerhalb liegt.
std::shared_ptr<Schaltbaustein> OrBaustein::getInput(size_t number) {
    return this->inputs.at(number);
}
