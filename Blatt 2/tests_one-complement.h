#ifndef __TESTS
#define __TESTS

#include "boolean.h"
#include "test_bit_vector.h"
#include "test_one-complement.h"

/**
 * Fuehre je eine Menge von Tests fuer die Umwandlung
 * in Einer-Komplement-Darstellung und fuer die 
 * Umwandlung aus Einer-Komplement-Darstellung aus.
 *
 * @return
 *         "true" genau dann, wenn beide Mengen
 *         von Tests ohne Fehler durchlaufen.
 */
int run_tests() {

  int tests_ok = TRUE;

  tests_ok = (tests_ok && test_compare());
  tests_ok = (tests_ok && test_from_one_complement());
  tests_ok = (tests_ok && test_to_one_complement());

  //  Ausgabe des Gesamtergebnisses.
  printf("Gesamtergebnis: ");
  print_test_result(tests_ok);

  return tests_ok;
}

#endif
