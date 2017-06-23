#include "bitvektor.h"


void sizeTest() {
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


void runTests() {
  sizeTest();
}
