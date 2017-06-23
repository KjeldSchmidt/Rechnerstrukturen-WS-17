#include "bitvektor.h"


void sizeTest() {
  std::cout << "sizeTest" << std::endl;
  Bitvektor zeroLengthVektor( 0 );
  Bitvektor vektor2( 10 );
  Bitvektor vektor3( 10 );
  Bitvektor vektor4( 11 );

  bool result = false;

  result = zeroLengthVektor.checkSizes( vektor2 );
  std::cout << ( result == false);
  result = zeroLengthVektor.checkSizes( zeroLengthVektor );
  std::cout << ( result == true);
  result = vektor2.checkSizes( vektor2 );
  std::cout << ( result == true);
  result = vektor2.checkSizes( vektor3 );
  std::cout << ( result == true);
  result = vektor2.checkSizes( vektor4 );
  std::cout << ( result == false);
  result = vektor2.checkSizes( zeroLengthVektor );
  std::cout << ( result == false);

  std::cout << std::endl << std::endl;
}

void setAndGetTest() {
  std::cout << "setAndGetTest" << std::endl;
  Bitvektor vektor1( 10 );

  vektor1.setBit( 5, 1 );
  vektor1.setBit( 1, 0 );

  bool result = false;
  result = vektor1.getBit( 5 ) == 1;
  std::cout << ( result == true );
  result = vektor1.getBit( 0 ) == 0;
  std::cout << ( result == true );

  std::cout << std::endl << std::endl;
}

void allZeroTest() {
  std::cout << "allZeroTest" << std::endl;
  Bitvektor zeroLengthVektor( 0 );
  Bitvektor vektor2( 10 );
  vektor2.setBit(0, 1);
  Bitvektor vektor3( 11 );

  bool result = false;

  result = zeroLengthVektor.allZero();
  std::cout << ( result == true );
  result = vektor2.allZero( );
  std::cout << ( result == false );
  result = vektor3.allZero();
  std::cout << ( result == true);

  std::cout << std::endl << std::endl;
}

void equalsTest() {
  std::cout << "equalsTest" << std::endl;
  Bitvektor zeroLengthVektor( 0 );
  Bitvektor vektor1( 10 );
  vektor1.setBit( 1, 1 );
  Bitvektor vektor2( 10 );
  vektor2.setBit( 1, 1 );
  Bitvektor vektor3( 10 );
  vektor3.setBit( 1, 0 );
  Bitvektor vektor4( 11 );

  bool result = false;

  result = zeroLengthVektor.equals( vektor2 );
  std::cout << ( result == false );
  result = zeroLengthVektor.equals( zeroLengthVektor );
  std::cout << ( result == true );
  result = vektor2.equals( zeroLengthVektor );
  std::cout << ( result == false );
  result = vektor2.equals( vektor3 );
  std::cout << ( result == false );
  result = vektor2.equals( vektor2 );
  std::cout << ( result == true );
  result = vektor2.equals( vektor1 );
  std::cout << ( result == true );
  result = vektor2.equals( vektor4 );
  std::cout << ( result == false );
  result = vektor3.equals( vektor4 );
  std::cout << ( result == false );

  std::cout << std::endl << std::endl;
}

void getSizeTest() {
  std::cout << "sizeTest" << std::endl;
  Bitvektor zeroLengthVektor( 0 );
  Bitvektor vektor0( 10 );
  Bitvektor vektor1( 11 );

  int result = false;

  result = zeroLengthVektor.getSize();
  std::cout << ( result == 0 );
  result = vektor0.getSize();
  std::cout << ( result == 10 );
  result = vektor1.getSize();
  std::cout << ( result == 11 );


  std::cout << std::endl << std::endl;
}

void calculateNotTest() {
  std::cout << "calculateNotTest" << std::endl;
  Bitvektor zeroLengthVektor( 0 );
  Bitvektor vektor1( 10 );
  for ( int i = 0; i < vektor1.getSize(); ++i ) {
    vektor1.setBit( i, 0 );
  }
  vektor1.setBit( 1, 1 );
  Bitvektor vektor2( 10 );
  for ( int i = 0; i < vektor2.getSize(); ++i ) {
    vektor2.setBit( i, 1 );
  }
  vektor2.setBit( 1, 0 );

  Bitvektor result(0);

  result = zeroLengthVektor.calculateNot();
  std::cout << ( result.equals( zeroLengthVektor ) );
  result = vektor1.calculateNot();
  std::cout << ( result.equals( vektor2 ) );
  result = vektor2.calculateNot();
  std::cout << ( result.equals( vektor1 ) );

  std::cout << std::endl << std::endl;
}

void runTests() {
  sizeTest();
  setAndGetTest();
  allZeroTest();
  equalsTest();
  getSizeTest();
  calculateNotTest();
}
