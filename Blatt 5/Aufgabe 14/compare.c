/*
 *  Vorlesung "Rechnerstrukturen", Blatt 5, Aufgabe 14.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "boolean.h"
#include "bit_vector.h"
#include "colored_output.h"


//Sie duerfen sich Hilfsfunktionen implementieren

int getCharacteristik( bit_vector *b, int k ) {
  int characteristik = 0;
  for (int i = 0; i < k; ++i ) {
    characteristik += b->bits[i + 1] << k - i;
  }
  return characteristik;
}

int getMantissa( bit_vector *b, int n, int k ) {
  int mantissa = 0;
  for (int i = 0; i < n; ++i ) {
    mantissa += b->bits[i + k + 1] << n - i;
  }
  return mantissa;
}

int isNaN ( bit_vector *b, int k, int n ) {
  char characteristikAllOnes = getCharacteristik( b, k ) == ( 1 << k+1 ) - 2;
  char mantissaNotZero = getMantissa( b, n, k ) != 0;
  return characteristikAllOnes && mantissaNotZero;
}

int compareNormalized( bit_vector *b1, bit_vector *b2, int k, int n ) {
  if ( getCharacteristik(b1, k ) > getCharacteristik( b2, k ) ) {
    return 1;
  } else if ( getCharacteristik(b1, k ) < getCharacteristik( b2, k ) ) {
    return 0;
  } else if ( getCharacteristik(b1, k ) == getCharacteristik( b2, k ) ) {
    if ( getMantissa( b1, n, k ) < getMantissa( b2, n, k ) ) {
      return 1;
    } else if ( getMantissa( b1, n, k ) > getMantissa( b2, n, k ) ) {
      return 0;
    }
  }
  return 0;
}

/**
 *  Die Funktion gibt an, ob der erste der beiden uebergebenen Bitvektoren kleiner als der andere ist
 *  Die Vektoren muessen beide im 1,k,n Format angelehnt an die IEEE-754 vorliegen.
 *  Dabei wird das Ergebnis an der Stelle im Speicher abgelegt, auf den der uebergebenen Zeiger result zeigt
 *  Der Rueckgabewert der Funktion liefert nur eine Information ueber den Erfolg/Fehler der Funktion
 *
 *  @param b1
 *         Zeiger auf einen Vektor im (1,k,n)-Format
 *  @param b2
 *         Zeiger auf einen Vektor im (1,k,n)-Format
 *  @param k
 *         Anzahl an Bits fuer die Characteristik
 *  @param n
 *         Anzahl an Bits fuer die Mantisse
 *  @param result
 *         ist 1 (TRUE) falls b1 kleiner als b2 unter Beruecksichtigung der IEEE-Sonderfaelle
 *  @return
 *         0, falls alle Eingaben gueltig und es keinen Fehler gab
 *         -1, sonst
 */

int lessThanIEEE(bit_vector *b1, bit_vector *b2, int k, int n, int* result) {
  // Comparision with NaN always gives FALSE.
  if ( isNaN( b1, k, n ) || isNaN( b2, k, n ) ) {
    printf("!");
    *result == 0;
    return 0;
  }
  // As a first step, the sign bit is an easy and absolute decider.
  if ( b1->bits[0] == 1 && b2->bits[0] == 1 ) {
    *result = 1;
  } else if ( b1->bits[0] == 0 && b2->bits[0] == 1 ) {
    *result = 0;
  }
  // If that doesn't work, we can check if the Vectors are normalized and, if yes, compare by characteristik.
  *result = compareNormalized( b1, b2, k, n );
  return 0;
}


#include "tests_compare.h"

int main(int argc, char **argv) {

  return run_tests();

}
