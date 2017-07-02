#include "Schalterbaustein.hpp"

/*
*   Mehrere der hier gegebenen Funktionen sind unnütz, aber die Erbschaft aus dem Schaltbaustein war gefordert.
*   Im Ausgleich für eigentlich reduzierbare Funktionen (die in einer besseren Implementation eventuell Fehler werfen würden)
*   Sind wir in der Lage Schalterbausteine auf eine Weise zu verwenden, die zu anderen Schaltbausteinen äquivalent ist.
*   Dadurch müssen einzelne Logikgatter nicht wissen, ob sie an eine Eingabe des Schaltnetzes oder an einen Baustein angeschlossen sind.
*/

Schalterbaustein::Schalterbaustein() {
    this->value = false;
}

bool Schalterbaustein::eval() {
    return this->value;
}

size_t Schalterbaustein::getInputSize() const {
    return 0;
}

void Schalterbaustein::setValue( bool value ) {
    this->value = value;
}

void Schalterbaustein::setInput(size_t number,  std::shared_ptr<Schaltbaustein> input) {
    
}

std::shared_ptr<Schaltbaustein> Schalterbaustein::getInput(size_t number) {
    return NULL;
}