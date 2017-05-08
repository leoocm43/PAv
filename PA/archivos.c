#include <stdio.h>

int main(){

  FILE *archivo = fopen("salidaArchivo", "w");
  fprintf(archivo, "hola mundo\n");
  fclose(archivo);
  return 0;
}

 /*FILE *archivo = fopen("salidaArchivo", "r");
char linea[1000];
fscanf(archivo, "%s", linea);
fclose(archivo);
printf("%s\n", linea);

FILE *archivo;
if((archivo = fopen("salidaArchivo", "r"))){
  char linea[1000];
  fgets(ñinea, 100, archivo);
  fclose(archivo);
printf("%s\n", linea);

}
return 0;*/
