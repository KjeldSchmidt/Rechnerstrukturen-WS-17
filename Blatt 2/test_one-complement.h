#ifndef __TEST_ONE_COMPLEMENT
#define __TEST_ONE_COMPLEMENT

#include "boolean.h"
#include "bit_vector.h"
#include "colored_output.h"

/**
 *  Teste die Korrektheit der convert_number-Funktion.
 *
 *  @return
 *          TRUE genau dann, wenn kein Test fehlschlaegt.
 */
int test_to_one_complement() {
  printf("[Teste Umwandlung in  Einer-Komplement-Darstellung] ");

  int tests_ok = TRUE;

  //  Bereite Vergleichs-Vektoren vor.
  bit_vector b;
  b.length = 32;  
  if ((b.bits = (unsigned char*)malloc(sizeof(unsigned char) * b.length)) == NULL) {
    printf("Speicheranforderung fehlgeschlagen.\n");
    return FALSE;
  }

  bit_vector result;
  
  //  Teste Umwandlung fuer  "0".
  //  - Berechne Bitvektor-Darstellung.
  result = convert_number(0);
 
  //  - Initialisiere alle Bits in b mit Nullen.
  memset(b.bits, FALSE, b.length);

  //  - Fuehre Test durch.
  tests_ok = (tests_ok && (compare(&result, &b) == TRUE));
  free(result.bits);
  show_progress(tests_ok);

  //  Teste Umwandlung fuer minimalen Wert.
  //  - Berechne Bitvektor-Darstellung.
  result = convert_number((long)(INT_MIN));

  bit_vector bnull;
  bnull.length = 0;
  bnull.bits   = NULL;
  
  //  - Fuehre Test durch.
  tests_ok = (tests_ok && (compare(&result, &bnull) == TRUE));
  show_progress(tests_ok);

  //  Teste Umwandlung fuer minimal darstellbaren Wert.
  //  - Berechne Bitvektor-Darstellung.
  result = convert_number((long)(INT_MIN + 1));

  //  - Initialisiere alle Bits in b mit Nullen
  memset(b.bits, FALSE, b.length);
  //  - Setze nur das ersten Bit auf 1.
  b.bits[0] = 1;  

  //  - Fuehre Test durch.
  tests_ok = (tests_ok && (compare(&result, &b) == TRUE));
  free(result.bits);
  show_progress(tests_ok);

  //  Teste Umwandlung fuer maximalen Wert.
  //  - Berechne Bitvektor-Darstellung.
  result = convert_number((long)(INT_MAX));
  
  //  - Initialisiere alle Bits in b mit Einsen.
  memset(b.bits, TRUE, b.length);
  //  - Setze nur das ersten Bit auf 0.
  b.bits[0] = 0;

  //  - Fuehre Test durch.
  tests_ok = (tests_ok && (compare(&result, &b) == TRUE));
  free(result.bits);
  show_progress(tests_ok);

  //  Teste Umwandlung fuer "1742" = "0....000011011001110".
  //  - Berechne Bitvektor-Darstellung.
  result = convert_number(1742);
  
  //  - Initialisiere alle Bits in b mit Nullen.
  memset(b.bits, FALSE, b.length);
  //  - Setze die Bits an den Stellen 30, 29, 28, 25, 24, 22, 21.
  b.bits[21] = b.bits[22] = b.bits[24] = b.bits[25] = b.bits[28]
    = b.bits[29] = b.bits[30] = TRUE;

  //  - Fuehre Test durch.
  tests_ok = (tests_ok && (compare(&result, &b) == TRUE));
  free(result.bits);
  show_progress(tests_ok);

  //  Teste Umwandlung fuer "-1742" (invertiert: 1742).
  //  - Berechne Bitvektor-Darstellung.
  result = convert_number(-1742);

  //  - Initialisiere alle Bits in b mit Einsen.
  memset(b.bits, TRUE, b.length);
  //  - Loesche die Bits an den Stellen 30, 29, 28, 25, 24, 22, 21.
  b.bits[21] = b.bits[22] = b.bits[24] = b.bits[25] = b.bits[28]
    = b.bits[29] = b.bits[30] = FALSE;

  //  - Fuehre Test durch.
  tests_ok = (tests_ok && (compare(&result, &b) == TRUE));
  free(result.bits);  
  show_progress(tests_ok);

  free(b.bits);    
  
  //  Ausgabe des Gesamtergebnisses.
  print_test_result(tests_ok);
  
  return tests_ok;
}

/**
 *  Teste die Korrektheit der convert_vector-Funktion.
 *
 *  @return
 *          TRUE genau dann, wenn kein Test fehlschlaegt.
 */
int test_from_one_complement() {
  printf("[Teste Umwandlung aus Einer-Komplement-Darstellung] ");

  int tests_ok = TRUE;

  //  Bereite Test-Vektoren vor.
  bit_vector b;
  b.length = 32;  
  if ((b.bits = (unsigned char*)malloc(sizeof(unsigned char) * b.length)) == NULL) {
    printf("Speicheranforderung fehlgeschlagen.\n");
    return FALSE;
  }

  //  Teste Umwandlung fuer "plus 0".
  //  - Initialisiere alle Bits in b mit Nullen
  memset(b.bits, FALSE, b.length);

  //  - Fuehre Test durch.
  tests_ok = (tests_ok && ((convert_vector(&b) == (long)0)));
  show_progress(tests_ok);

  //  Teste Umwandlung fuer "minus 0".
  //  - Initialisiere alle Bits in b mit Einsen
  memset(b.bits, TRUE, b.length);

  //  - Fuehre Test durch.
  tests_ok = (tests_ok && ((convert_vector(&b) == (long)0)));
  show_progress(tests_ok);

  //  Teste Umwandlung fuer minimalen Wert.
  //  - Initialisiere alle Bits in b mit Nullen
  memset(b.bits, FALSE, b.length);
  //  - Setze nur das ersten Bit auf 1.
  b.bits[0] = 1;  

  //  - Fuehre Test durch.
  tests_ok = (tests_ok && ((convert_vector(&b) == (long)(INT_MIN + 1))));
  show_progress(tests_ok);

  //  Teste Umwandlung fuer maximalen Wert.
  //  - Initialisiere alle Bits in b mit Einsen
  memset(b.bits, TRUE, b.length);
  //  - Setze nur das ersten Bit auf 0.
  b.bits[0] = 0;

  //  - Fuehre Test durch.
  tests_ok = (tests_ok && ((convert_vector(&b) == (long)(INT_MAX))));
  show_progress(tests_ok);

  //  Teste Umwandlung fuer "1742" = "0....000011011001110".
  //  - Initialisiere alle Bits in b mit Nullen
  memset(b.bits, FALSE, b.length);
  //  - Setze die Bits an den Stellen 30, 29, 28, 25, 24, 22, 21.
  b.bits[21] = b.bits[22] = b.bits[24] = b.bits[25] = b.bits[28]
    = b.bits[29] = b.bits[30] = TRUE;

  //  - Fuehre Test durch.
  tests_ok = (tests_ok && ((convert_vector(&b) == 1742)));
  show_progress(tests_ok);

  //  Teste Umwandlung fuer "-1742" (invertiert: 1742).
  //  - Initialisiere alle Bits in b mit Einsen
  memset(b.bits, TRUE, b.length);
  //  - Loesche die Bits an den Stellen 30, 29, 28, 25, 24, 22, 21.
  b.bits[21] = b.bits[22] = b.bits[24] = b.bits[25] = b.bits[28]
    = b.bits[29] = b.bits[30] = FALSE;

  //  - Fuehre Test durch.
  tests_ok = (tests_ok && ((convert_vector(&b) == -1742)));
  show_progress(tests_ok);

  free(b.bits);
    
  //  Ausgabe des Gesamtergebnisses.
  print_test_result(tests_ok);
  
  return tests_ok;
}

#endif
