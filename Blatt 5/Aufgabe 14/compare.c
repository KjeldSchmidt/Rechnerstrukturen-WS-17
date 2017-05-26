/*
 *  Vorlesung "Rechnerstrukturen", Blatt 5, Aufgabe 14.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "boolean.h"
#include "bit_vector.h"
#include "colored_output.h"


//Sie duerfen sich Hilfsfunktionen implementieren

/**
 *  Die Funktion gibt an, ob der erste der beiden uebergebenen Bitvektoren kleiner als der andere ist
 *  Die Vektoren muessen beide im 1,k,n Format angelehnt an die IEEE-754 vorliegen.
 *  Dabei wird das Ergebnis an der Stelle im Speicher abgelegt, auf den der uebergebenen Zeiger result zeigt
 *  Der Rueckgabewert der Funktion liefert nur eine Information ueber den Erfolg/Fehler der Funktion
 *
 *  @param b1
 *         Zeiger auf einen Vektor im (1,k,n)-Format
 *  @param b2
 *         Zeiger auf einen Vektor im (1,k,n)-Format
 *  @param k
 *         Anzahl an Bits fuer die Characteristik
 *  @param n
 *         Anzahl an Bits fuer die Mantisse
 *  @param result
 *         ist 1 (TRUE) falls b1 kleiner als b2 unter Beruecksichtigung der IEEE-Sonderfaelle
 *  @return
 *         0, falls alle Eingaben gueltig und es keinen Fehler gab
 *         -1, sonst
 */
int lessThanIEEE(bit_vector *b1, bit_vector *b2, int k, int n, int* result) {
   //Hier bitte implementieren
   return OK;
}


#include "tests_compare.h"

int main(int argc, char **argv) {

  return run_tests();
  
}
