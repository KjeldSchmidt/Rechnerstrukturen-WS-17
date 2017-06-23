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
  if ( this->getSize() != other.getSize() ) return Bitvektor(0);
  Bitvektor result( this->getSize() );
  for ( int i = 0; i < this->getSize(); ++i ) {
    result.setBit( i, this->getBit( i ) & other.getBit( i ) );
  }

  return result;
}

Bitvektor Bitvektor::calculateOr( const Bitvektor& other ) const {
  if ( this->getSize() != other.getSize() ) return Bitvektor(0);
  Bitvektor result( this->getSize() );
  for ( int i = 0; i < this->getSize(); ++i ) {
    result.setBit( i, this->getBit( i ) | other.getBit( i ) );
  }

  return result;
}

Bitvektor Bitvektor::calculateXor( const Bitvektor& other ) const {
  if ( this->getSize() != other.getSize() ) return Bitvektor(0);
  Bitvektor result( this->getSize() );
  for ( int i = 0; i < this->getSize(); ++i ) {
    result.setBit( i, this->getBit( i ) != other.getBit( i ) );
  }

  return result;
}

Bitvektor Bitvektor::calculateNot() const {
  Bitvektor result( this->getSize() );
  for ( int i = 0; i < this->getSize(); ++i ) {
    result.setBit( i, ~this->getBit( i ) );
  }

  return result;
}

size_t Bitvektor::getSize() const {
  return this->length;
}

bool Bitvektor::getBit(size_t position) const {
  if ( position < 0 || position >= this->getSize() ) {
    throw "IndexOutOfBoundsException";
  }
  bool result = this->bits[ position ];
  return result;
}

void Bitvektor::setBit(size_t position, bool value) {
  if ( position < 0 || position >= this->getSize() ) {
    throw "IndexOutOfBoundsException";
  }
  this->bits[ position ] = value;
}

bool Bitvektor::allZero() const {
  for ( int i = 0; i < this->getSize(); ++i ) {
    if ( this->getBit( i ) ) {
      return false;
    }
  }

  return true;
}

bool Bitvektor::equals(const Bitvektor& other) const {
  if ( this->getSize() != other.getSize() ) return false;

  for ( int i = 0; i < this->getSize(); ++i ) {
    if( this->getBit( i ) != other.getBit( i ) ) {
      return false;
    }
  }

  return true;
}

void Bitvektor::printOnConsole() const {
  for ( int i = this->getSize(); i >= 0; --i ) {
    std::cout << this->getBit( i );
  }
}
