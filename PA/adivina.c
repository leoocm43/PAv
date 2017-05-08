#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(NULL));//genera una semilla
  int maquina = rand() %100;
  int intentos = 0;
  int usuario = -1;

  printf("%d", maquina);
  while(maquina != usuario){

 	intentos++;
	printf("dame tu intento\n");
	scanf("%d", &usuario);
	if(usuario > maquina){
	  printf("Tu numero es muy grande\n");
	}
	else if(usuario < maquina){
	  printf("Tu numero es muy pequeño\n");
	  
	}
  }
  printf("Le atinaste en %d intentos\n", intentos);
return 0;
}
