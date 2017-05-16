#ifndef __IPV4
#define __IPV4

#include "stdint.h"


typedef struct {
  uint8_t a;
  uint8_t b;
  uint8_t c;
  uint8_t d;
} ipv4;


int compare(ipv4 b0, ipv4 b1) {
	if(b0.a==b1.a && b0.b==b1.b && b0.c==b1.c && b0.d==b1.d)return TRUE;
	else return FALSE;
}

ipv4 toAddress(uint8_t a, uint8_t b, uint8_t c , uint8_t d){
  ipv4 address;
  address.a=a;
  address.b=b;
  address.c=c;
  address.d=d;
  return address;
}


#endif