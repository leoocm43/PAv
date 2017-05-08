#include <stdio.h>
#include <stdlib.h>

typedef struct persona{

  char nombre[50];
  int edad;
}persona;

typedef struct nodo{
  persona *per;
  struct nodo *siguiente;
} nodo;

void inserta(nodo *n, persona *per){
  if(n->siguiente == NULL){
    n->siguiente = (nodo *) malloc(sizeof(nodo));
    n->siguiente->per = *per;
    n->siguiente->siguiente = NULL;
  }
  else{
    inserta(n->siguiente, per);
  }
}

void imprime(nodo *n){

  while(n != NULL){
    printf("nombre = %s edad = %d\n", n->per.nombre, n->per.edad);
    n = n->siguiente;
  }

}

persona * leePersona(){

  persona *per = malloc(sizeof(persona));
  printf(" dame un nombre\n");
  scanf("%s", per->nombre);
  printf("dame su edad\n");
  scanf("%d", &(per->edad));

  return per;
  
}
int main(){
  nodo raiz;
  persona *per = leePersona();
  raiz.per = *per;
  raiz.siguiente = NULL;
  per = leePersona();
  inserta(&raiz, per);
  imprime(&raiz);

return 0;
}




