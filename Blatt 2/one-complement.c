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

  //  Initilize struct to return
  bit_vector b;

  // The smallest number encodeable by one's complement is (long)INT_MIN + 1. So the minimum value of long has to be rejected.
  // Desired values for output have been copied from the tests.
  if ( number == (long) INT_MIN ) {
    b.length = 0;
    b.bits = NULL;
    return b;
  }

  // In all other cases, we can construct a valid, 32-bit vector. Attempt to allocate memory and set it to 0.
  b.length = 32;
  if ( (b.bits = (unsigned char*) malloc( sizeof(unsigned char) * 32) ) == NULL ) {
    perror("Speicheranforderung fehlgeschlagen.\n");
  }
  memset(b.bits, FALSE, b.length);

  // First, check the parity. If the number is negative, the first bit has to be 0.
  if ( number < 0 ) {
    b.bits[0] = 1;
  }
  // One's complement has the nice property that flipping all bits gives the negative of the number. 
  // So we work with the absolute value and then flip each bit based on bits[0]. labs is just abs for long.
  number = labs(number); 


  // At each bit position, we compare to the value of that bit position. Since we know that longs here are 32 bit, we hardcode that information.
  // bitValue starts as 2^30. If you wonder why its not 31 or 32, just think about it. It'll come to you.
  long bitValue = (long) INT_MAX/2 + 1;

  for ( int i = 1; i < 32; ++i ) {
    if ( number >= bitValue ) {      // if the number is greater than the value of this bit, we need this bit to be set.
      number -= bitValue;            // remaining number to encode
      b.bits[i] = !b.bits[0];        // flip based on wether the number is positive or negative
    } else {
      b.bits[i] = b.bits[0];
    }

    bitValue = bitValue / 2;         // the next bit is only worth half as much.
  }

  return b;
}

#include "tests_one-complement.h"

int main(int argc, char **argv) {

  return run_tests();
  
}
