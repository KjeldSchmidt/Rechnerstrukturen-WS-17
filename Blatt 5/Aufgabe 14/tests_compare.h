#ifndef __TESTS
#define __TESTS

#include "boolean.h"
#include "test_compare.h"

/**
 * Fuehre je eine Menge von Tests fuer die Umwandlung
 * von unaerer Binaerzahlen in Vektordarstellung aus
 *
 * @return
 *         "true" genau dann, wenn beide Mengen
 *         von Tests ohne Fehler durchlaufen.
 */
int run_tests() {

  int tests_ok = TRUE;

  tests_ok = (tests_ok && test_ieee());
  
  return tests_ok;
}

#endif
