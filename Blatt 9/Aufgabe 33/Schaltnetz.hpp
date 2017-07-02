#ifndef SCHALTNETZ_H
#define SCHALTNETZ_H
#include <memory>

#include "Schalterbaustein.hpp"
#include "Schaltbaustein.hpp"
#include "OrBaustein.hpp"
#include "AndBaustein.hpp"
#include "NotBaustein.hpp"
/**
 * Modellierung eines Schaltnetzes mit zwei Eingaengen (X und Y),
 * an denen jeweils Boolesche Werte anliegen koennen. Das Schaltnetz
 * hat genau einen Ausgang, der dem Ausgang eines Schaltbausteins
 * entspricht.
 */
class Schaltnetz{

private:
    // Schaltbaustein, dessen Ausgabe der Ausgabe des
    // Schaltnetzes entspricht.
    std::shared_ptr<Schaltbaustein> output;
	std::shared_ptr<Schalterbaustein> s1, s2; 
public:
	/**
     * Konstrukor. Setzt die Eingaenge per default auf Schalterbausteine
     */
	Schaltnetz();
	
	/**
     * Setzt den Ausgabebaustein des Schaltnetzes
     * @param baustein Schaltbaustein, dessen Ausgabe mit der Ausgabe des Schaltnetzes verbunden werden soll.
     */
	void setOutput(std::shared_ptr<Schaltbaustein> baustein);
	
	 /**
     * Liefert den Schaltbaustein zurueck, mit dem die Eingabe X verknuepft ist
     * @return Verknuepfter Schaltbaustein
     */
	std::shared_ptr<Schaltbaustein> getInputX();
	 /**
     * Liefert den Schaltbaustein zurueck, mit dem die Eingabe Y verknuepft ist
     * @return Verknuepfter Schaltbaustein
     */
	std::shared_ptr<Schaltbaustein> getInputY();
    /**
     * Setzt die Eingabe am Eingang X des Schaltnetzes.
     * @param value Neuer Wert fuer den Eingang X des Schaltnetzes
     */
    void setValueX(bool value);
    
    /**
     * Setzt die Eingabe am Eingang Y des Schaltnetzes.
     * @param value Neuer Wert fuer den Eingang Y des Schaltnetzes
     */
    void setValueY(bool value);
    
    /**
     * Wertet das Schaltnetz fuer die aktuell an den 
     * Eingaengen X und Y anliegenden Booleschen Werte aus.
     * @return Ergebnis der Auswertung.
     */
    bool eval();

    /**
     * Wertet das Schaltnetz aus, wobei angenommen wird, dass
     * die als Parameter uebergebenen Booleschen Werte an den 
     * Eingaengen X und Y anliegen.
     * @param x Boolescher Wert, der am Eingang X anliegt.
     * @param y Boolescher Wert, der am Eingang Y anliegt.
     * @return Ergebnis der Auswertung.
     */
    bool eval(bool x, bool y);

};
#endif