#ifndef __TEST_ONE_COMPLEMENT
#define __TEST_ONE_COMPLEMENT

#include "boolean.h"
#include "colored_output.h"

/**
 *  Teste die Korrektheit der convert_vector-Funktion.
 *
 *  @return
 *          TRUE genau dann, wenn kein Test fehlschlaegt.
 */
int test_fromIPv4() {
  printf("[Teste Umwandlung aus ipv4] ");

  int tests_ok = TRUE;
  
  ipv4 address1=toAddress(192,168,0,222);  
  ipv4 address2=toAddress(0,0,0,1);
  ipv4 address3=toAddress(255,255,255,0);

  uint32_t temp1 = convertAddress(address1);
  uint32_t temp2 = convertAddress(address2);
  uint32_t temp3 = convertAddress(address3);
  
  //  - Fuehre Test durch.
  tests_ok = (tests_ok & show_progress((temp1 == 0xC0A800DEu)));
  
  tests_ok = (tests_ok & show_progress((temp2 == 0x00000001u)));
  
  tests_ok = (tests_ok & show_progress((temp3 == 0xFFFFFF00u)));
    
  //  Ausgabe des Gesamtergebnis
  print_test_result(tests_ok);
  
  return tests_ok;
}


/**
 *  Teste die Korrektheit der convert_vector-Funktion.
 *
 *  @return
 *          TRUE genau dann, wenn kein Test fehlschlaegt.
 */
int test_fromUint32t() {
  printf("[Teste Umwandlung zu ipv4] ");

   
  
  int tests_ok = TRUE;
  uint32_t number1=0xC0A800DEu, number2= 0x00000001u, number3= 0xFFFFFF00u;

  ipv4 address1=toAddress(192,168,0,222);  
  ipv4 address2=toAddress(0,0,0,1);
  ipv4 address3=toAddress(255,255,255,0);
  
  ipv4 temp1 = covertFromAddress(number1);
  ipv4 temp2 = covertFromAddress(number2);
  ipv4 temp3 = covertFromAddress(number3);
  
  //  - Fuehre Test durch.
  tests_ok = ( tests_ok & show_progress(compare(temp1,address1)));
  
  tests_ok = (  tests_ok & show_progress(compare(temp2,address2)));
  
  tests_ok = (  tests_ok & show_progress(compare(temp3,address3)));
    
  //  Ausgabe des Gesamtergebnis
  print_test_result(tests_ok);
  
  return tests_ok;
}



/**
 *  Teste die Korrektheit der convert_vector-Funktion.
 *
 *  @return
 *          TRUE genau dann, wenn kein Test fehlschlaegt.
 */
int test_prefix() {
  printf("[Teste Subnetzerstellung aus Praefix] ");

   
  
  int tests_ok = TRUE;
  
  uint32_t temp1 = getSubnetmaskFromPrefix(32);
  uint32_t temp2 = getSubnetmaskFromPrefix(31);
  uint32_t temp3 = getSubnetmaskFromPrefix(24);
  uint32_t temp4 = getSubnetmaskFromPrefix(8);
  uint32_t temp5 = getSubnetmaskFromPrefix(1);
  uint32_t temp6 = getSubnetmaskFromPrefix(0);
  
  uint32_t subnet1=0xFFFFFFFFu, subnet2=0xFFFFFFFEu, subnet3=0xFFFFFF00, subnet4=0xFF000000u, subnet5=0x80000000u, subnet6=0x00000000u;
  
  //  - Fuehre Test durch.
  tests_ok = show_progress( temp1 == subnet1);
  
   tests_ok = (tests_ok & show_progress(temp2==subnet2));
  
    tests_ok = (tests_ok & show_progress(temp3==subnet3));
  
    tests_ok = (tests_ok & show_progress(temp4==subnet4));
  
    tests_ok = (tests_ok & show_progress(temp5==subnet5));
  
    tests_ok = (tests_ok & show_progress(temp6==subnet6));
        
  //  Ausgabe des Gesamtergebnis
  print_test_result(tests_ok);
  
  return tests_ok;
}

int test_network() {
  printf("[Teste Network-Address aus IP und Praefix] ");

  
  
  int tests_ok = TRUE;
  
  uint32_t subnet1=0xFFFFFFFFu, subnet2=0xFFFFFFFEu, subnet3=0xFFFFFF00, subnet4=0xFF000000u, subnet5=0x80000000u, subnet6=0x00000000u;
  uint32_t ip1=0x01020304u, ip2=0xC0A80001u, ip3=0x0A000001u, ip4=0xC0A80002u, ip5=0xC0A80201u;
  uint32_t temp10 = getNetwork(subnet1,32);
  
  uint32_t temp20 = getNetwork(subnet2,31);
  uint32_t temp21 = getNetwork(ip1,31);
  uint32_t gtru21 = 0x01020304u;
  uint32_t temp22 = getNetwork(ip2,31);
  uint32_t gtru22 = 0xC0A80000u;
  
  uint32_t temp30 = getNetwork(subnet3,24);
  uint32_t temp31 = getNetwork(ip1,24);
  uint32_t gtru31 = 0x01020300u;
  uint32_t temp32 = getNetwork(ip2,24);
  uint32_t gtru32 = 0xC0A80000u;
  uint32_t temp33 = getNetwork(ip3,24);
  uint32_t gtru33 = 0x0A000000u;
  
  uint32_t temp40 = getNetwork(subnet4,8);
  uint32_t temp42 = getNetwork(ip2,8);
  uint32_t gtru42 = 0xC0000000u;
  uint32_t temp43 = getNetwork(ip3,8);
  uint32_t gtru43 = 0x0A000000u;
  uint32_t temp44 = getNetwork(ip4,8);
  uint32_t gtru44 = 0xC0000000u;
  
  uint32_t temp50 = getNetwork(subnet5,1);
  uint32_t temp54 = getNetwork(ip4,1);
  uint32_t gtru54 = 0x80000000u;
  uint32_t temp55 = getNetwork(ip5,1);
  uint32_t gtru55 = gtru54;
  
  uint32_t temp60 = getNetwork(subnet6,0);
  uint32_t temp61 = getNetwork(ip1,0);
  uint32_t gtru61 = 0x00000000u;
  uint32_t temp64 = getNetwork(ip4,0);
  uint32_t gtru64 = gtru61;
  uint32_t temp65 = getNetwork(ip5,0);
  uint32_t gtru65 = gtru61;
  
  
  
  //  - Fuehre Test durch.
  tests_ok = show_progress( temp10 == subnet1);
  
 
  tests_ok = (tests_ok & show_progress(temp20==subnet2));
  tests_ok = (tests_ok & show_progress(temp21==gtru21));
  tests_ok = (tests_ok & show_progress(temp22==gtru22));
  

  tests_ok = (tests_ok & show_progress(temp30==subnet3));
  tests_ok = (tests_ok & show_progress(temp31==gtru31));
  tests_ok = (tests_ok & show_progress(temp32==gtru32));
  tests_ok = (tests_ok & show_progress(temp33==gtru33));
  
  tests_ok = (tests_ok & show_progress(temp40==subnet4));
  tests_ok = (tests_ok & show_progress(temp42==gtru42));
  tests_ok = (tests_ok & show_progress(temp43==gtru43));
  tests_ok = (tests_ok & show_progress(temp44==gtru44));
  
  tests_ok = (tests_ok & show_progress(temp50==subnet5));
  tests_ok = (tests_ok & show_progress(temp54==gtru54));
  tests_ok = (tests_ok & show_progress(temp55==gtru55));
  
  tests_ok = (tests_ok & show_progress(temp60==subnet6));
  tests_ok = (tests_ok & show_progress(temp61==gtru61));
  tests_ok = (tests_ok & show_progress(temp64==gtru64));
  tests_ok = (tests_ok & show_progress(temp65==gtru65));
  
    
  //  Ausgabe des Gesamtergebnis
  print_test_result(tests_ok);
  
  return tests_ok;
}


int test_broadcast() {
  printf("[Teste Broadcast-Address aus IP und Praefix] ");

  
  
  int tests_ok = TRUE;
  
  uint32_t subnet1=0xFFFFFFFFu, subnet2=0xFFFFFFFEu, subnet3=0xFFFFFF00, subnet4=0xFF000000u, subnet5=0x80000000u, subnet6=0x00000000u;
  uint32_t ip1=0x01020304u, ip2=0xC0A80001u, ip3=0x0A000001u, ip4=0xC0A80002u, ip5=0xC0A80201u;
  uint32_t temp10 = getBroadcast(subnet1,32);
  
  uint32_t temp20 = getBroadcast(subnet2,31);
  uint32_t gtru20 = 0xFFFFFFFFu;
  uint32_t temp21 = getBroadcast(ip1,31);
  uint32_t gtru21 = 0x01020305u;
  uint32_t temp22 = getBroadcast(ip2,31);
  uint32_t gtru22 = 0xC0A80001u;
  
  uint32_t temp30 = getBroadcast(subnet3,24);
  uint32_t gtru30 = 0xFFFFFFFFu;
  uint32_t temp31 = getBroadcast(ip1,24);
  uint32_t gtru31 = 0x010203FFu;
  uint32_t temp32 = getBroadcast(ip2,24);
  uint32_t gtru32 = 0xC0A800FFu;
  uint32_t temp33 = getBroadcast(ip3,24);
  uint32_t gtru33 = 0x0A0000FFu;
  
  uint32_t temp40 = getBroadcast(subnet4,8);
  uint32_t gtru40 = 0xFFFFFFFFu;
  uint32_t temp42 = getBroadcast(ip2,8);
  uint32_t gtru42 = 0xC0FFFFFFu;
  uint32_t temp43 = getBroadcast(ip3,8);
  uint32_t gtru43 = 0x0AFFFFFFu;
  uint32_t temp44 = getBroadcast(ip4,8);
  uint32_t gtru44 = 0xC0FFFFFFu;
  
  uint32_t temp50 = getBroadcast(subnet5,1);
  uint32_t gtru50 = 0xFFFFFFFFu;
  uint32_t temp54 = getBroadcast(ip4,1);
  uint32_t gtru54 = gtru50;
  uint32_t temp55 = getBroadcast(ip5,1);
  uint32_t gtru55 = gtru54;
  
  uint32_t temp60 = getBroadcast(subnet6,0);
  uint32_t gtru60 = 0xFFFFFFFFu;
  uint32_t temp61 = getBroadcast(ip1,0);
  uint32_t gtru61 = gtru60;
  uint32_t temp64 = getBroadcast(ip4,0);
  uint32_t gtru64 = gtru61;
  uint32_t temp65 = getBroadcast(ip5,0);
  uint32_t gtru65 = gtru61;
  
  
  
  //  - Fuehre Test durch.
  tests_ok = show_progress(temp10 == subnet1);
  

  tests_ok = (tests_ok & show_progress(temp20==gtru20));
  tests_ok = (tests_ok & show_progress(temp21==gtru21));
  tests_ok = (tests_ok & show_progress(temp22==gtru22));
  

  tests_ok = (tests_ok & show_progress(temp30==gtru30));
  tests_ok = (tests_ok & show_progress(temp31==gtru31));
  tests_ok = (tests_ok & show_progress(temp32==gtru32));
  tests_ok = (tests_ok & show_progress(temp33==gtru33));
  
  tests_ok = (tests_ok & show_progress(temp40==gtru40));
  tests_ok = (tests_ok & show_progress(temp42==gtru42));
  tests_ok = (tests_ok & show_progress(temp43==gtru43));
  tests_ok = (tests_ok & show_progress(temp44==gtru44));

  tests_ok = (tests_ok & show_progress(temp50==gtru50));
  tests_ok = (tests_ok & show_progress(temp54==gtru54));
  tests_ok = (tests_ok & show_progress(temp55==gtru55));
  
  tests_ok = (tests_ok & show_progress(temp60==gtru60));
  tests_ok = (tests_ok & show_progress(temp61==gtru61));
  tests_ok = (tests_ok & show_progress(temp64==gtru64));
  tests_ok = (tests_ok & show_progress(temp65==gtru65));
  
    
  //  Ausgabe des Gesamtergebnis
  print_test_result(tests_ok);
  
  return tests_ok;
}


int test_numberOfHosts() {
  printf("[Teste Anzahl Hosts zu gegebenen Praefix] ");   
  
  int tests_ok = TRUE;
  
  //uint32_t temp0 = getNumberOfHost(33);
  uint32_t temp1 = getNumberOfHost(32);
  uint32_t temp2 = getNumberOfHost(31);
  uint32_t temp3 = getNumberOfHost(24);
  uint32_t temp4 = getNumberOfHost(8);
  uint32_t temp5 = getNumberOfHost(1);
  uint32_t temp6 = getNumberOfHost(0);
  //uint32_t temp7 = getNumberOfHost(-1);
  
  uint32_t  size1=1, size2=2, size3=254u, size4=16777214u, size5=2147483646u, size6=4294967294u;
  
  //  - Fuehre Test durch.
  //tests_ok = show_progress( temp0 == size0);
  tests_ok = (tests_ok & show_progress(temp1==size1));
  tests_ok = (tests_ok & show_progress(temp2==size2));
  tests_ok = (tests_ok & show_progress(temp3==size3));
  tests_ok = (tests_ok & show_progress(temp4==size4));
  tests_ok = (tests_ok & show_progress(temp5==size5));
  tests_ok = (tests_ok & show_progress(temp6==size6));
  //tests_ok = (tests_ok & show_progress(temp7==size7));
    
  //  Ausgabe des Gesamtergebnis
  print_test_result(tests_ok);
  
  return tests_ok;
}


int test_getFirst() {
  printf("[Teste FirstAddress aus IP und Praefix] ");

  
  
  int tests_ok = TRUE;
  
  uint32_t subnet1=0xFFFFFFFFu, subnet2=0xFFFFFFFEu, subnet3=0xFFFFFF00, subnet4=0xFF000000u, subnet5=0x80000000u, subnet6=0x00000000u;
  uint32_t ip1=0x01020304u, ip2=0xC0A80001u, ip3=0x0A000001u, ip4=0xC0A80002u, ip5=0xC0A80201u;
  
  uint32_t temp10 = getFirst(subnet1,32);
    
  uint32_t temp20 = getFirst(subnet2,31);
  uint32_t gtru20 = subnet2;
  uint32_t temp21 = getFirst(ip1,31);
  uint32_t gtru21 = ip1;
  uint32_t temp22 = getFirst(ip2,31);
  uint32_t gtru22 = ip2;
  
  uint32_t temp30 = getFirst(subnet3,24);
  uint32_t gtru30 = 0xFFFFFF01u;
  uint32_t temp31 = getFirst(ip1,24);
  uint32_t gtru31 = 0x01020301u;
  uint32_t temp32 = getFirst(ip2,24);
  uint32_t gtru32 = 0xC0A80001u;
  uint32_t temp33 = getFirst(ip3,24);
  uint32_t gtru33 = 0x0A000001u;
  
  uint32_t temp40 = getFirst(subnet4,8);
  uint32_t gtru40 = 0xFF000001u;
  uint32_t temp42 = getFirst(ip2,8);
  uint32_t gtru42 = 0xC0000001u;
  uint32_t temp43 = getFirst(ip3,8);
  uint32_t gtru43 = 0x0A000001u;
  uint32_t temp44 = getFirst(ip4,8);
  uint32_t gtru44 = 0xC0000001u;
  
  uint32_t temp50 = getFirst(subnet5,1);
  uint32_t gtru50 = 0x80000001u;
  uint32_t temp54 = getFirst(ip4,1);
  uint32_t gtru54 = 0x80000001u;
  uint32_t temp55 = getFirst(ip5,1);
  uint32_t gtru55 = 0x80000001u;
  
  uint32_t temp60 = getFirst(subnet6,0);
  uint32_t gtru60 = 0x00000001u;
  uint32_t temp61 = getFirst(ip1,0);
  uint32_t gtru61 = gtru60;
  uint32_t temp64 = getFirst(ip4,0);
  uint32_t gtru64 = gtru61;
  uint32_t temp65 = getFirst(ip5,0);
  uint32_t gtru65 = gtru61;
  
  
  
  //  - Fuehre Test durch.
  tests_ok = show_progress(temp10 == subnet1);
  

  tests_ok = (tests_ok & show_progress(temp20==gtru20));
  tests_ok = (tests_ok & show_progress(temp21==gtru21));
  tests_ok = (tests_ok & show_progress(temp22==gtru22));
  

  tests_ok = (tests_ok & show_progress(temp30==gtru30));
  tests_ok = (tests_ok & show_progress(temp31==gtru31));
  tests_ok = (tests_ok & show_progress(temp32==gtru32));
  tests_ok = (tests_ok & show_progress(temp33==gtru33));
  
  tests_ok = (tests_ok & show_progress(temp40==gtru40));
  tests_ok = (tests_ok & show_progress(temp42==gtru42));
  tests_ok = (tests_ok & show_progress(temp43==gtru43));
  tests_ok = (tests_ok & show_progress(temp44==gtru44));

  tests_ok = (tests_ok & show_progress(temp50==gtru50));
  tests_ok = (tests_ok & show_progress(temp54==gtru54));
  tests_ok = (tests_ok & show_progress(temp55==gtru55));
  
  tests_ok = (tests_ok & show_progress(temp60==gtru60));
  tests_ok = (tests_ok & show_progress(temp61==gtru61));
  tests_ok = (tests_ok & show_progress(temp64==gtru64));
  tests_ok = (tests_ok & show_progress(temp65==gtru65));
  
    
  //  Ausgabe des Gesamtergebnis
  print_test_result(tests_ok);
  
  return tests_ok;
}



int test_getLast() {
  printf("[Teste Berechnung der letzten Address aus IP und Praefix] ");

  
  
  int tests_ok = TRUE;
  
  uint32_t subnet1=0xFFFFFFFFu, subnet2=0xFFFFFFFEu, subnet3=0xFFFFFF00, subnet4=0xFF000000u, subnet5=0x80000000u, subnet6=0x00000000u;
  uint32_t ip1=0x01020304u, ip2=0xC0A80001u, ip3=0x0A000001u, ip4=0xC0A80002u, ip5=0xC0A80201u;
  uint32_t temp10 = getLast(subnet1,32);
  
  uint32_t temp20 = getLast(subnet2,31);
  uint32_t gtru20 = 0xFFFFFFFFu;
  uint32_t temp21 = getLast(ip1,31);
  uint32_t gtru21 = 0x01020305u;
  uint32_t temp22 = getLast(ip2,31);
  uint32_t gtru22 = 0xC0A80001u;
  
  uint32_t temp30 = getLast(subnet3,24);
  uint32_t gtru30 = 0xFFFFFFFEu;
  uint32_t temp31 = getLast(ip1,24);
  uint32_t gtru31 = 0x010203FEu;
  uint32_t temp32 = getLast(ip2,24);
  uint32_t gtru32 = 0xC0A800FEu;
  uint32_t temp33 = getLast(ip3,24);
  uint32_t gtru33 = 0x0A0000FEu;
  
  uint32_t temp40 = getLast(subnet4,8);
  uint32_t gtru40 = 0xFFFFFFFEu;
  uint32_t temp42 = getLast(ip2,8);
  uint32_t gtru42 = 0xC0FFFFFEu;
  uint32_t temp43 = getLast(ip3,8);
  uint32_t gtru43 = 0x0AFFFFFEu;
  uint32_t temp44 = getLast(ip4,8);
  uint32_t gtru44 = 0xC0FFFFFEu;
  
  uint32_t temp50 = getLast(subnet5,1);
  uint32_t gtru50 = 0xFFFFFFFEu;
  uint32_t temp54 = getLast(ip4,1);
  uint32_t gtru54 = gtru50;
  uint32_t temp55 = getLast(ip5,1);
  uint32_t gtru55 = gtru54;
  
  uint32_t temp60 = getLast(subnet6,0);
  uint32_t gtru60 = 0xFFFFFFFEu;
  uint32_t temp61 = getLast(ip1,0);
  uint32_t gtru61 = gtru60;
  uint32_t temp64 = getLast(ip4,0);
  uint32_t gtru64 = gtru61;
  uint32_t temp65 = getLast(ip5,0);
  uint32_t gtru65 = gtru61;
  
  
  
  //  - Fuehre Test durch.
  tests_ok = show_progress(temp10 == subnet1);
  

  tests_ok = (tests_ok & show_progress(temp20==gtru20));
  tests_ok = (tests_ok & show_progress(temp21==gtru21));
  tests_ok = (tests_ok & show_progress(temp22==gtru22));
  

  tests_ok = (tests_ok & show_progress(temp30==gtru30));
  tests_ok = (tests_ok & show_progress(temp31==gtru31));
  tests_ok = (tests_ok & show_progress(temp32==gtru32));
  tests_ok = (tests_ok & show_progress(temp33==gtru33));
  
  tests_ok = (tests_ok & show_progress(temp40==gtru40));
  tests_ok = (tests_ok & show_progress(temp42==gtru42));
  tests_ok = (tests_ok & show_progress(temp43==gtru43));
  tests_ok = (tests_ok & show_progress(temp44==gtru44));

  tests_ok = (tests_ok & show_progress(temp50==gtru50));
  tests_ok = (tests_ok & show_progress(temp54==gtru54));
  tests_ok = (tests_ok & show_progress(temp55==gtru55));
  
  tests_ok = (tests_ok & show_progress(temp60==gtru60));
  tests_ok = (tests_ok & show_progress(temp61==gtru61));
  tests_ok = (tests_ok & show_progress(temp64==gtru64));
  tests_ok = (tests_ok & show_progress(temp65==gtru65));
  
    
  //  Ausgabe des Gesamtergebnis
  print_test_result(tests_ok);
  
  return tests_ok;
}


int test_intersection() {
  printf("[Teste die Ueberpruefung auf Schnitt von Subnetzen] ");

  
  
  int tests_ok = TRUE;
  
  uint32_t subnet1=0xC0A80000u, subnet2=0xC0A80100u, subnet3=0x10000002, subnet4=0x10000003, subnet5=0x10000001, subnet6=0x10000005;
  
  int temp1_24_2_24=doIntersect(subnet1,24,subnet2,24);
  int temp1_16_2_16=doIntersect(subnet1,16,subnet2,16);
  int temp1_24_2_16=doIntersect(subnet1,24,subnet2,16); 
  int temp1_16_2_24=doIntersect(subnet1,16,subnet2,24);   
  int temp1_16_3_16=doIntersect(subnet1,16,subnet3,16);   
  int temp1_8_3_8=doIntersect(subnet1,8,subnet3,8); 
  int temp2_24_1_24=doIntersect(subnet2,24,subnet1,24);
  int temp3_8_3_8=doIntersect(subnet3,8,subnet3,8); 
  int temp3_32_4_31=doIntersect(subnet3,32,subnet4,31); 
  int temp3_32_4_32=doIntersect(subnet3,32,subnet4,32); 
  int temp3_32_5_31=doIntersect(subnet3,32,subnet5,31); 
  int temp3_32_6_31=doIntersect(subnet3,32,subnet6,31); 
  int temp3_32_2_0=doIntersect(subnet3,32,subnet2,0);
  int temp3_32_2_1=doIntersect(subnet3,32,subnet2,1);
  int temp3_32_6_2=doIntersect(subnet3,32,subnet6,2);  
  int temp6_2_3_32=doIntersect(subnet6,2,subnet3,32); 
  
  
  
  //  - Fuehre Test durch.
  tests_ok = (tests_ok & show_progress(temp1_24_2_24==FALSE));
  tests_ok = (tests_ok & show_progress(temp1_16_2_16==TRUE));
  tests_ok = (tests_ok & show_progress(temp1_24_2_16==TRUE));
  tests_ok = (tests_ok & show_progress(temp1_16_2_24==TRUE));
  tests_ok = (tests_ok & show_progress(temp1_16_3_16==FALSE));
  tests_ok = (tests_ok & show_progress(temp1_8_3_8==FALSE));
  tests_ok = (tests_ok & show_progress(temp2_24_1_24==FALSE));
  tests_ok = (tests_ok & show_progress(temp3_8_3_8==TRUE));
  tests_ok = (tests_ok & show_progress(temp3_32_4_31==TRUE));
  tests_ok = (tests_ok & show_progress(temp3_32_4_32==FALSE));
  tests_ok = (tests_ok & show_progress(temp3_32_5_31==FALSE));
  tests_ok = (tests_ok & show_progress(temp3_32_6_31==FALSE));
  tests_ok = (tests_ok & show_progress(temp3_32_2_0==TRUE));
  tests_ok = (tests_ok & show_progress(temp3_32_2_1==FALSE));
  tests_ok = (tests_ok & show_progress(temp3_32_6_2==TRUE));
  tests_ok = (tests_ok & show_progress(temp6_2_3_32==TRUE));
  
  
  
    
  //  Ausgabe des Gesamtergebnis
  print_test_result(tests_ok);
  
  return tests_ok;
}


#endif
