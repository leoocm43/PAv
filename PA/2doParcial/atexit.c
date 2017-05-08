#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void f1(){
  printf("Ya me voy\n");
}

int main( int argc, const char* argv[]){
  atexit(f1);
  //_exit(0); //es inmediato
  while(1){
  }
  exit(0); //imprime y leugo exit
}
