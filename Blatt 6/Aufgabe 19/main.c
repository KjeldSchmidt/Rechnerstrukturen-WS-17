#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/*
  Hier Hilfsfunktionen ergaenzen. Bitte modularisieren
  Sie Ihren Programmtext vernuenftig. Danke.
*/

void printNumber( char showBitField ) {
	if ( showBitField >> 7 == 1 ) {
		printf("This bitfield can't represent an actual number. You screwed up.\n");
		return;
	}



}

void leftpadNumber( char *string, char minLength, char *out) {
	char currentActualLength = 0;
	char offset;
	char paddedString[ minLength ];
	memset( paddedString, 48, minLength );

	while ( string[ currentActualLength ] != 0 ) {
		++currentActualLength;
	}
	
	offset = minLength - currentActualLength;

	for ( char i = 0; i < currentActualLength; ++i ) {
		paddedString[ i + offset ] = string[ i ];
	}

	for ( char i = 0; i < minLength; ++i ) {
		out[i] = paddedString[i];
	}
}

void showNumber(unsigned int number) {
  char numberAsString[5];
  char paddedNumber[5];
  sprintf( numberAsString, "%d", number );
  leftpadNumber( numberAsString, 4, paddedNumber );
  printf("%s\n", paddedNumber);
}

int main(int argc, char **argv) {
  showNumber(123);
  showNumber(4567);
  showNumber(8910);
}
