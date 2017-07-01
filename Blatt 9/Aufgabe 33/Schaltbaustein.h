#ifndef SCHALTBAUSTEIN_H
#define SCHALTBAUSTEIN_H

#include <memory>
#include <cstdio>  
/**
 * Modellierung eines Schaltbausteins, z.B. AND, OR oder NOT.
 * Der Baustein hat genau einen Ausgang, an dem der berechnete
 * Boolesche Wert anliegt.
 */
class Schaltbaustein; 

class Schaltbaustein {
	protected:
	public:
    /**
     * Auslesen des durch den Schaltbaustein berechneten Werts.
     * @return Berechneter Wert.
     */
    virtual bool eval()=0;
	/**
	 * Gibt die Anzahl der Eingaenge des Schaltbausteins zurueck
	 * @return Anzahl an Eingaengen
	 */
	virtual size_t getInputSize() const=0;
	/**
	 * Verknuepft den Eingang mit der Nummer number mit der Ausgabe des Bausteins input
	 * @param number Zu setzender Eingang
	 * @param input Schaltbaustein dessen Ausgang mit dem Eingang verbunden werden soll.
	 */
	virtual void setInput(size_t number,  std::shared_ptr<Schaltbaustein>  input)=0;
	/**
	 * Gibt den Schaltbaustein zurueck, der mit dem Eingang mit der Nummer number verknuepften ist
	 * @param number Nummer des Eingangs Eingang
	 * @return Schaltbaustein mit dem der Eingang verbunden ist.
	 */
	virtual std::shared_ptr<Schaltbaustein> getInput(size_t number) =0;
};
#endif