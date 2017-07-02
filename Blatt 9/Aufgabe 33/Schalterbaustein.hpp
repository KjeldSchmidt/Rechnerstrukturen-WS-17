#ifndef SCHALTERBAUSTEIN_H
#define SCHALTERBAUSTEIN_H

#include "Schaltbaustein.hpp"
/**
 * Modellierung eines Schaltbausteins, welcher immer einen konstanten Wert zurückliefert. 
 * Verfuegt ueber keinen Eingang, Ausgabe kann nur umgeschaltet werden.
 */
class Schalterbaustein : public Schaltbaustein {
	private:
		bool value;
	public:
		Schalterbaustein();
		void setValue( bool value );
		bool eval();
		size_t getInputSize() const;
		void setInput(size_t number,  std::shared_ptr<Schaltbaustein>  input);
		std::shared_ptr<Schaltbaustein> getInput(size_t number);
};
#endif