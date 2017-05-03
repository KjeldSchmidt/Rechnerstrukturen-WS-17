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

  //  [Programmtext hier ergaenzen.]

  //  Aktuelles (Zwischen-)Ergebnis.
  long value = 0;

  //  Wandele um.
  
  //  [Programmtext hier ergaenzen.]

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

  //  [Programmtext hier ergaenzen.]

  return b;
}

#include "tests_one-complement.h"

int main(int argc, char **argv) {

  return run_tests();
  
}
