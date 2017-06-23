#include "bitvektor.h"
#include "tests.h"

int main() {
  return 0;
}

Bitvektor::Bitvektor( size_t length ) {
  this->bits = (bool*) malloc( length * sizeof( bits ) );
}

bool Bitvektor::checkSizes( const Bitvektor& other ) const {
  return this->length == other.length;
}
