#ifndef _DIVISION_RESULT_H
#define _DIVISION_RESULT_H

#include "polynomial.h"

/**
 * Struktur zur Kapselung des Ergebnisses einer Polynomdivision.
 * Es werden Zeiger auf drei Polynome gespeichert: den "ganzzahligen
 * Anteil", den Zaehler des Restes (ggfs. NULL) und den Nenner
 * des Restes (ggfs. NULL). Ein ungueltiges Resultat wird dadurch
 * dargestellt, dass der Quotient NULL ist.
 */
typedef struct {
  polynomial *quotient;
  polynomial *remainder_numerator;
  polynomial *remainder_denominator;
} division_result;

/**
 *  Teste ein Divisionsergebnis auf Gueltigkeit.
 *  
 *  @param result
 *         Zeiger auf das ueberpruefendes Resultat.
 *  @return 
 *         TRUE, falls das uebergebene Resultat sowie 
 *         der dort gekapselte Quotient ungleich NULL sind.
 */
int is_valid_division_result(division_result *result) {
  return ((result != NULL) && (result->quotient != NULL));
}

/**
 *  Gib den Speicher eines Divisionsergebnisses frei.
 *
 *  @param result
 *         Zeiger auf das Divisionsergebnis, dessen
 *         Speicher freigegeben werden soll.
 */
void free_division_result(division_result *result) {

  if (result != NULL) {
  
    if (result->quotient != NULL) {
      free(result->quotient->coefficients);
      free(result->quotient);
      result->quotient = NULL;
    }
    
    if (result->remainder_numerator != NULL) {
      free(result->remainder_numerator->coefficients);
      free(result->remainder_numerator);
      result->remainder_numerator = NULL;
    }
    
    if (result->remainder_denominator != NULL) {
      free(result->remainder_denominator->coefficients);
      free(result->remainder_denominator);
      result->remainder_denominator = NULL;
    }
    
  }
}

/**
 * Vergleiche zwei Divisionsergebnisse. Zwei Divisionsergebnisse
 * sind genau dann gleich, wenn sie in allen repraesentierten
 * Komponenten uebereinstimmen.
 * Es wird davon ausgegangen, dass beide uebergebenen
 * Zeiger auf gueltige und konsistente Strukturen verweisen.
 *
 * @param d0 
 *        Zeiger auf das erste Divisionsergebnis.
 * @param d1 
 *        Zeiger auf das zweite Divisionsergebnis.
 * @return
 *        Ergebnis des Vergleichs.
 */
int compare_division_result(division_result *d0, division_result *d1) {

  /*
    Hier Programmtext ergaenzen.
  */
  
  return FALSE;
  
}

#endif
