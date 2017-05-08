#include <stdio.h>

#define MACRO1 25

int main(void){
  #ifdef MACRO1 //tst whether macro is defined...
    printf("\nMACRO1 Defined with value [%d]\n", MACRO1);
  #endif
  return 0 ;
}

//MACRO remplaza, no es funcion

