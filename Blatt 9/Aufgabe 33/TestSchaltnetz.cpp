#include "AndBaustein.h"
#include "OrBaustein.h"
#include "NotBaustein.h"
#include "Schaltnetz.h"	
#include <iostream>

    int main() {

    Schaltnetz meinNetz = *(new Schaltnetz());

	/*
	  Erzeuge einen OR-Baustein.
	  Erzeuge einen AND-Baustein.
	  Verbinde den x-Eingang des OR-Bausteins mit dem Ausgang des AND-Bausteins.
	  Verbinde den y-Eingang des OR-Bausteins mit dem y-Eingang des Schaltnetzes.
	  Verbinde den x-Eingang des AND-Bausteins mit dem x-Eingang des Schaltnetzes.
	  Verbinde den y-Eingang des AND-Bausteins mit dem y-Eingang des Schaltnetzes.
	  Verbinde des Ausgang des Schaltnetzes mit dem Ausgang des OR-Bausteins.
	*/
	

	std::cout << "(true ,true ) -> " << meinNetz.eval(true,true) << 
			   " (sollte true sein)" << std::endl;
	std::cout << "(true ,false) -> " << meinNetz.eval(true,false) << 
			   " (sollte false sein)" << std::endl;
	std::cout << "(false,false) -> " << meinNetz.eval(false,false)  << 
			   " (sollte false sein)" << std::endl;
	std::cout << "(false,true ) -> " << meinNetz.eval(false,true) << 
			   " (sollte true sein)" << std::endl; 
	
	/* 
	  Erzeuge einen NOT-Baustein.
	  Verbinde den Eingang des NOT-Bausteins mit dem Ausgang des OR-Bausteins.
	  Verbinde des Ausgang des Schaltnetzes mit dem Ausgang des NOT-Bausteins.
	*/
	
	

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

 
