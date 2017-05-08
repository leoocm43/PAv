#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_entradas 500
struct Entrada {
  char palabra[20];     /* la palabra */
  int lineas[10];   /* el número de línea en el que aparece */
  int total;        /* total de apariciones de la palabra en el texto */
};

int split(char *str, char palabras[][21]) {
  int i = -1;
  char *tmp;
  tmp = strtok(str," \t\n.¿?:");
  while(tmp) {
    strcpy(palabras[++i],tmp);
    tmp = strtok(NULL," \t\n.¿?:");
  }  
  return ++i;
}

void imprime(Entrada entradas[max_entradas]){

int *p;
int len = split(linea,palabras);
*p = entradas->lineas;

for (int i =0; i < len; i++){

   printf("La palabra %s se encuentra en las lineas %d", entradas->palabras[i], p++); 
}






typedef struct Entrada Entrada;
int busca(Entrada entradas[], int longitud, char* palabra){
  //regresa algo >=0 si palabra ya registrada sino -1
  while(){
    if(strcmp(palabra, entradas[i].palabra) == 0){
	return i;
    i++;
    }
    return -1;
  }
}

void imprime(Entrada entradas[], int longitud){
 for(int i = 0;i < longitud; i++){
   printf("La palabra '%s' se encuentra en las lineas:\n", entradas[i].palabra);
   int j = 0;
   while(entradas[i].lineas[j] !=0)
    printf("\t%d", entradas[i].lineas[j++]);
   printf("\n");
 } 
}
int main() {
  Entrada entradas[max_entradas] = {{"",{0},0}}; /* inicializa el arreglo */
  char *linea;
  size_t tamanio;
  int num_linea = 1;
  int longitud = 0;
  while (getline(&linea,&tamanio, stdin) != -1) {
    char palabras[100][21];
    int len = split(linea,palabras);    
    int i;
    for(i = 0; i < len; i++){
      int res = busca(entradas, longitud, palabras[i];
	if(res < 0) {
	  strcpy(entradas[longitud].palabra, palabras[i]);
	  entradas[longitud]. lineas[0] = num_linea;
	  entradas[longitud].total++;;
	  longitud++;
	}
	else{
	  int j = 0;
	  while(entradas[res].lineas[j] != 0 && entradas[res].lineas[j] != 		  num_linea){
	  j++;
	  entradas[res].lineas[j] = num_line;
	    
	  }
	}
	    num_linea++;
    }
    imprime(entradas, longitud);
}
