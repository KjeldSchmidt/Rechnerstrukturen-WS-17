#ifndef __BITVECTOR
#define __BITVECTOR

#include "boolean.h"

// Struktur zur "Kapselung" von Bit-Vektoren.
// Hinweis: Da C keinen Datentypen "bit" hat,
// wird ein Element vom Typ "char" genutzt,
// um ein(!) Bit zu repraesentieren. Dieses
// Element speichert entweder den Wert 0 oder
// den Wert 1.
typedef struct {
  unsigned short length;
  unsigned char *bits;
} bit_vector;

/**
 * Vergleiche zwei Bit-Vektoren. Zwei Vektoren sind 
 * genau dann gleich, wenn sie beide entweder NULL sind
 * oder beide verschieden von NULL sind und Vektoren der
 * gleichen Laenge repraesentieren, die in allen Elementen
 * uebereinstimmen. 
 * Es wird davon ausgegangen, dass beide uebergebenen
 * Zeiger auf gueltige und konsistente Strukturen verweisen.
 *
 * @param b0 
 *        Zeiger auf den ersten Bit-Vektor.
 * @param b1 
 *        Zeiger auf den ersten Bit-Vektor.
 * @return
 *        Ergebnis des Vergleichs.
 */
int compare(bit_vector *b0, bit_vector *b1) {

  //  Teste zunaechst alle Sonderfaelle.
  
  //  Sind beide Vektoren NULL, so sind beide
  //  Vektoren gleich.
  if ((b0 == NULL) && (b1 == NULL)) {
    return TRUE;
  }

  //  Ist nur einer der Vektoren NULL, so sind
  //  die Vektoren nicht gleich.
  if (b0 == NULL || b1 == NULL) {
    return FALSE;
  }

  //  Haben die Vektoren unterschiedliche Laengen,
  //  so sind sie nicht gleich.
  if (b0->length != b1->length) {
    return FALSE;
  }

  int value = TRUE;

  //  Die Vektoren haben gleiche Laenge, vergleiche
  //  also die Elemente an allen Stellen.
  
  for (int i = 0; i < b0->length; i++) {
    value = (value && (b0->bits[i] == b1->bits[i]));
  }

  return value;
  
}

#endif
