#include <stdio.h>


void imprime(char c, int veces){
  int i;
  for(i = 0; i <veces; i++){
    printf("%c", c);
  }
}


int* frecuencia(int calis[], int n, int *frecs){

  //int frecs[11] = {0};
  for(int i = 0; i < n; i++){
	frecs[calis[i]]++;
  }
}

void histograma(int frecs[]){
  for(int i = 0; i <= 10; i++){
	printf("Calificacion de %d\t ", i);
	imprime('*', frecs[i]);
	printf("\n");
  }

}

int main(){

  int calis[] ={0,0,1,2,3,4,5,0,10,4,5,6,7,3,4};
  int frecs[11] = {0};
  frecuencia(calis, 15, frecs);
  histograma(frecs);
  return 0;


}
