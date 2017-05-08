#include <stdio.h>
#include <unistd.h>

int main(int argc, const char* argv[]){
  
  const char* c1;
  const char* c2;

  c1 = "Hola";
  if(fork()){
    c2 = "Mundo";
    sleep(10);
  }else{
    c2 = "Proceso hijo";
  }
  printf("%s %s\n", c1, c2);

  return 0;

}
