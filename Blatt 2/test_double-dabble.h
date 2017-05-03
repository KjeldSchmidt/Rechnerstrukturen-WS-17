#ifndef __TEST_ONE_COMPLEMENT
#define __TEST_ONE_COMPLEMENT

#include "boolean.h"
#include "bit_vector.h"
#include "colored_output.h"

/**
 *  Teste die Korrektheit der convert_vector-Funktion.
 *
 *  @return
 *          TRUE genau dann, wenn kein Test fehlschlaegt.
 */
int test_from_bitvector() {
  printf("[Teste Umwandlung aus Einer-Komplement-Darstellung] ");

  int tests_ok = TRUE;

  //  Bereite Test-Vektoren vor.
  bit_vector b;
  b.length = 32;  
  if ((b.bits = (unsigned char*)malloc(sizeof(unsigned char) * b.length)) == NULL) {
    printf("Speicheranforderung fehlgeschlagen.\n");
    return FALSE;
  }

  //  Bereite zweiten Test-Vektor vor
  bit_vector b2;
  b2.length = 8;
  if ((b2.bits = (unsigned char*)malloc(sizeof(unsigned char) * b2.length)) == NULL) {
    printf("Speicheranforderung fehlgeschlagen.\n");
    return FALSE;
  }


  //  Bereite dritten Test-Vektor vor
  bit_vector b3;
  b3.length = 1;
  if ((b3.bits = (unsigned char*)malloc(sizeof(unsigned char) * b3.length)) == NULL) {
    printf("Speicheranforderung fehlgeschlagen.\n");
    return FALSE;
  }


  //  Teste Umwandlung fuer "plus 0".
  //  - Initialisiere alle Bits in b mit Nullen
  memset(b.bits, FALSE, b.length);

  //  - Fuehre Test durch.
  tests_ok = (tests_ok && ((convert_vector(&b) == (long)0)));
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

  //  Teste Umwandlung fuer "147" = "10010011".
  //  - Initialisiere alle Bits in b mit Nullen
  memset(b2.bits, FALSE, b2.length);
  //  - Setze die Bits an den Stellen 7,6,3,0.
  b2.bits[0] = b2.bits[3] = b2.bits[6] = b2.bits[7] = TRUE;

  //  - Fuehre Test durch.
  tests_ok = (tests_ok && ((convert_vector(&b2) == 147)));
  show_progress(tests_ok);

  //  Teste Umwandlung fuer "1" = "1".
  //  - Setze die Bits an der Stelle 0
  b3.bits[0] = TRUE;

  //  - Fuehre Test durch.
  tests_ok = (tests_ok && ((convert_vector(&b3) == 1)));
  show_progress(tests_ok);


  free(b3.bits);
  free(b2.bits);
  free(b.bits);
    
  //  Ausgabe des Gesamtergebnis
  print_test_result(tests_ok);
  
  return tests_ok;
}

#endif
