/**
 *  Vorlesung "Rechnerstrukturen", Blatt 3, Aufgabe 10.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "boolean.h"
#include "polynomial.h"
#include "division_result.h"
#include "colored_output.h"

/**
 * Fuehre eine Polynomdivision fuer die beiden uebergebenen 
 * Polynome durch.
 * 
 * @param p0 
 *        Zeiger auf das erste Polynom.
 * @param p1 
 *        Zeiger auf das zweite Polynom.
 * @return
 *        Ergebnis der Polynomdivision.
 */
division_result divide_polynomial(polynomial *p0, polynomial *p1) {
  
  division_result result;
  //  Markiere das Resultat zunaechst als ungueltig, um
  //  vorzeitige Rueckspruenge als solche erkennen zu koennen.
  result.quotient = NULL;

  //  Pruefe die Eingaben.
  if ( (!is_valid_polynomial(p0)) ||
       (!is_valid_polynomial(p1))) {
    printf(ANSI_COLOR_MAGENTA "Keine gueltigen Polynome uebergeben.\n" ANSI_COLOR_RESET);
    return result;    
  }

  //  Erzeuge eine Reprasentation fuer den Quotienten.
  polynomial *quotient;
  if ((quotient = (polynomial*)malloc(sizeof(polynomial))) == NULL) {
    printf(ANSI_COLOR_MAGENTA "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    return result;
  }
  result.quotient = quotient;

  //  Es ist zunaechst unklar, ob ein Rest benoetigt wird.
  polynomial *remainder_numerator   = NULL;
  polynomial *remainder_denominator = NULL;

  //  Berechne den Grad des Ergebnispolynoms.
  int degree = abs(p0->degree - p1->degree);
    
  //  Erzeuge einen Quotienten mit Grad mindestens 0,
  //  auch, wenn nur ein Rest berechnet werden muss.
  if (degree >= 0) {
    quotient->degree = (unsigned short)degree;
  }
  else {
    quotient->degree = 0;
  }

  //  Erzeuge Repraesentation des Quotienten.
  if ((quotient->coefficients =
       (float*)malloc(sizeof(float) * (quotient->degree+1))) == NULL) {
    printf(ANSI_COLOR_MAGENTA "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_division_result(&result);  //  Speicherfreigabe.
    return result;
  }    

  /*
    Ggfs. hier Programmtext ergaenzen.
  */

  polynomial *remaining;
  //  Iteriere passend..
  for( int i = p1->degree; i >= 0; --i ) {
    
    //  "Du suchst die groessten Exponenten aus den beiden Polynomen..."
    unsigned short exponentP0 = find_largest_exponent( p0 );
    unsigned short exponentP1 = find_largest_exponent( p1 );

    //  "...dividierst das miteinander..."



    /*
      Hier Programmtext ergaenzen.
    */

    //  "...und schon wuerde es sich lohnen, zurueck zu multiplizieren, ..."

    /*
      Hier Programmtext ergaenzen.
    */

    //  "...denn wenn man jetzt noch subtrahiert,..."
    remainder_numerator = subtract_polynomial( p0, p1 );
    
    /*
      Hier Programmtext ergaenzen.
    */

    //  ...hat man erreicht, dass man die hoechste Potenz verliert."
  }

  //  Stelle fest, ob noch ein Rest existiert.

  /*
    Hier Programmtext ergaenzen.
  */

  //  Falls noch ein Restpolynom existiert...
  int condition = 0; // Bedingung angeben
  if (condition) {

    //  ...erzeuge eine Repraesentation...
    if ((remainder_numerator =
	 (polynomial*)malloc(sizeof(polynomial))) == NULL) {
      printf(ANSI_COLOR_MAGENTA "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
      free_division_result(&result);  //  Speicherfreigabe.
      return result;
    }
    result.remainder_numerator = remainder_numerator;
    remainder_numerator->coefficients = NULL;

    //  ...und kopiere das Restpolynom als Zaehler.

    /*
      Hier Programmtext ergaenzen.
    */

    //  Erzeuge eine Repraesentation fuer den Nenner...
    if ((remainder_denominator =
	 (polynomial*)malloc(sizeof(polynomial))) == NULL) {
      printf(ANSI_COLOR_MAGENTA "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
      free_division_result(&result);  //  Speicherfreigabe.
      return result;
    }
    result.remainder_denominator = remainder_denominator;
    remainder_denominator->coefficients = NULL;

    // ...und kopiere den Nenner.
    copy_polynomial(p1, remainder_denominator, 0, p1->degree);
  }
    
  //  Gggfs. Speicherfreigabe.

  /*
    Hier Programmtext ergaenzen.
  */
  
  //  Setze die Komponenten der Rueckgabestruktur.
  //  Bei einem vorherigen Ruecksprung war das Ergebnis
  //  als ungueltig zu betrachten.

  result.quotient              = quotient;
  result.remainder_numerator   = remainder_numerator;
  result.remainder_denominator = remainder_denominator;

  

  return result;
}

#include "tests_divide_polynomial.h"

int main(int argc, char **argv) {

  return run_tests();
  
}
