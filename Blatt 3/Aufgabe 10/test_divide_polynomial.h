#ifndef _TEST_DIVIDE_POLYNOMIAL
#define _TEST_DIVIDE_POLYNOMIAL

#include "boolean.h"
#include "division_result.h"
#include "colored_output.h"

/**
 *  Vereinfachte Speicherfreigabe der in den Tests
 *  genutzten Konstrukte. Die Uebergabe von NULL 
 *  ist zulaessig.
 *
 *  @param p0
 *         Zeiger auf eine Polynomstruktur, deren
 *         Koeffizientenfeld freigegeben werden soll.
 *  @param p1
 *         Zeiger auf eine Polynomstruktur, deren
 *         Koeffizientenfeld freigegeben werden soll.
 *  @param expect
 *         Zeiger auf eine Divisionsergebnis, dessen
 *         zugehoeriger Speicher freigegeben werden soll.
 *  @param result
 *         Zeiger auf eine Divisionsergebnis, dessen
 *         zugehoeriger Speicher freigegeben werden soll.
 */
void free_test_data(polynomial *p0, polynomial *p1, division_result *expect, division_result *result) {

  if (is_valid_division_result(result)) {
    free_division_result(result);
  }

  if (is_valid_division_result(expect)) {
    free_division_result(expect);
  }

  if (is_valid_polynomial(p1)) { 	
    free(p1->coefficients);
  }
  
  if (is_valid_polynomial(p0)) { 
    free(p0->coefficients);
  }
}

/**
 * Fuehre einen Test der Polynomdivision durch.
 * Situation: Es gibt nur einen Rest, keinen Quotienten.
 *
 * @return 
 *         TRUE genau dann, wenn der Test nicht fehlgeschlagen ist.
 */
unsigned char test_divide_polynomial_one() {

  division_result expect;
  expect.quotient = NULL;
  expect.remainder_numerator = NULL;
  expect.remainder_denominator = NULL;

  // -------------------------------------------------------
  //  Bereite Test-Polynome vor.
  // -------------------------------------------------------

  polynomial p0;
  p0.degree = 3;  
  if ((p0.coefficients = (float*)malloc(sizeof(float) * (p0.degree+1))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(NULL, NULL, NULL, NULL); // For completeness only.
    return FALSE;
  }

  p0.coefficients[3] = 4;
  p0.coefficients[2] = 3;
  p0.coefficients[1] = 2;
  p0.coefficients[0] = 1;

  // -------------------------------------------------------

  polynomial p1;
  p1.degree = 4;  
  if ((p1.coefficients = (float*)malloc(sizeof(float) * (p1.degree+1))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(&p0, NULL, NULL, NULL);  //  Speicherfreigabe.
    return FALSE;
  }

  p1.coefficients[4] = 5;
  p1.coefficients[3] = 4;
  p1.coefficients[2] = 3;
  p1.coefficients[1] = 2;
  p1.coefficients[0] = 1;

  // -------------------------------------------------------
  //  Bereite erwartetes Ergebnis vor.
  // -------------------------------------------------------

  polynomial *quotient;
  if ((quotient = (polynomial*)malloc(sizeof(polynomial))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(&p0, &p1, NULL, NULL);  //  Speicherfreigabe.
    return FALSE;
  }
  expect.quotient = quotient;
  quotient->degree = 0;

  if ((quotient->coefficients = (float*)malloc(sizeof(float) * (quotient->degree+1))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(&p0, &p1, &expect, NULL);  //  Speicherfreigabe.
    return FALSE;
  }

  quotient->coefficients[0] = 0;

  // -------------------------------------------------------

  polynomial *remainder_numerator;
  if ((remainder_numerator = (polynomial*)malloc(sizeof(polynomial))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(&p0, &p1, &expect, NULL);  //  Speicherfreigabe.
    return FALSE;
  }
  remainder_numerator->coefficients = NULL;  // Vermeide Freigabe nicht-allozierten Speichers.
  expect.remainder_numerator = remainder_numerator;

  copy_polynomial(&p0, remainder_numerator, 0, p0.degree);

  // -------------------------------------------------------

  polynomial *remainder_denominator;
  if ((remainder_denominator = (polynomial*)malloc(sizeof(polynomial))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(&p0, &p1, &expect, NULL);  //  Speicherfreigabe.
    return FALSE;
  }
  remainder_denominator->coefficients = NULL;  // Vermeide Freigabe nicht-allozierten Speichers.
  expect.remainder_denominator = remainder_denominator;

  copy_polynomial(&p1, remainder_denominator, 0, p1.degree);

  // -------------------------------------------------------
  // Fuehre die Polynomdivision durch.
  // -------------------------------------------------------
  
  division_result result = divide_polynomial(&p0, &p1);
  
  // -------------------------------------------------------
  // Vergleiche das erwartete und das berechnete Ergebnis.
  // -------------------------------------------------------

  int tests_ok = (compare_division_result(&expect, &result) == TRUE);
  show_progress(tests_ok);
  
  // -------------------------------------------------------
  //  Gib den angeforderten Speicher wieder frei.
  // -------------------------------------------------------
  
  free_test_data(&p0, &p1, &expect, &result); 

  return tests_ok;  

}

/**
 * Fuehre einen Test der Polynomdivision durch.
 * Situation: Es gibt nur einen ganzzahligen Quotienten.
 *
 * @return 
 *         TRUE genau dann, wenn der Test nicht fehlgeschlagen ist.
 */
unsigned char test_divide_polynomial_two() {

  division_result expect;
  expect.quotient = NULL;
  expect.remainder_numerator = NULL;
  expect.remainder_denominator = NULL;

  // -------------------------------------------------------
  //  Bereite Test-Polynome vor.
  // -------------------------------------------------------

  polynomial p0;
  p0.degree = 2;  
  if ((p0.coefficients = (float*)malloc(sizeof(float) * (p0.degree+1))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(NULL, NULL, NULL, NULL); // For completeness only.
    return FALSE;
  }

  p0.coefficients[2] = 21;
  p0.coefficients[1] = 24;
  p0.coefficients[0] = 0;

  // -------------------------------------------------------

  polynomial p1;
  p1.degree = 2;  
  if ((p1.coefficients = (float*)malloc(sizeof(float) * (p1.degree+1))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(&p0, NULL, NULL, NULL);  //  Speicherfreigabe.
    return FALSE;
  }

  p1.coefficients[2] = 7;
  p1.coefficients[1] = 8;
  p1.coefficients[0] = 0;

  // -------------------------------------------------------

  polynomial *quotient;
  if ((quotient = (polynomial*)malloc(sizeof(polynomial))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(&p0, &p1, NULL, NULL);  //  Speicherfreigabe.
    return FALSE;
  }
  expect.quotient = quotient;
  quotient->degree = 0;

  if ((quotient->coefficients = (float*)malloc(sizeof(float) * (quotient->degree+1))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(&p0, &p1, &expect, NULL);  //  Speicherfreigabe.
    return FALSE;
  }

  quotient->coefficients[0] = 3;
  
  // -------------------------------------------------------
  // Fuehre die Polynomdivision durch.
  // -------------------------------------------------------
  
  division_result result = divide_polynomial(&p0, &p1);
  
  // -------------------------------------------------------
  // Vergleiche das erwartete und das berechnete Ergebnis.
  // -------------------------------------------------------

  int tests_ok = (compare_division_result(&expect, &result) == TRUE);
  show_progress(tests_ok);
  
  // -------------------------------------------------------
  //  Gib den angeforderten Speicher wieder frei.
  // -------------------------------------------------------
  
  free_test_data(&p0, &p1, &expect, &result); 

  return tests_ok;  
  
}

/**
 * Fuehre einen Test der Polynomdivision durch.
 * Situation: Es gibt nur einen polynomiellen Quotienten.
 *
 * @return 
 *         TRUE genau dann, wenn der Test nicht fehlgeschlagen ist.
 */
unsigned char test_divide_polynomial_three() {

  division_result expect;
  expect.quotient = NULL;
  expect.remainder_numerator = NULL;
  expect.remainder_denominator = NULL;

  // -------------------------------------------------------
  //  Bereite Test-Polynome vor.
  // -------------------------------------------------------

  polynomial p0;
  p0.degree = 2;  
  if ((p0.coefficients = (float*)malloc(sizeof(float) * (p0.degree+1))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(NULL, NULL, NULL, NULL); // For completeness only.
    return FALSE;
  }

  p0.coefficients[2] = 2;
  p0.coefficients[1] = 7;
  p0.coefficients[0] = 3;

  // -------------------------------------------------------

  polynomial p1;
  p1.degree = 1;  
  if ((p1.coefficients = (float*)malloc(sizeof(float) * (p1.degree+1))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(&p0, NULL, NULL, NULL);  //  Speicherfreigabe.
    return FALSE;
  }

  p1.coefficients[1] = 1;
  p1.coefficients[0] = 3;

  // -------------------------------------------------------
  //  Bereite erwartetes Ergebnis vor.
  // -------------------------------------------------------

  polynomial *quotient;
  if ((quotient = (polynomial*)malloc(sizeof(polynomial))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(&p0, &p1, NULL, NULL);  //  Speicherfreigabe.
    return FALSE;
  }
  expect.quotient = quotient;
  quotient->degree = 1;

  if ((quotient->coefficients = (float*)malloc(sizeof(float) * (quotient->degree+1))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(&p0, &p1, &expect, NULL);  //  Speicherfreigabe.
    return FALSE;
  }

  quotient->coefficients[1] = 2;
  quotient->coefficients[0] = 1;
  
  // -------------------------------------------------------
  // Fuehre die Polynomdivision durch.
  // -------------------------------------------------------
  
  division_result result = divide_polynomial(&p0, &p1);
  
  // -------------------------------------------------------
  // Vergleiche das erwartete und das berechnete Ergebnis.
  // -------------------------------------------------------

  int tests_ok = (compare_division_result(&expect, &result) == TRUE);
  show_progress(tests_ok);
  
  // -------------------------------------------------------
  //  Gib den angeforderten Speicher wieder frei.
  // -------------------------------------------------------
  
  free_test_data(&p0, &p1, &expect, &result); 

  return tests_ok;  

}

/**
 * Fuehre einen Test der Polynomdivision durch.
 * Situation: Es gibt einen polynomiellen Quotienten und einen Rest.
 *
 * @return 
 *         TRUE genau dann, wenn der Test nicht fehlgeschlagen ist.
 */
unsigned char test_divide_polynomial_four() {

  division_result expect;
  expect.quotient = NULL;
  expect.remainder_numerator = NULL;
  expect.remainder_denominator = NULL;

  // -------------------------------------------------------
  //  Bereite Test-Polynome vor.
  // -------------------------------------------------------

  polynomial p0;
  p0.degree = 3;  
  if ((p0.coefficients = (float*)malloc(sizeof(float) * (p0.degree+1))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(NULL, NULL, NULL, NULL); // For completeness only.
    return FALSE;
  }

  p0.coefficients[3] =   1;
  p0.coefficients[2] =   0;
  p0.coefficients[1] =   2;
  p0.coefficients[0] = -12;

  // -------------------------------------------------------

  polynomial p1;
  p1.degree = 2;  
  if ((p1.coefficients = (float*)malloc(sizeof(float) * (p1.degree+1))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(&p0, NULL, NULL, NULL);  //  Speicherfreigabe.
    return FALSE;
  }

  p1.coefficients[2] = 1;
  p1.coefficients[1] = 0;
  p1.coefficients[0] = 1;

  // -------------------------------------------------------
  //  Bereite erwartetes Ergebnis vor.
  // -------------------------------------------------------

  polynomial *quotient;
  if ((quotient = (polynomial*)malloc(sizeof(polynomial))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(&p0, &p1, NULL, NULL);  //  Speicherfreigabe.
    return FALSE;
  }
  expect.quotient = quotient;
  quotient->degree = 1;

  if ((quotient->coefficients = (float*)malloc(sizeof(float) * (quotient->degree+1))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(&p0, &p1, &expect, NULL);  //  Speicherfreigabe.
    return FALSE;
  }

  quotient->coefficients[1] = 1;
  quotient->coefficients[0] = 0;
  
  // -------------------------------------------------------

  polynomial *remainder_numerator;
  if ((remainder_numerator = (polynomial*)malloc(sizeof(polynomial))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(&p0, &p1, &expect, NULL);  //  Speicherfreigabe.
    return FALSE;
  }
  expect.remainder_numerator = remainder_numerator;
  remainder_numerator->degree = 1;
  
  if ((remainder_numerator->coefficients = (float*)malloc(sizeof(float) * (remainder_numerator->degree+1))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(&p0, &p1, &expect, NULL);  //  Speicherfreigabe.
    return FALSE;
  }

  remainder_numerator->coefficients[1] =   1;
  remainder_numerator->coefficients[0] = -12;

  // -------------------------------------------------------

  polynomial *remainder_denominator;
  if ((remainder_denominator = (polynomial*)malloc(sizeof(polynomial))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(&p0, &p1, &expect, NULL);  //  Speicherfreigabe.
    return FALSE;
  }
  remainder_denominator->coefficients = NULL;  // Vermeide Freigabe nicht-allozierten Speichers.
  expect.remainder_denominator = remainder_denominator;
  
  copy_polynomial(&p1, remainder_denominator, 0, p1.degree);

  // -------------------------------------------------------
  // Fuehre die Polynomdivision durch.
  // -------------------------------------------------------
  
  division_result result = divide_polynomial(&p0, &p1);
  
  // -------------------------------------------------------
  // Vergleiche das erwartete und das berechnete Ergebnis.
  // -------------------------------------------------------

  int tests_ok = (compare_division_result(&expect, &result) == TRUE);
  show_progress(tests_ok);
  
  // -------------------------------------------------------
  //  Gib den angeforderten Speicher wieder frei.
  // -------------------------------------------------------
  
  free_test_data(&p0, &p1, &expect, &result); 

  return tests_ok;  

}

/**
 * Fuehre einen Test der Polynomdivision durch.
 * Situation: Es gibt nur einen polynomiellen Quotienten.
 *
 * @return 
 *         TRUE genau dann, wenn der Test nicht fehlgeschlagen ist.
 */
unsigned char test_divide_polynomial_five() {

  division_result expect;
  expect.quotient = NULL;
  expect.remainder_numerator = NULL;
  expect.remainder_denominator = NULL;

  // -------------------------------------------------------
  //  Bereite Test-Polynome vor.
  // -------------------------------------------------------

  polynomial p0;
  p0.degree = 4;  
  if ((p0.coefficients = (float*)malloc(sizeof(float) * (p0.degree+1))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(NULL, NULL, NULL, NULL); // For completeness only.
    return FALSE;
  }

  p0.coefficients[4] =  1;
  p0.coefficients[3] =  0;
  p0.coefficients[2] = -7;
  p0.coefficients[1] =  4;
  p0.coefficients[0] = -6;

  // -------------------------------------------------------

  polynomial p1;
  p1.degree = 1;  
  if ((p1.coefficients = (float*)malloc(sizeof(float) * (p1.degree+1))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(&p0, NULL, NULL, NULL);  //  Speicherfreigabe.
    return FALSE;
  }

  p1.coefficients[1] = 1;
  p1.coefficients[0] = 3;

  // -------------------------------------------------------
  //  Bereite erwartetes Ergebnis vor.
  // -------------------------------------------------------

  polynomial *quotient;
  if ((quotient = (polynomial*)malloc(sizeof(polynomial))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(&p0, &p1, NULL, NULL);  //  Speicherfreigabe.
    return FALSE;
  }
  expect.quotient = quotient;
  quotient->degree = 3;

  if ((quotient->coefficients = (float*)malloc(sizeof(float) * (quotient->degree+1))) == NULL) {
    printf(ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_test_data(&p0, &p1, &expect, NULL);  //  Speicherfreigabe.
    return FALSE;
  }

  quotient->coefficients[3] =  1;
  quotient->coefficients[2] = -3;
  quotient->coefficients[1] =  2;
  quotient->coefficients[0] = -2;
  
  // -------------------------------------------------------
  // Fuehre die Polynomdivision durch.
  // -------------------------------------------------------
  
  division_result result = divide_polynomial(&p0, &p1);
  
  // -------------------------------------------------------
  // Vergleiche das erwartete und das berechnete Ergebnis.
  // -------------------------------------------------------

  int tests_ok = (compare_division_result(&expect, &result) == TRUE);
  show_progress(tests_ok);
  
  // -------------------------------------------------------
  //  Gib den angeforderten Speicher wieder frei.
  // -------------------------------------------------------
  
  free_test_data(&p0, &p1, &expect, &result); 

  return tests_ok;  

}

/**
 *  Teste die Korrektheit der divide-polynomial-Funktion.
 *
 *  @return
 *          TRUE genau dann, wenn kein Test fehlschlaegt.
 */
unsigned char test_divide_polynomial() {

  printf("[Teste divide_polynomial-Funktion] ");
  
  unsigned char tests_ok = TRUE;

  //  Teste Division nur mit Rest.
  tests_ok = (tests_ok && test_divide_polynomial_one());
  //  Teste Division mit ganzzahligem Quotienten.
  tests_ok = (tests_ok && test_divide_polynomial_two());

  //  Die naechsten drei Tests sind genau die Beispiele aus
  //  "Polynomdivision (Mathe-Song)"
  //  https://www.youtube.com/watch?v=K8K4_gowb4E 
  //  von Johann Beurich (DorFuchs)
  tests_ok = (tests_ok && test_divide_polynomial_three());
  tests_ok = (tests_ok && test_divide_polynomial_four());
  tests_ok = (tests_ok && test_divide_polynomial_five());
  
  //  Ausgabe des Gesamtergebnisses.
  print_test_result(tests_ok);
  
  return tests_ok;
}

#endif
