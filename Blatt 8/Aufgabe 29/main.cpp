#include "bitvektor.h"

int main() {
  return 0;
}

bool Bitvektor::checkSizes( const Bitvektor& other ) const {
  return this->length == other.length;
}
