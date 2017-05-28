#ifndef __TEST_ONE_COMPLEMENT
#define __TEST_ONE_COMPLEMENT

#include "boolean.h"
#include "colored_output.h"
#include <stdint.h>
#include <assert.h>



typedef union floatUnion {
  float float_number;
  uint32_t uint_number;
} floatUnion;



/**
 *  Hilsfunktion zur Umwandlung von float to bit_vector
 *
 *  @param f
 *         Umzuwandelnde 32bit IEEE-float
 *  @param b
 *         gueltiger Pointer auf Bitvektor, fordert Speicher fuer das bits-Feld an.
 *         falls das bits-Feld bereits zuvor initialisiert ist, gege den Speicher zunaechst frei.
 *  @return
 *         TRUE, falls alle Eingaben gueltig und es keinen Fehler gab
 *         FALSE, sonst
 */
int to_bit_vector_32(float f, bit_vector* b){
	assert(sizeof(float)==sizeof(uint32_t));
	if(!b){
		printf( ANSI_COLOR_RED "Illegaler Pointer auf Bitvektor.\n" ANSI_COLOR_RESET);
		return FALSE;
	}
	if(b->bits){
		free(b->bits);
	}
	b->length = 32;  
	if ((b->bits = (unsigned char*)malloc(sizeof(unsigned char) * b->length)) == NULL) {
		printf( ANSI_COLOR_RED "Speicheranforderung fehlgeschlagen.\n" ANSI_COLOR_RESET);
		return FALSE;
	}
	
	floatUnion fu;
	fu.float_number=f;
	for(int i=0;i<32;i++){
		b->bits[31-i]=(fu.uint_number >> i) & 1u;		
	}	
	
	return TRUE;
}

/**
 *  Teste die Korrektheit der compare-Funktion.
 *
 *  @return
 *          TRUE genau dann, wenn kein Test fehlschlaegt.
 */
int test_ieee() {
  printf("[Teste Compare-Funktion]");

  
  
  int tests_ok = TRUE;
  int error = TRUE;
  bit_vector b1={0},b2={0},b3={0},b4={0},b5={0},b6={0},b7={0},b8={0},b9={0},b10={0},b11={0},b12={0};  
  to_bit_vector_32(-1.3f,&b1);
  if(!to_bit_vector_32(-1.2f,&b2)){free(b1.bits); return FALSE;}
  if(!to_bit_vector_32(-0.0f,&b3)){free(b2.bits); free(b1.bits); return FALSE;}
  if(!to_bit_vector_32(0.0f,&b4)){free(b3.bits); free(b2.bits); free(b1.bits); return FALSE;}
  if(!to_bit_vector_32(1.2f,&b5)){free(b4.bits); free(b3.bits);  free(b2.bits); free(b1.bits); return FALSE;}
  if(!to_bit_vector_32(0.0f/0.0f,&b6)){free(b5.bits);free(b4.bits); free(b3.bits); free(b2.bits); free(b1.bits); return FALSE;}
  if(!to_bit_vector_32(1.0f/0.0f,&b7)){free(b6.bits); free(b5.bits);free(b4.bits); free(b3.bits); free(b2.bits); free(b1.bits); return FALSE;}
  if(!to_bit_vector_32(-1.0f/0.0f,&b8)){free(b7.bits);free(b6.bits);free(b5.bits);free(b4.bits);free(b3.bits); free(b2.bits); free(b1.bits); return FALSE;}

  unsigned char b9bits[] = {1,0,1,0,1,0,1};
  unsigned char b10bits[] = {1,1,1,0,1,0,0};
  unsigned char b11bits[] = {1,0,0,1,1,0,1};
  unsigned char b12bits[] = {0,0,0,1,1,0,1};

  b9.length=7;
  b9.bits=b9bits;

  b10.length=7;
  b10.bits=b10bits;
  
  b11.length=7;
  b11.bits=b11bits;
  
  b12.length=7;
  b12.bits=b12bits;
  
  int res=0;
  
  error = lessThanIEEE(&b1,&b2,8,23,&res);
  tests_ok &= show_progress(!error && res == 1);
  error = lessThanIEEE(&b2,&b3,8,23,&res);//-1.2 zu -0.0
  tests_ok &= show_progress(!error && res == 1);
  error = lessThanIEEE(&b3,&b4,8,23,&res);//-0 zu 0
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b2,&b4,8,23,&res);//-1.2 zu 0
  tests_ok &= show_progress(!error && res == 1);
  error = lessThanIEEE(&b4,&b1,8,23,&res);//0.0 zu -1.3
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b4,&b3,8,23,&res);
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b3,&b2,8,23,&res);
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b2,&b1,8,23,&res);
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b1,&b1,8,23,&res);
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b2,&b2,8,23,&res);
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b3,&b3,8,23,&res);
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b4,&b4,8,23,&res);
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b8,&b1,8,23,&res);//-inf zu -1.2
  tests_ok &= show_progress(!error && res == 1);
  error = lessThanIEEE(&b8,&b3,8,23,&res);//-inf zu -0
  tests_ok &= show_progress(!error && res == 1);
  error = lessThanIEEE(&b8,&b4,8,23,&res);//-inf zu +0
  tests_ok &= show_progress(!error && res == 1);
  error = lessThanIEEE(&b8,&b7,8,23,&res);//-inf zu +inf
  tests_ok &= show_progress(!error && res == 1);
  error = lessThanIEEE(&b7,&b8,8,23,&res);//inf zu -inf
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b6,&b8,8,23,&res);//NaN zu -inf
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b8,&b6,8,23,&res);//-inf zu NaN
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b6,&b6,8,23,&res);//NaN zu NaN
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b6,&b3,8,23,&res);//NaN zu -0
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b6,&b4,8,23,&res);//NaN zu +0
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b6,&b1,8,23,&res);//NaN zu -1.3
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b6,&b5,8,23,&res);//NaN zu 1.2
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b3,&b6,8,23,&res);//-0 zu NaN
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b4,&b6,8,23,&res);//+0 zu NaN
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b1,&b6,8,23,&res);//-1.3 zu NaN
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b5,&b6,8,23,&res);//1.2 zu NaN
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b5,&b9,8,23,&res);//1.2 zu NaN
  tests_ok &= show_progress(error);
  error = lessThanIEEE(&b9,&b10,3,3,&res);
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b10,&b9,3,3,&res);
  tests_ok &= show_progress(!error && res == 1);
  error = lessThanIEEE(&b10,&b9,2,4,&res);
  tests_ok &= show_progress(!error && res == 0);//zu nan
  error = lessThanIEEE(&b9,&b10,2,4,&res);
  tests_ok &= show_progress(!error && res == 0);//zu nan
  error = lessThanIEEE(&b9,&b10,0,6,&res);
  tests_ok &= show_progress(error);//k=0
  error = lessThanIEEE(&b9,&b10,1,6,&res);
  tests_ok &= show_progress(error);//1+k+n size falsch    
  error = lessThanIEEE(&b11,&b12,2,4,&res);//- denormal zu +denormal
  tests_ok &= show_progress(!error && res == 1);
  error = lessThanIEEE(&b12,&b11,2,4,&res);//+ denormal zu -denormal
  tests_ok &= show_progress(!error && res == 0);
  error = lessThanIEEE(&b9,&b11,2,4,&res);//neg zu -denormal
  tests_ok &= show_progress(!error && res == 1);
  
  

    
  //  Ausgabe des Gesamtergebnis
  print_test_result(tests_ok);
  
  free(b8.bits);
  free(b7.bits);
  free(b6.bits);
  free(b5.bits);
  free(b4.bits);
  free(b3.bits);
  free(b2.bits);
  free(b1.bits);
  
  return tests_ok;
}

#endif
