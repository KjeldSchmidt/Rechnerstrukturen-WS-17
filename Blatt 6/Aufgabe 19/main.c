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

void showNumber(unsigned int number) {
  char numberAsString[4];
  sprintf( numberAsString, "%d", number );
}

int main(int argc, char **argv) {
  showNumber(123);
  showNumber(4567);
  showNumber(8910);
}
