/*
 *  Vorlesung "Rechnerstrukturen", Blatt 2, Aufgabe 6.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "boolean.h"
#include "bit_vector.h"
#include "colored_output.h"


/**
 *  Wandle einen Bit-Vektor in eine Zahl in long-
 *  Darstellung mittels des Algorithmus aus Aufg-
 *  abe No. 6 um.
 *
 *  @param b
 *         Zeiger auf einen Vektor
 *  @return
 *         long-Darstellung des kodierten Werts.
 */
long convert_vector(bit_vector *b) {

  //  Teste, ob der uebergebene Vektor gueltig ist.

  if ( b == NULL || b->length == 0 ) {
  	perror("Invalider Bitvektor");
  }

  //  Aktuelles (Zwischen-)Ergebnis.
  long value = 0;
  unsigned char *position = b->bits;            // Set the pointer position to the first char in the bit array. We need this so we may increment carelessly, which is not possible with b->bits directly.

  for ( int i = 0; i < b->length; ++i ) {       // Simply iterate over the bit array by length (Step 2 and 5 of the informal algorithm)
  	value *= 2;									// It is important to _start_ by multiplying with two, because the last digit should _not_ be doubled. In the first iteration, this simply has no effect ( Step 3 )
  	value += *position;                         // Add the current positions value ( Step 4, part 2 ). Note that step 1 is needlessly includes one execution of step 4 - we don't do that.
  	position++;                                 // Increment the pointer to the next bit location. ( Step 4, part 1)
  }

  return value;
}

#include "tests_double-dabble.h"

int main(int argc, char **argv) {

  return run_tests();
  
}
