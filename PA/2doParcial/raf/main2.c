#include <stdio.h>

typedef struct Alumno{
  char matricula[10];
  char nombre[51];
  char correo[19];
} Alumno;

void impresion(Alumno a){
  printf("matricula: %s nombre: %s correo: %s\n", a.matricula, a.nombre, a.correo);
}

Alumno lee(FILE* archivo, int reg){
  long pos = 77 * reg; //posicion del alumno en cuestion
  Alumno a;
  fseek(archivo, pos, SEEK_SET);
  fread(&(a.matricula), 9, 1, archivo);
  a.matricula[9] = '\0';
  fread(&(a.nombre), 50, 1, archivo);
  a.nombre[50] = '\0';
  fread(&(a.correo), 18, 1, archivo);
  a.correo[18] = '\0';
}

int main(){
  FILE *alumno1 = fopen("estudiantes", "rb");
  Alumno a = lee(alumno1, 0);
  fseek(alumno1, 0, SEEK_END);
  int regs = ftell(alumno1) / 77;
  printf("Numero de registros %d\n", regs);
  impresion(a);
  fclose(alumno1);
  return 0;
}	
