#ifndef __TESTS
#define __TESTS

#include "boolean.h"
#include "test_network.h"

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

  tests_ok = (tests_ok && test_fromIPv4());
  tests_ok = (tests_ok && test_fromUint32t());
  tests_ok = (tests_ok && test_prefix());
  tests_ok = (tests_ok && test_network());
  tests_ok = (tests_ok && test_broadcast());
  tests_ok = (tests_ok && test_numberOfHosts());
  tests_ok = (tests_ok && test_getFirst());
  tests_ok = (tests_ok && test_getLast());  
  tests_ok = (tests_ok && test_intersection());  
  
  
  
  
  

  //  Ausgabe des Gesamtergebnisses.
  printf("Gesamtergebnis: ");
  print_test_result(tests_ok);

  return tests_ok;
}

#endif
