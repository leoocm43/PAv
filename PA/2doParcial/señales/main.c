#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


int cuenta = 0;

void ctrl_c(int signum){
  printf("se atrapo la señan SIGINT %d\n", signum);
  if(cuenta == 0){
    alarm(5);
    printf("Digita nuevamente ctrl-c para terminar en menos de 5 seg\n");
  }else{
    cuenta++;
  }
  exit(signum);
}

void alarma(int signum){
  printf("El temproizador expiró");
  cuenta = 0;
}

int main()
{
  //registrar el manejador de señal
  signal(SIGINT, ctrl_c);
  signal(SIGALRM, alarma);

  while(1)
  {
    printf("Prcesando cosas\n");
    sleep(1);
  }
  return EXIT_SUCCESS;
}
