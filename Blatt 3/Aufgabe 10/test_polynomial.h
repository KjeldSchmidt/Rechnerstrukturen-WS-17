#ifndef _TEST_POLYNOMIAL
#define _TEST_POLYNOMIAL

#include "boolean.h"
#include "polynomial.h"
#include "colored_output.h"

/**
 *  Teste die Korrektheit der compare_polynomial-Funktion.
 *
 *  @return
 *          TRUE genau dann, wenn kein Test fehlschlaegt.
 */
unsigned char test_compare_polynomial() {

  printf("[Teste compare_polynomial-Funktion] ");
  
  unsigned char tests_ok = TRUE;

  //  Bereite Test-Polynome vor.
  polynomial p0;
  p0.degree = 4;  
  if ((p0.coefficients = (float*)malloc(sizeof(float) * (p0.degree+1))) == NULL) {
    printf(ANSI_COLOR_MAGENTA "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    return FALSE;
  }

  polynomial p1;
  p1.degree = 3;  
  if ((p1.coefficients = (float*)malloc(sizeof(float) * (p1.degree+1))) == NULL) {
    printf(ANSI_COLOR_MAGENTA "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    return FALSE;
  }

  polynomial p2;
  p2.degree = 4;  
  if ((p2.coefficients = (float*)malloc(sizeof(float) * (p2.degree+1))) == NULL) {
    printf(ANSI_COLOR_MAGENTA "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    return FALSE;
  }

  polynomial p3;
  p3.degree = 4;  
  if ((p3.coefficients = (float*)malloc(sizeof(float) * (p3.degree+1))) == NULL) {
    printf(ANSI_COLOR_MAGENTA "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    return FALSE;
  }

  //  Teste compare_polynomial(NULL, NULL);
  tests_ok = (tests_ok &&
	      ((compare_polynomial((polynomial*)NULL, (polynomial*)NULL) == TRUE)));
  show_progress(tests_ok);
  
  //  Teste compare_polynomial(NULL, non-NULL);
  tests_ok = (tests_ok &&
	      ((compare_polynomial((polynomial*)NULL, &p0) == FALSE)));
  show_progress(tests_ok);

  //  Teste compare_polynomial(non-NULL, NULL);
  tests_ok = (tests_ok &&
	      ((compare_polynomial(&p1, (polynomial*)NULL) == FALSE)));
  show_progress(tests_ok);

  //  Teste compare_polynomial(*,*) mit unterschiedlicher Laenge.
  tests_ok = (tests_ok &&
	      ((compare_polynomial(&p0, &p1) == FALSE)));
  show_progress(tests_ok);

  //  Teste compare_polynomial(*,*) mit gleicher Laenge aber
  //  unterschiedlichem erstem Koeffizienten.
  p0.coefficients[0] = 7;
  p0.coefficients[1] = 4;
  p0.coefficients[2] = 2;
  p0.coefficients[3] = 1;
  p0.coefficients[4] = 2;

  p2.coefficients[0] = 7;
  p2.coefficients[1] = 4;
  p2.coefficients[2] = 2;
  p2.coefficients[3] = 1;
  p2.coefficients[4] = 3;

  tests_ok = (tests_ok &&
	      ((compare_polynomial(&p0, &p2) == FALSE)));

  //  Teste compare_polynomial(*,*) mit gleicher Laenge und identischen Coefficients.
  p3.coefficients[0] = 7;
  p3.coefficients[1] = 4;
  p3.coefficients[2] = 2;
  p3.coefficients[3] = 1;
  p3.coefficients[4] = 2;

  tests_ok = (tests_ok &&
	      ((compare_polynomial(&p0, &p3) == TRUE)));

  //  Gib den angeforderten Speicher wieder frei.
  free(p3.coefficients);
  free(p2.coefficients);
  free(p1.coefficients);
  free(p0.coefficients);

  //  Ausgabe des Gesamtergebnisses.
  print_test_result(tests_ok);
  
  return tests_ok;
}

#endif
