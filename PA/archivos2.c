#include <stdlib.h>
#include <stdio.h>

int main(){
  char archivo[] = "archivo.txt";
  FILE* fptr = fopen(archivo, "w");
  if(fptr == NULL) {
    fprintf(stderr,"Problemas al abrir el archivo\n");
    exit(1);
  }
  fprintf(fptr, "Hola mundo sobre archivos\n");
  fprintf(fptr, "Otra linea\n");
  fprintf(stderr, "Esto va a la salida de error\n");
  fprintf(stdout, "Esto va a la saluda estandar\n");
  exit(1);
  fclose(fptr);

  return 0 ;
}


