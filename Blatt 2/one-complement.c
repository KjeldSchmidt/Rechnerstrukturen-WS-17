/*
 *  Vorlesung "Rechnerstrukturen", Blatt 2, Aufgabe 7.
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
 *  Darstellung um.
 *
 *  @param b
 *         Zeiger auf einen Vektor mit 32 Bits.
 *  @return
 *         long-Darstellung des kodierten Werts.
 */
long convert_vector(bit_vector *b) {

  //  Teste, ob der uebergebene Vektor gueltig ist.

  if ( b == NULL || b->length != 32 ) {
    perror("Invalider Bitvektor");
  }

  //  Aktuelles (Zwischen-)Ergebnis.
  long value = 0;
  unsigned char *position = b->bits;            // Set the pointer position to the first char in the bit array. We need this so we may increment carelessly, which is not possible with b->bits directly.

  //  Wandele um.

  position++;

  for ( int i = 1; i < b->length; ++i ) {       // Simply iterate over the bit array by length (Step 2 and 5 of the informal algorithm)
    value *= 2;                 // It is important to _start_ by multiplying with two, because the last digit should _not_ be doubled. In the first iteration, this simply has no effect ( Step 3 )
    value += *position;                         // Add the current positions value ( Step 4, part 2 ). Note that step 1 is needlessly includes one execution of step 4 - we don't do that.
    position++;                                 // Increment the pointer to the next bit location. ( Step 4, part 1)
  }

  value -= *(b->bits) * INT_MAX;

  return value;
}

/**
 *  Wandle eine Zahl in long-Darstellung in
 *  einen Bit-Vektor um. Der hierbei erzeugte Speicher
 *  muss spaeter separat frei gegeben werden.
 *
 *  @param number
 *         long-Darstellung des zu kodierenden Werts.
 *  @return
 *         Vektor mit 32 Bits.
 */
bit_vector convert_number(long number) {

  //  Erzeuge Rueckgabe-Struktur.
  bit_vector b;

  memset(b.bits, FALSE, b.length);

  return b;
}

#include "tests_one-complement.h"

int main(int argc, char **argv) {

  return run_tests();
  
}
