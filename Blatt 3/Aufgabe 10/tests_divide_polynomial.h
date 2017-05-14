#ifndef _TESTS
#define _TESTS

#include "boolean.h"
#include "test_polynomial.h"
#include "test_division_result.h"
#include "test_divide_polynomial.h"

/**
 * Fuehre je eine Menge von Tests fuer die 
 * Polynomdivision aus.
 *
 * @return
 *         "true" genau dann, wenn beide Mengen
 *         von Tests ohne Fehler durchlaufen.
 */
int run_tests() {

  int tests_ok = TRUE;

  tests_ok = (tests_ok && test_compare_polynomial());
  tests_ok = (tests_ok && test_compare_division_result());
  tests_ok = (tests_ok && test_divide_polynomial());

  //  Ausgabe des Gesamtergebnisses.
  printf("Gesamtergebnis: ");
  print_test_result(tests_ok);

  return tests_ok;
}

#endif
