#include <stdio.h>

int algo(int (*oper) (int, int), int a, int b){
  return oper(a,b);
}

int suma(int a, int b){
  return a + b;
}

int resta(int a, int b){

  return a - b;
}

void burbuja(int *arr, int tamanio, int (*comp) (int, int)){
  int intercambio = 1;
  int x = tamanio;
  while(intercambio){
    intercambio = 0;
    for(int i =0;  i < x-1; i++){
	for(int j = i + 1; j < x; j++){

	  if(comp(arr[i], arr[j]) == 1){
	    int tmp = arr[i];
	    arr[i] = arr[j];
	    arr[j] = tmp;
	    intercambio = 1;
	  }
	}
    }
    x--;

  }
}

int comp1(int a, int b){
  if (a < b)
    return -1;
  else
    return 1;
  
}

int comp2(int a, int b){
  if (a < b)
    return 1;
  else
    return -1;
  
}

int main(){

  int a[] = {12,34,21,1,2,10};
  burbuja(a, 6, comp1);
  for(int i = 0; i < 6; i ++){
   printf("%d\t", a[i]);
  }

  //printf("%d\n", algo(&suma, 5, 10));// usar & para llamar a función que llama a otra funcion
  //printf("%d\n", algo(&resta, 5, 10));

}
