#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/*
  Hier Hilfsfunktionen ergaenzen. Bitte modularisieren
  Sie Ihren Programmtext vernuenftig. Danke.
*/

void printNumber( char bitField ) {
	if ( bitField >> 7 == 1 ) {
		printf("This bitfield can't represent an actual number. You screwed up.\n");
		return;
	}

	for ( char i = 6; i >= 0; --i ) {
		if ( bitField >> i & 1 ) {
			printf("activate position %c\n", (char) 65 + i ) ;
		}
	}
	printf("\n");

}

char getBitField( char numberAsAscii ) {
	if ( numberAsAscii == 48 ) return 126;
	if ( numberAsAscii == 49 ) return 48;
	if ( numberAsAscii == 50 ) return 109;
	if ( numberAsAscii == 51 ) return 121;
	if ( numberAsAscii == 52 ) return 51;
	if ( numberAsAscii == 53 ) return 91;
	if ( numberAsAscii == 54 ) return 95;
	if ( numberAsAscii == 55 ) return 112;
	if ( numberAsAscii == 56 ) return 127;
	if ( numberAsAscii == 57 ) return 123;
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

	for ( char i = 0; i < 4; ++i ) {
		printNumber( getBitField( paddedNumber[i] ) );
	}

	printf("%s\n", paddedNumber);
}

int main(int argc, char **argv) {
	showNumber(123);
	showNumber(4567);
	showNumber(8910);
}
