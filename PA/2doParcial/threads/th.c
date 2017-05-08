#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <pthread.h>

  int total = 0;
  char * palabra = "hola";
  char* palabras[] = {"hola", "adios", "hola", "hola", "hola", "adios"};

void busca(	int inicio, int fin, char* quien) {
  int resultado = 0;
  for(int i = inicio; i < fin; i++) 
    if (strcmp(palabra, palabras[i]) == 0) {
      printf("encontrada %s\n", quien);
      int temp = total;
      total ++;
    }
}

void* th(void* arg){
  busca(3,6, "thread hijo");
  return arg;
}


int main(int argc, char* argv[]) {
  pthread_attr_t attr;
  pthread_t thread;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
  int tmp = pthread_create(&thread, &attr, th, NULL);
  busca(0, 3, "padre");
  pthread_join(thread, NULL);
  printf("el totale fue de: %d\n", total);
  return 0;
}

//dup2 permite utiizar un manejador de archivos que ya existe
