#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H

#include "boolean.h"
#include "colored_output.h"

/**
 * Struktur zur "Kapselung" von Polynomen.
 * Achtung: Ein Polynom vom Grad d wird durch
 * (d+1) Koeffizienten dargestellt.
 * Ein ungueltiges Resultat wird dadurch
 * dargestellt, dass die Koeffizienten NULL sind.
 */
typedef struct {
  unsigned short degree;  
  float *coefficients;
} polynomial;

/**
 *  Teste ein Polynom auf Gueltigkeit.
 *  
 *  @param result
 *         Zeiger auf das ueberpruefendes Polynom.
 *  @return 
 *         TRUE, falls das uebergebene Polynom sowie 
 *         der dort gekapselten Koeffizienten ungleich NULL sind.
 */
int is_valid_polynomial(polynomial *p) {
  return ((p != NULL) && (p->coefficients != NULL));
}

void free_polynomial( polynomial *p ) {
  if ( p != NULL ) {
    if ( p->coefficients != NULL ) free( p-> coefficients );
    free( p );
  } 
}


/**
 *  Gib ein Polynom auf dem Bildschirm aus.
 *
 *  @param p
 *         Zeiger auf das auszugebene Polynom. 
 */
void print_polynomial(polynomial *p) {
  if (is_valid_polynomial(p)) {
    printf("\n Grad: %d, Koeffizienten: ", p->degree);
    for (int i= p->degree; i>=0; i--) {
      printf("%f ", p->coefficients[i]);
    }
    printf("\n");
  }
  else {
    printf(ANSI_COLOR_RED "Ungueltiges Polynom uebergeben.\n" ANSI_COLOR_RESET);
  }
}

int find_largest_exponent(polynomial *p) {
  for ( int i = p->degree; i > 0; --i ) {
    if ( p->coefficients[i] != 0 ) return i;
  }
  return 0;
}

polynomial *subtract_polynomial( polynomial *p0, polynomial *p1 ) {
  if ( !is_valid_polynomial(p0) || !is_valid_polynomial(p1) ) {
    return NULL;
  }

  polynomial difference;
  int possible_degree = ( p0->degree > p1->degree ) ? p0->degree : p1->degree;

  if ( (difference.coefficients = (float*) malloc( sizeof(float) * (possible_degree+1)) ) == NULL ) {
    printf(ANSI_COLOR_MAGENTA "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_polynomial( &difference );  //  Speicherfreigabe.
    return NULL;
  }

  for ( int i = 0; i <= possible_degree; ++i ) {
    difference.coefficients[i] = p0->coefficients[i] - p1->coefficients[i];
    if ( difference.coefficients[i] != 0 ) {
      difference.degree = i;
    }
  }

  return &difference;
}

polynomial *multiply_polynomial( polynomial *p0, polynomial *p1 ) {
  if ( !is_valid_polynomial(p0) || !is_valid_polynomial(p1) ) {
    return NULL;
  }

  polynomial product;
  product.degree = p0->degree * p1->degree;

  if ((product.coefficients = ( float* ) malloc( sizeof(float) * (product.degree+1))) == NULL) {
    printf(ANSI_COLOR_MAGENTA "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
    free_polynomial( &product );  //  Speicherfreigabe.
    return NULL;
  }

  for ( int i = 0; i <= p0->degree; ++i ) {
    for ( int j = 0; i <= p1->degree; ++i ) {
      product.coefficients[ i + j ] += p0->coefficients[i] * p1->coefficients[j];
    }
  }

  return &product;
}

/**
 * Hilfsfunktion zum Kopieren eines (Teil-)Polynoms. Die
 * Koeffizienten [start...end] des Quell-Polynoms werden
 * als Koeffizienten [0...degree] des Ziel-Polynoms verwendet.
 * Der fuer die Koeffizienten des Ziel-Polynoms zuvor belegte 
 * Speicher wird freigegeben.
 * 
 * @param from
 *        Zeiger auf das zu kopierenden Polynom.
 * @param to
 *        Zeiger auf das Ziel-Polynom.
 * @param start
 *        Erster zu kopierenden Koeffizient.
 * @param end
 *        Letzter zu kopierenden Koeffizient.
 */
int copy_polynomial(polynomial *from, polynomial *to, unsigned short start, unsigned short end) {

  //  Ueberpruefe die Eingabe.
  if (is_valid_polynomial(from)) {

    //  Ueberpruefe den zu kopierenden Bereich.
    if ((start > end) || (end > from->degree)) {
      printf(ANSI_COLOR_RED "Ungueltige Indizes uebergeben.\n" ANSI_COLOR_RESET);
      return FALSE;
    }

    //  Gib zuvor belegte Speicher frei.
    free(to->coefficients);

    //  Bestimme den Grad des resultierenden Polynoms.
    to->degree = end-start;

    //  Erzeuge das Koeffizienten-Feld.
    if ((to->coefficients =
	 (float*)malloc(sizeof(float) * (to->degree+1))) == NULL) {
      printf(ANSI_COLOR_MAGENTA "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
      to->degree = 0;
      return FALSE;
    }

    //  Kopiere die Koeffizienten.
    int j = 0;
    for (int i=start; i <= end; i++) {
      to->coefficients[j] = from->coefficients[i];
      j = j+1;
    }
    
  }
  else {
    printf(ANSI_COLOR_RED "Ungueltiges Quell-Polynom uebergeben.\n" ANSI_COLOR_RESET);
    return FALSE;
  }

  return TRUE;   
}

/**
 * Vergleiche zwei Polynomen. Zwei Polynome sind 
 * genau dann gleich, wenn sie beide entweder NULL sind
 * oder beide verschieden von NULL sind und Polynome vom
 * gleichen Grad repraesentieren, die in allen Koeffizienten
 * uebereinstimmen. Die Feinheit, dass ein Polynom vom
 * Grad d auch einen Koeffizienten d haben muss, der ungleich
 * 0 ist, wird hier nicht betrachtet.
 * Es wird davon ausgegangen, dass beide uebergebenen
 * Zeiger auf gueltige und konsistente Strukturen verweisen.
 *
 * @param p0 
 *        Zeiger auf das erste Polynom.
 * @param p1 
 *        Zeiger auf das zweite Polynom.
 * @return
 *        Ergebnis des Vergleichs.
 */
int compare_polynomial(polynomial *p0, polynomial *p1) {

  //  Teste zunaechst alle Sonderfaelle.
  
  //  Sind beide Polynome NULL, so sind beide
  //  Polynome gleich.
  if ((p0 == NULL) && (p1 == NULL)) {
    return TRUE;
  }

  //  Ist nur eines der Polynome NULL oder mindestens eines
  //  der Polynome ungueltig, so sind die Polynome nicht gleich.
  if (!(is_valid_polynomial(p0)) || !(is_valid_polynomial(p1))) {
    return FALSE;
  }

  //  Sind die Polynome von unterschiedlichem Grad,
  //  so sind sie nicht gleich.
  if (p0->degree != p1->degree) {
    return FALSE;
  }

  int value = TRUE;

  //  Die Polynome haben gleichen Grad, vergleiche
  //  also die Koeffiziente an allen Stellen.  
  for (int i = 0; i <= p0->degree; i++) {
    value = (value && (p0->coefficients[i] == p1->coefficients[i]));
  }

  return value;
  
}

#endif
