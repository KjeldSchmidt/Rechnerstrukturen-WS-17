#include "AndBaustein.hpp"
#include "OrBaustein.hpp"
#include "NotBaustein.hpp"
#include "Schalterbaustein.hpp"
#include "Schaltnetz.hpp"
#include <iostream>

/*
 *	In dieser Datei wurden keine interessanten Designentscheidungen getroffen. 
 *	Die geforderten codefunktionen wurden 1:1 aus den Kommentaren übertragen.
 */

int main() {

    Schaltnetz meinNetz = *(new Schaltnetz());

	
	//Erzeuge einen OR-Baustein.
	std::shared_ptr<OrBaustein> orGate( new OrBaustein() );
	//Erzeuge einen AND-Baustein.
	std::shared_ptr<AndBaustein> andGate( new AndBaustein() );
	//Verbinde den x-Eingang des OR-Bausteins mit dem Ausgang des AND-Bausteins.
	orGate->setInput(0, andGate );
	//Verbinde den y-Eingang des OR-Bausteins mit dem y-Eingang des Schaltnetzes.
	orGate->setInput(1, meinNetz.getInputY() );
	//Verbinde den x-Eingang des AND-Bausteins mit dem x-Eingang des Schaltnetzes.
	andGate->setInput(0, meinNetz.getInputX() );
	//Verbinde den y-Eingang des AND-Bausteins mit dem y-Eingang des Schaltnetzes.
	andGate->setInput(1, meinNetz.getInputY() );
	//Verbinde des Ausgang des Schaltnetzes mit dem Ausgang des OR-Bausteins.
	meinNetz.setOutput( orGate );
	
	

	std::cout << "(true ,true ) -> " << meinNetz.eval(true,true) << 
			   " (sollte true sein)" << std::endl;
	std::cout << "(true ,false) -> " << meinNetz.eval(true,false) << 
			   " (sollte false sein)" << std::endl;
	std::cout << "(false,false) -> " << meinNetz.eval(false,false)  << 
			   " (sollte false sein)" << std::endl;
	std::cout << "(false,true ) -> " << meinNetz.eval(false,true) << 
			   " (sollte true sein)" << std::endl; 
	
	 
	//Erzeuge einen NOT-Baustein.
	std::shared_ptr<NotBaustein> notGate( new NotBaustein() );
	//Verbinde den Eingang des NOT-Bausteins mit dem Ausgang des OR-Bausteins.
	notGate->setInput( 0, orGate );
	//Verbinde des Ausgang des Schaltnetzes mit dem Ausgang des NOT-Bausteins.
	meinNetz.setOutput( notGate );
	
	
	

	std::cout << "Mit invertierter Ausgabe:"<<std::endl;

	std::cout << "(true ,true ) -> " << meinNetz.eval(true,true) << 
			   " (sollte false sein)" << std::endl;
	std::cout << "(true ,false) -> " << meinNetz.eval(true,false) << 
			   " (sollte true sein)" << std::endl;
	std::cout << "(false,false) -> " << meinNetz.eval(false,false)  << 
			   " (sollte true sein)" << std::endl;
	std::cout << "(false,true ) -> " << meinNetz.eval(false,true) << 
			   " (sollte false sein)" << std::endl; 
	return 0;
    }

 
