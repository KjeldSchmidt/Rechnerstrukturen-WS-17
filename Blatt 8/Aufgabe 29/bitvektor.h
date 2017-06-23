#ifndef BITVEKTOR_H
#define BITVEKTOR_H

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <iterator>
#include <iostream>

class Bitvektor{

private:

  /* Bool-Array für Wahrheitswerte */
  bool* bits;

  /* Laenge von bits*/
  size_t length;

  /* Wird im Falle eines Fehlers zurück gegeben. Hat die Länge 0*/
  static Bitvektor emptyVector;

  /**
   * Vergleiche die Laenge zweier Bitvektoren.
   *
   * @param b0
   *        Referenz auf den ersten Bitvektor.
   * @param b1
   *        Referenz auf den ersten Bitvektor.
   * @return
   *        true, falls die Vektoren die selbe Laenge besitzen
   */
   bool checkSizes(const Bitvektor& other) const;
public:
  /**
   * Konstruktor für einen Bitvektor der Laenge size
   *
   * @param size
   *        Laenge des Vektors.
   */
  Bitvektor(size_t size);

  /**
   * Berechnet einen neuen Bitvektor der aus bitweiser
   * AND-Operation der beiden Vektoren hervorgeht.
   * Die beiden Bitvektoren müssen die selbe Länge besitzen,
   * andernfalls wird ein Bitvektor der Länge Null zurück gegeben.
   *
   * @param other
   *        der zweite Bitvektor-Operand für die Operation
   * @return
   *        Ergebnis der bitweisen AND-Operation
   */
  Bitvektor calculateAnd(const Bitvektor& other) const;

  /**
   * Berechnet einen neuen Bitvektor der aus bitweiser
   * OR-Operation der beiden Vektoren hervorgeht.
   * Die beiden Bitvektoren müssen die selbe Länge besitzen,
   * andernfalls wird ein Bitvektor der Länge Null zurück gegeben.
   *
   * @param other
   *        der zweite Bitvektor-Operand für die Operation
   * @return
   *        Ergebnis der bitweisen AND-Operation
   */
  Bitvektor calculateOr(const Bitvektor& other) const;

  /**
   * Berechnet einen neuen Bitvektor der aus bitweiser
   * XOR-Operation der beiden Vektoren hervorgeht.
   * Die beiden Bitvektoren müssen die selbe Länge besitzen,
   * andernfalls wird ein Bitvektor der Länge Null zurück gegeben.
   *
   * @param other
   *        der zweite Bitvektor-Operand für die Operation
   * @return
   *        Ergebnis der bitweisen XOR-Operation
   */
  Bitvektor calculateXor(const Bitvektor& other) const;

  /**
   * Berechnet einen neuen Bitvektor der aus bitweiser
   * NOT-Operation des Vektors hervorgeht.
   *
   * @return
   *        Ergebnis der bitweisen NOT-Operation
   */
  Bitvektor calculateNot() const;

  /**
   * Gibt die Länge des Bitvektors zurück
   *
   * @return
   *        Anzahl der Bits im Bitvektor
   */
  size_t getSize() const;

  /**
   * Gibt das Bit des Bitvektors an der übergebenen Stelle zurück
   *
   * @param position
   *        Position des Bits. 0 entspricht dem LSB.
   * @return
   *        Bit an der Position
   */
  bool getBit(size_t position) const;

  /**
   * Setzt das Bit an der Stelle position auf den neuen Wert value
   * Dabei ist die Position 0 die Position des Least-Significant-Bits.
   *
   * @param position
   *        Position des Bits. 0 entspricht dem LSB.
   * @param value
   *        zusetzender Wert an position.
   */
  void setBit(size_t position, bool value);

  /**
   * Vergleiche zwei Bitvektoren. Zwei Vektoren sind
   * genau dann gleich, wenn sie die gleiche Laenge besitzen
   * und in allen Elementen uebereinstimmen.
   *
   * @param b0
   *        Referenz auf den ersten Bitvektor.
   * @param b1
   *        Referenz auf den ersten Bitvektor.
   * @return
   *        Ergebnis des Vergleichs.
   */
  bool allZero() const;

  /**
   * Überprüft ob der Bitvektor nur aus Nullen (false) besteht
   * In diesem und im Fall size==0, wird true zurück gegeben.
   *
   * @return
   *        true, falls der Bitvektor nur Nullen repräsentiert
   *              oder die Länge Null besitzt.
   */
  bool equals(const Bitvektor& other) const;

  /**
   * Gibt den Vektor auf der Standardausgabe in der Form MSB,...,.LSB aus.
   */
  void printOnConsole() const;

  static void checkSizesTest();

};

#endif // BITVEKTOR_H
