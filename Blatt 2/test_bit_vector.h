#ifndef __TEST_BITVECTOR
#define __TEST_BITVECTOR

#include "boolean.h"
#include "bit_vector.h"
#include "colored_output.h"

/**
 *  Teste die Korrektheit der compare-Funktion.
 *
 *  @return
 *          TRUE genau dann, wenn kein Test fehlschlaegt.
 */
int test_compare() {

  printf("[Teste compare-Funktion] ");
  
  int tests_ok = TRUE;

  //  Bereite Test-Vektoren vor.
  bit_vector b0;
  b0.length = 4;  
  if ((b0.bits = (unsigned char*)malloc(sizeof(unsigned char) * b0.length)) == NULL) {
    printf("Speicheranforderung fehlgeschlagen.\n");
    return FALSE;
  }

  bit_vector b1;
  b1.length = 3;  
  if ((b1.bits = (unsigned char*)malloc(sizeof(unsigned char) * b1.length)) == NULL) {
    printf("Speicheranforderung fehlgeschlagen.\n");
    return FALSE;
  }

  bit_vector b2;
  b2.length = 4;  
  if ((b2.bits = (unsigned char*)malloc(sizeof(unsigned char) * b2.length)) == NULL) {
    printf("Speicheranforderung fehlgeschlagen.\n");
    return FALSE;
  }

  bit_vector b3;
  b3.length = 4;  
  if ((b3.bits = (unsigned char*)malloc(sizeof(unsigned char) * b3.length)) == NULL) {
    printf("Speicheranforderung fehlgeschlagen.\n");
    return FALSE;
  }

  //  Teste compare(NULL, NULL);
  tests_ok = (tests_ok &&
	      ((compare((bit_vector*)NULL, (bit_vector*)NULL) == TRUE)));
  show_progress(tests_ok);
  
  //  Teste compare(NULL, non-NULL);
  tests_ok = (tests_ok &&
	      ((compare((bit_vector*)NULL, &b0) == FALSE)));
  show_progress(tests_ok);

  //  Teste compare(non-NULL, NULL);
  tests_ok = (tests_ok &&
	      ((compare(&b1, (bit_vector*)NULL) == FALSE)));
  show_progress(tests_ok);

  //  Teste compare(*,*) mit unterschiedlicher Laenge.
  tests_ok = (tests_ok &&
	      ((compare(&b0, &b1) == FALSE)));
  show_progress(tests_ok);

  //  Teste compare(*,*) mit gleicher Laenge aber unterschiedlichem letzen Bit.
  b0.bits[0] = 0;
  b0.bits[1] = 1;
  b0.bits[2] = 1;
  b0.bits[3] = 0;

  b2.bits[0] = 0;
  b2.bits[1] = 1;
  b2.bits[2] = 1;
  b2.bits[3] = 1;

  tests_ok = (tests_ok &&
	      ((compare(&b0, &b2) == FALSE)));

  //  Teste compare(*,*) mit gleicher Laenge und identischen Bits.
  b3.bits[0] = 0;
  b3.bits[1] = 1;
  b3.bits[2] = 1;
  b3.bits[3] = 0;

  tests_ok = (tests_ok &&
	      ((compare(&b0, &b3) == TRUE)));

  //  Gib den angeforderten Speicher wieder frei.
  free(b3.bits);
  free(b2.bits);
  free(b1.bits);
  free(b0.bits);

  //  Ausgabe des Gesamtergebnisses.
  print_test_result(tests_ok);
  
  return tests_ok;
}

#endif
