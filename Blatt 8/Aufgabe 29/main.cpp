#include "bitvektor.h"
#include "tests.h"

int main() {
  runTests();
  return 0;
}

Bitvektor::Bitvektor( size_t length ) {
  this->bits = (bool*) malloc( length * sizeof( bits ) );
  this->length = length;
}

bool Bitvektor::checkSizes( const Bitvektor& other ) const {
  return this->length == other.length;
}

Bitvektor Bitvektor::calculateAnd( const Bitvektor& other ) const {

}

Bitvektor Bitvektor::calculateOr( const Bitvektor& other ) const {

}

Bitvektor Bitvektor::calculateXor( const Bitvektor& other ) const {

}

Bitvektor Bitvektor::calculateNot() const {

}

size_t Bitvektor::getSize() const {
  return this->length;
}

bool Bitvektor::getBit(size_t position) const {

}

void Bitvektor::setBit(size_t position, bool value) {

}

bool Bitvektor::allZero() const {

}

bool Bitvektor::equals(const Bitvektor& other) const {

}

void Bitvektor::printOnConsole() const {

}
