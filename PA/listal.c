//Leonardo Campuzano Magallanes A01214855; Alexis Gonzalez A0
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

void inserta(nodo* n, persona *per) {
  if (n->siguiente == NULL) {
    n->siguiente = (nodo *) malloc(sizeof(nodo));
    (*(*n).siguiente).per = *per;
    n->siguiente->siguiente = NULL;
  }
  else
    inserta(n->siguiente, per);
}

void inserta

void imprime(nodo *n) {
  while(n != NULL) {
    printf("nombre = %s edad = %d\n", (*n).per.nombre, n->per.edad);
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

/*int main() {
  nodo raiz;
  persona *per = leePersona();
  raiz.per = *per;
  raiz.siguiente = NULL;
  per = leePersona();
  inserta(&raiz, per);
  imprime(&raiz);
  return 0;
}*/

int main2() {
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

