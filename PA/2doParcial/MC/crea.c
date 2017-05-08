#include <stdio.h>
#include <string.h>
#include "mc.h"

/* para memmoria compartida */
#include <sys/shm.h>
#include <sys/stat.h>

int main(int argc, const char * argv[]) {
  //char* palabras[] = {"hola", "hola", "adios", "adios", "adios", "hola"};
  /* crea memoria compartida */
  int shmid1, shmid2;

  if ( (shmid1 = shmget(KEY1, sizeof(compartir), IPC_CREAT | S_IRWXU)) < 0 ) {
    perror("Error en creacion al_ shmget");
    return 1;
  }
 
  compartir *cmp = (compartir*) shmat(shmid1, 0, 0);
  if (((int) cmp) == -1) {
    perror("error en shmat1");
    return 1;
  }
  cmp->inicio = 0;
  cmp->fin = argc-2; //sizeof(palabras)/sizeof(char*);
  cmp->mitad = cmp->fin/2;
  strcpy(cmp->palabra, argv[1]);

  
  if ( (shmid2 = shmget(KEY2, cmp->fin*50, IPC_CREAT | S_IRWXU)) < 0 ) {
    perror("Error en creacion al_ shmget");
    return 1;
  }

  char *mem2 = (char*) shmat(shmid2, 0, 0);
  if (((int) mem2) == -1) {
    perror("error en shmat2");
    return 1;
  }

  for(int i = 0; i < cmp->fin; i++) {
    strcpy(mem2, argv[i+2]);
    mem2 += 50;
  }

  return 0;
}
