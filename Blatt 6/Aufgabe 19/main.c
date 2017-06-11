#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/*
  Hier Hilfsfunktionen ergaenzen. Bitte modularisieren
  Sie Ihren Programmtext vernuenftig. Danke.
*/

void printNumber( char *bitField ) {
	for ( char i = 0; i < 4; ++i ) {
		if ( bitField[i] >> 7 == 1 ) {
			printf("This bitfield (%d) can't represent an actual number. You screwed up.\n", bitField[i] );
			return;
		}	
	}

	char line0[16];
	char line1[16];
	char line2[16];
	char line3[16];
	char line4[16];
	memset( line0, (char) 32, 15 );
	memset( line1, (char) 32, 15 );
	memset( line2, (char) 32, 15 );
	memset( line3, (char) 32, 15 );
	memset( line4, (char) 32, 15 );
	line0[15] = 0;
	line1[15] = 0;
	line2[15] = 0;
	line3[15] = 0;
	line4[15] = 0;

	if ( bitField[0] >> 6 & 1 ) line0[1] = 45;
	if ( bitField[1] >> 6 & 1 ) line0[5] = 45;
	if ( bitField[2] >> 6 & 1 ) line0[9] = 45;
	if ( bitField[3] >> 6 & 1 ) line0[13] = 45;
	if ( bitField[0] >> 5 & 1 ) line1[0] = 124;
	if ( bitField[1] >> 5 & 1 ) line1[4] = 124;
	if ( bitField[2] >> 5 & 1 ) line1[8] = 124;
	if ( bitField[3] >> 5 & 1 ) line1[12] = 124;
	if ( bitField[0] >> 4 & 1 ) line1[2] = 124;
	if ( bitField[1] >> 4 & 1 ) line1[6] = 124;
	if ( bitField[2] >> 4 & 1 ) line1[10] = 124;
	if ( bitField[3] >> 4 & 1 ) line1[14] = 124;
	if ( bitField[0] >> 3 & 1 ) line2[1] = 45;
	if ( bitField[1] >> 3 & 1 ) line2[5] = 45;
	if ( bitField[2] >> 3 & 1 ) line2[9] = 45;
	if ( bitField[3] >> 3 & 1 ) line2[13] = 45;
	if ( bitField[0] >> 2 & 1 ) line3[0] = 124;
	if ( bitField[1] >> 2 & 1 ) line3[4] = 124;
	if ( bitField[2] >> 2 & 1 ) line3[8] = 124;
	if ( bitField[3] >> 2 & 1 ) line3[12] = 124;
	if ( bitField[0] >> 1 & 1 ) line3[2] = 124;
	if ( bitField[1] >> 1 & 1 ) line3[6] = 124;
	if ( bitField[2] >> 1 & 1 ) line3[10] = 124;
	if ( bitField[3] >> 1 & 1 ) line3[14] = 124;
	if ( bitField[0] >> 0 & 1 ) line4[1] = 45;
	if ( bitField[1] >> 0 & 1 ) line4[5] = 45;
	if ( bitField[2] >> 0 & 1 ) line4[9] = 45;
	if ( bitField[3] >> 0 & 1 ) line4[13] = 45;

	printf("%s\n", line0 );
	printf("%s\n", line1 );
	printf("%s\n", line2 );
	printf("%s\n", line3 );
	printf("%s\n", line4 );
	

	printf("\n");

}

char getBitField( char numberAsAscii ) {
	if ( numberAsAscii == 48 ) return 119;
	if ( numberAsAscii == 49 ) return 10;
	if ( numberAsAscii == 50 ) return 93;
	if ( numberAsAscii == 51 ) return 91;
	if ( numberAsAscii == 52 ) return 58;
	if ( numberAsAscii == 53 ) return 107;
	if ( numberAsAscii == 54 ) return 111;
	if ( numberAsAscii == 55 ) return 82;
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
	char bitFields[4];

	sprintf( numberAsString, "%d", number );
	leftpadNumber( numberAsString, 4, paddedNumber );

	for ( char i = 0; i < 4; ++i ) {
		bitFields[i] = getBitField( paddedNumber[i] );
	}

	printNumber( bitFields );
}

int main(int argc, char **argv) {
	showNumber(123);
	showNumber(4567);
	showNumber(8910);
}
