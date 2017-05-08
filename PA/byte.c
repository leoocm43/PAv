#include <stdio.h>


int main(){

  char *b = "hola";
  printf("%lu %lu\n", (unsigned long) b,  (unsigned long) (b+1));//de uno en uno
  
  int c[] = {12,34};//con short va de dos en 2
  printf("%lu %lu\n", (unsigned long) c,  (unsigned long) (c+1));//de 4 en 4	


}
