#include <stdio.h>
#include <unistd.h>

int main(int argc, const char * argv[]){

  const char* c1;
  const char* c2;

  c1 = "Hola";
  pid_t pid;

  if(pid = fork()){
    c2 = "Mundo";
    sleep(10);
  }else{
    c1 = "Adios";
    c2 = "Proceso hijo";
    sleep(10);
   }
  printf("%s %s pid = %d , pid = %d\n", c1, c2, pid, getpid()); //orden: pidhijo, pidpadre
  return 0;


}

//ps aux | grep ./fork1 --> ver procesos
