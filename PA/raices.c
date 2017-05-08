#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void cuadrado(int *a){
  *a *= *a;
}

char * raices(int a, int b, int c){
  int dis = b*b-4*a*c;
  if(dis == 0)
	return "raices iguales";
  else if(dis < 0)
	return "raices complejas";
  else
	return "racies desiguales";

}

int longitud(char *cadena){

  int i = 0;
  while(cadena[i] != '\0')
    i++;
  return i;
}

int main(){

  char * tmp = raices(1,12, 250);
  int tamano = longitud(tmp);
  char *tmp1 = (char *) malloc((tamano+1)*sizeof(char));
  memcpy(tmp1, tmp, tamano + 1);
  tmp1[2] = '\0';//modificar eof
  printf("%s, %s\n", tmp, tmp1);
  printf("%d %d\n", 1 || 1 , 101^ 101);
  int tmp3 = 0xF;
  int tmp4 = 0x5;
  printf("%d %d\n", tmp3 >> 1, tmp3 ^ tmp4);// >> recorre bits
  free(tmp1);
  int z = 100;
  cuadrado(&z);
  printf("%d\n", z);
  return 0;
}


