/*
Alexis Gonzalez A01333499
Leonardo Campuzano A01214855
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct persona {
  char nombre[50];
  int edad;
} persona;

typedef struct nodo {
  persona per;
  struct nodo *siguiente;
} nodo;


void inserta2(nodo** n, persona *per){
  if((*n) == NULL){ //  lo que apunta n es null
	nodo *new = (nodo *) malloc(sizeof(nodo));
	new->per = *per;
	new->siguiente = NULL;
	**n = new;// n apunta a new ( que apunta al nuevo nodo)
  }
  else{
	inserta2(&(*(*n)).siguiente), per);
  }
}

void imprime(nodo *n) {
  while(n != NULL) {
    printf("nombre = %s | edad = %d\n", (*n).per.nombre, n->per.edad);
    n = n->siguiente;
  }
}

persona * leePersona() {
  persona *per = malloc(sizeof(persona)); 
  printf("dane un nombre\n");
  scanf("%s",per->nombre);
  if (strcmp(per->nombre, "fin") == 0)
    return NULL;
  printf("dame su edad\n");
  scanf("%d", &(per->edad));
  return per;
}

int main() {
  nodo *raiz = NULL;
  persona *per;
  do {
    per = leePersona();
    if (per != NULL)
      inserta2(&raiz, per);
  } while (per != NULL);
  imprime(raiz);
  return 0;
}
