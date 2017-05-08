#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

int busca(char* palabras[], char* palabra, int inicio, int fin, char* quien) {
  int resultado = 0;
  for(int i = inicio; i < fin; i++) 
    if (strcmp(palabra, palabras[i]) == 0) {
      printf("encontrada %s\n", quien);
      resultado++;
    }
  return resultado;
}

int total_hijo = 0;
void busca_hijo(char* palabras[], char* palabra, int inicio, int fin, char* quien) {
  int resultado = 0;
  for(int i = inicio; i < fin; i++) 
    if (strcmp(palabra, palabras[i]) == 0) {
      printf("encontrada %s\n", quien);
      kill(getppid(), SIGUSR1);
      sleep(1);
    }
}


void cuenta_hijo(int s){
  printf("Señal del hijo\n");
  total_hijo++;
  signal(SIGUSR1, cuenta_hijo);
}

int main(int argc, char* argv[]) {
  char * palabra = "hola";
  char* palabras[] = {"hola", "adios", "hola", "hola", "hola", "adios"};
  pid_t pid;

  if ((pid = fork())) {
    /* proceso padre */

    int res = busca(palabras, palabra, 0, 3, "padre");
    printf("res padre = %d\n", res);
    int status = 0;
    waitpid(pid, &status, 0);
    printf("total = %d\n", res + total_hijo);
  }
  else {
    /* proceso hijo */
    busca_hijo(palabras, palabra, 3, 6, "hijo");
  }
  return 0;
}

//dup2 permite utiizar un manejador de archivos que ya existe
