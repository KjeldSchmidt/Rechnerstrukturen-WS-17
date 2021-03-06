/*
 *  Vorlesung "Rechnerstrukturen", Blatt 4, Aufgabe 14.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "boolean.h"
#include "stdint.h"
#include "colored_output.h"
#include "ipaddress.h"


/**
 *  Wandle eine IPv4 Addresse in eine ganzzahlige usigned 32-bit Darstellung um.
 *
 *  @param address
 *         IPv4 Adresse
 *  @return
 *         uint32_t-Darstellung der Adresse.
 */
uint32_t convertAddress(ipv4 address) {
  uint32_t converted = 0;

  converted += address.a << 24;
  converted += address.b << 16;
  converted += address.c << 8;
  converted += address.d;
  return converted;
}

/**
 *  Wandle eine als ganzzahlige usigned 32-bit Darstellung dargestellte IPv4 Addresse in Octalschreibweise um.
 *
 *  @param converted
 *         IPv4 Adresse im uint32_t Format
 *  @return
 *         Octaldarstellung der Adresse als ipv4-Struct.
 */
ipv4 covertFromAddress(uint32_t converted){
	ipv4 address;

  address.a = converted >> 24;
  address.b = converted >> 16;
  address.c = converted >> 8;
  address.d = converted;


	return address;
}

/**
 *  Erzeugt zu einem gegebenen Präfix eine passende IPv4-Subnetzmaske als uint32_t.
 *
 *  @param prefix
 *         Anzahl der Host-Bits in der IP-Adresse. Muss im Bereich 0<=x<=32 sein.
 *  @return
 *         Octaldarstellung der zugehoerigen Subnetz-Adresse im uint32_t Format
 */
uint32_t getSubnetmaskFromPrefix(int prefix){
  uint32_t octalPrefix = 0;
	for ( int i = 0; i < prefix; ++i ) {
    octalPrefix += 1 << 31 - i;
  }
	return octalPrefix;
}

/**
 *  Erzeugt zu einer IPv4-Adresse und einem gegebenen Präfix
 *  die zugehörige IPv4-Network-Adresse als uint32_t.
 *  @param address
 *         IP-Adresse innerhalb des Subnetzes zu der die Netzwerk-Adresse
 *         bestimmt werden soll. Vom Typ uint32_t.
 *
 *  @param prefix
 *         Anzahl der Host-Bits in der IP-Adresse. Muss im Bereich 0<=x<=32 sein.
 *  @return
 *         Octaldarstellung der zugehoerigen Network-Adresse im uint32_t Format
 */
uint32_t getNetwork(uint32_t address, int prefix){
  return address & getSubnetmaskFromPrefix( prefix );
}

/**
 *  Erzeugt zu einer IPv4-Adresse und einem gegebenen Präfix
 *  die zugehörige IPv4-Broadcast-Adresse als uint32_t.
 *  @param address
 *         IP-Adresse innerhalb des Subnetzes zu der die Broadcast-Adresse
 *         bestimmt werden soll. Vom Typ uint32_t.
 *
 *  @param prefix
 *         Anzahl der Host-Bits in der IP-Adresse. Muss im Bereich 0<=x<=32 sein.
 *  @return
 *         Octaldarstellung der zugehoerigen Broadcast-Adresse im uint32_t Format
 */
uint32_t getBroadcast(uint32_t address, int prefix){
    return address | ~getSubnetmaskFromPrefix( prefix );
}

/**
 *  Liefert zu einem gegebenen Präfix die maximale Anzahl an eindeutig adressibaren
 *  Host innerhalb eines IPv4-Subnetzmaske zu gebenen Präfix.
 *
 *  @param prefix
 *         Anzahl der Host-Bits in der IP-Adresse. Muss im Bereich 0<=x<=32 sein.
 *  @return
 *         maximale Anzahl an eindeutig adressierbaren Host innerhalb des Subnetzes
 */
uint32_t getNumberOfHost(int prefix) {
    if ( prefix == 0 ) return 4294967294;
    if ( prefix == 31 ) return 2;
    if ( prefix == 32 ) return 1;
    uint32_t numberOfHosts = (1 << (32 - prefix)) - 2;
    return numberOfHosts;
}

/**
 *  Erzeugt zu einer IPv4-Adresse und einem gegebenen Präfix
 *  die erste gültige IPv4-Host-Adresse als uint32_t.
 *  @param address
 *         IP-Adresse innerhalb des Subnetzes zu der die erste Host-Adresse
 *         bestimmt werden soll. Vom Typ uint32_t.
 *
 *  @param prefix
 *         Anzahl der Host-Bits in der IP-Adresse. Muss im Bereich 0<=x<=32 sein.
 *  @return
 *         erste gueltige Hostadresse im zugehoerigen Subnetz im uint32_t Format
 */
uint32_t getFirst(uint32_t address, int prefix){
    if ( prefix >= 31 ) return address;
    return getNetwork( address, prefix ) + 1;
}


/**
 *  Erzeugt zu einer IPv4-Adresse und einem gegebenen Präfix
 *  die letzte gültige IPv4-Host-Adresse als uint32_t.
 *  @param address
 *         IP-Adresse innerhalb des Subnetzes zu der die letzte Host-Adresse
 *         bestimmt werden soll. Vom Typ uint32_t.
 *
 *  @param prefix
 *         Anzahl der Host-Bits in der IP-Adresse. Muss im Bereich 0<=x<=32 sein.
 *  @return
 *         letzte gueltige Hostadresse im zugehoerigen Subnetz im uint32_t Format
 */
uint32_t getLast(uint32_t address, int prefix){
    if ( prefix >= 31 ) return getBroadcast( address, prefix );
    return getBroadcast( address, prefix ) - 1;
}

/**
 *  Berechnet ob sich zwei Subnetze überlappen. Die Subnetze werden aus den
 *  übergebenen IPv4-Adressen mittels jeweiligen Präfixe bestimmt.
 *  @param ip1
 *         IP-Adresse innerhalb des ersten Subnetzes
 *  @param prefix1
 *         Anzahl der Host-Bits in der ersten IP-Adresse. Muss im Bereich 0<=x<=32 sein.
 *  @param ip2
 *         IP-Adresse innerhalb des zweiten Subnetzes
 *  @param prefix1
 *         Anzahl der Host-Bits in der zweiten IP-Adresse. Muss im Bereich 0<=x<=32 sein.
 *  @return
 *         TRUE, falls die Subnetze sich überlappen oder sogar enthalten, FALSE sonst.
 */
int doIntersect(uint32_t ip1, int prefix1, uint32_t ip2, int prefix2)
{
    if ( getBroadcast( ip1, prefix1 ) >= getNetwork( ip2, prefix2 ) && getNetwork( ip1, prefix1 ) <= getBroadcast( ip2, prefix2 ) ) return 1;
    if ( getBroadcast( ip2, prefix2 ) >= getNetwork( ip1, prefix1 ) && getNetwork( ip2, prefix2 ) <= getBroadcast( ip1, prefix1 ) ) return 1;
    return 0;
}

#include "tests_network.h"

int main(int argc, char **argv) {
   return run_tests();
}
