#include <stdio.h>

int main(){
  int a, b;
  char* c = "12 34";
  sscanf(c, "%d %d", &a, &b);//sscanf hace scan sobre el string, no sobre stdin
  printf("Los numeros son %d %d: \n", a, b);
}
