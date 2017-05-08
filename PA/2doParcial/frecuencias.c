
//Alexis Gonzalez A01333499 Leonardo Campuzano A01214855 Tarea 9

#include <stdio.h>
#include <string.h>

typedef struct Palabra{
  char palabra[20];
  int veces;
} Palabra;

void busca(Palabra palabras[], int *tamanio, char* palabra){
  for( int i = 0; i < *tamanio; i++){
    if(strcmp(palabras[i].palabra, palabra) == 0){
      palabras[i].veces++;
      return;
    }
  }
  strcpy(palabras[*tamanio].palabra, palabra);
  palabras[*tamanio].veces = 1;
  (*tamanio)++;
}

void imprime(char c, int veces){
  int i;
  for(i = 0; i <veces; i++){
    printf("%c", c);
  }
}

void escribir(Palabra palabras[], int tamanio){
  for(int i =0; i < tamanio; i++){
    printf("%s %d\t", palabras[i].palabra, palabras[i].veces);//imprime numero de palabras
  }
}

void histograma(Palabra palabras[], int tamanio){
  for(int i =0; i < tamanio; i++){
	printf("Repeticiones de %s\t", palabras[i].palabra);
	imprime('*', palabras[i].veces);
	printf("\n");
  }
}


int main(){
  Palabra palabras[100];
  char palabra[20];
  int tamanio = 0;

 while(scanf("%s", palabra) != EOF){
    busca(palabras, &tamanio, palabra);
  }
  escribir(palabras, tamanio);
  histograma(palabras, tamanio);
  return 0;
}
