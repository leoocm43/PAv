#include <stdio.h>

void imprime(char c, int veces){
int i;
  for(i=0; i < veces; i ++){
  printf("%c", c);
  }

}


int main(){

  int pisos;
  printf("Dame el numero de pisos de tu rombo\n");
  scanf("%d", &pisos);
  int blancos = pisos/2 ;
  int asteriscos = 1;
  for(int i = 0;i < pisos/2; i++){//parte de arriba
	imprime(' ', blancos);
	imprime('*', asteriscos);
	printf("\n");
	blancos -= 1;
	asteriscos +=2;
  }
  imprime('*', pisos);//base
  printf("\n");
  blancos = 1;
  asteriscos = pisos - 2;
  for(int i = 0;i < pisos/2; i++){//parte de abajo
	imprime(' ', blancos);
	imprime('*', asteriscos);
	printf("\n");
	blancos += 1;
	asteriscos -=2;
  }
  printf("\n");





return 0;

}
