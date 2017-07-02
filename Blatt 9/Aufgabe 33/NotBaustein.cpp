#include "NotBaustein.hpp"
#include <stdexcept>

//Expliziter Konstruktor freut den Compiler
NotBaustein::NotBaustein() {

}

// Ein logisches NOT. Weitere Erklärungen sind hoffentlich nicht nötig.
bool NotBaustein::eval() {
    return !(this->input->eval());
}

// NOT hat stets nur einen Eingang.
size_t NotBaustein::getInputSize() const {
    return 1;
}

// Anders als AND und OR ist diese Funktion hier sinnvoll implementiert; Versucht man einen anderen Eingang als 0 zu setzen, gibt es logischerweise einen Fehler
void NotBaustein::setInput(size_t number, std::shared_ptr<Schaltbaustein>  input) {
    if ( number == 0 ) {
        this->input = input;
    } else {
        throw std::out_of_range("0 is the only valid input");
    }
}

// Natürlich könnte man stets schlicht den einzigen Input zurückgeben, aber mit einem expliziten Fehler fühlt es sich besser an.
std::shared_ptr<Schaltbaustein> NotBaustein::getInput(size_t number) {
    if ( number == 0 ) {
       return this->input;
    } else {
        throw std::out_of_range("0 is the only valid input");
    }
}
