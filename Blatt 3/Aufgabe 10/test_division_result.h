#ifndef _TEST_DIVISION_RESULT
#define _TEST_DIVISION_RESULT

#include "boolean.h"
#include "division_result.h"
#include "colored_output.h"

/**
 *  Teste die Korrektheit der compare_division_result-Funktion.
 *
 *  @return
 *          TRUE genau dann, wenn kein Test fehlschlaegt.
 */
unsigned char test_compare_division_result() {

  printf("[Teste compare_division_result-Funktion] ");
  
  unsigned char tests_ok = TRUE;

  //  Bereite Test-Polynome vor.
  polynomial p0;
  p0.degree = 4;  
  if ((p0.coefficients = (float*)malloc(sizeof(float) * (p0.degree+1))) == NULL) {
    printf(ANSI_COLOR_MAGENTA "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    return FALSE;
  }

  p0.coefficients[0] = 1;
  p0.coefficients[1] = 2;
  p0.coefficients[2] = 3;
  p0.coefficients[3] = 4;
  p0.coefficients[4] = 5;

  polynomial p1;
  p1.degree = 3;  
  if ((p1.coefficients = (float*)malloc(sizeof(float) * (p1.degree+1))) == NULL) {
    printf(ANSI_COLOR_MAGENTA "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    return FALSE;
  }
  p1.coefficients[0] = 21;
  p1.coefficients[1] = 23;
  p1.coefficients[2] = 43;
  p1.coefficients[3] = 44;

  polynomial p2;
  p2.degree = 4;  
  if ((p2.coefficients = (float*)malloc(sizeof(float) * (p2.degree+1))) == NULL) {
    printf(ANSI_COLOR_MAGENTA "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    return FALSE;
  }

  p2.coefficients[0] = 1;
  p2.coefficients[1] = 0;
  p2.coefficients[2] = 30;
  p2.coefficients[3] = 0;
  p2.coefficients[4] = 5;
  
  polynomial p3;
  p3.degree = 4;  
  if ((p3.coefficients = (float*)malloc(sizeof(float) * (p3.degree+1))) == NULL) {
    printf(ANSI_COLOR_MAGENTA "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    return FALSE;
  }

  p3.coefficients[0] = 1;
  p3.coefficients[1] = 2;
  p3.coefficients[2] = 3;
  p3.coefficients[3] = 4;
  p3.coefficients[4] = 5;

  //  Teste compare_division_result(NULL, NULL);
  tests_ok = (tests_ok &&
	      ((compare_division_result((division_result*)NULL, (division_result*)NULL) == TRUE)));
  show_progress(tests_ok);

  division_result d0;
  d0.quotient              = &p0;
  d0.remainder_numerator   = &p2;
  d0.remainder_denominator = &p0;
  
  //  Teste compare_division_result(NULL, non-NULL);
  tests_ok = (tests_ok &&
	      ((compare_division_result((division_result*)NULL, &d0) == FALSE)));
  show_progress(tests_ok);

  division_result d1;
  d1.quotient              = &p0;
  d1.remainder_numerator   = &p1;
  d1.remainder_denominator = &p0;

  //  Teste compare_division_result(non-NULL, NULL);
  tests_ok = (tests_ok &&
	      ((compare_division_result(&d1, (division_result*)NULL) == FALSE)));
  show_progress(tests_ok);

  //  Teste compare_division_result(*,*) mit unterschiedlicher Laenge.
  tests_ok = (tests_ok &&
	      ((compare_division_result(&d0, &d1) == FALSE)));
  show_progress(tests_ok);

  division_result d2;
  d2.quotient              = &p0;
  d2.remainder_numerator   = &p3;
  d2.remainder_denominator = &p0;

  //  Teste compare_division_result(*,*) mit gleicher Laenge aber
  //  unterschiedlichem erstem Koeffizienten.

  tests_ok = (tests_ok &&
	      ((compare_division_result(&d0, &d2) == FALSE)));
  show_progress(tests_ok);

  division_result d3;
  d3.quotient              = &p0;
  d3.remainder_numerator   = &p2;
  d3.remainder_denominator = &p0;

  //  Teste compare_division_result(*,*) mit gleicher Laenge und identischen Coefficients.
  tests_ok = (tests_ok &&
	      ((compare_division_result(&d0, &d3) == TRUE)));
  show_progress(tests_ok);

  division_result d4;
  d4.quotient              = &p0;
  d4.remainder_numerator   = NULL;
  d4.remainder_denominator = NULL;

  //  Teste compare_division_result(*,*) mit nur einem Rest.
  tests_ok = (tests_ok &&
	      ((compare_division_result(&d0, &d4) == FALSE)));
  show_progress(tests_ok);
  
  division_result d5;
  d5.quotient              = &p0;
  d5.remainder_numerator   = NULL;
  d5.remainder_denominator = NULL;

  //  Teste compare_division_result(*,*) ohne Rest.
  tests_ok = (tests_ok &&
	      ((compare_division_result(&d5, &d4) == TRUE)));
  show_progress(tests_ok);

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
