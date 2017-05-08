// Alexis Gonzalez A01333499  Leonardo Campuzano Magallanes A01214855 Tarea 8
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Alumno{
  char matricula[10];
  char nombre[51];
  char correo[19];
} Alumno;

typedef struct Alumno2{
  char matricula[10];
  char nombre[51];
  char correo[19];
  short siguiente;
} Alumno2;



void impresion(Alumno2 a){
  printf("matricula: %s, nombre: %s, correo: %s, siguiente: %hd\n", a.matricula, a.nombre, a.correo, a.siguiente);
}

Alumno lee(FILE* archivo, int reg){
  long pos = 77 * reg;
  Alumno a;
  fseek(archivo, pos, SEEK_SET);
  fread(&(a.matricula), 9, 1, archivo);
  a.matricula[9] = '\0';
  fread(&(a.nombre), 50, 1, archivo);
  a.nombre[50] = '\0';
  fread(&(a.correo), 18, 1, archivo);
  a.correo[18] = '\0';
  return a;
}

Alumno2 lee2(FILE* archivo, int reg){
  long pos = 79 * reg;
  Alumno2 a;
  fseek(archivo, 2, SEEK_SET);
  fseek(archivo, pos, SEEK_CUR);
  fread(&(a.matricula), 9, 1, archivo);
  a.matricula[9] = '\0';
  fread(&(a.nombre), 50, 1, archivo);
  a.nombre[50] = '\0';
  fread(&(a.correo), 18, 1, archivo);
  a.correo[18] = '\0';
  fread(&(a.siguiente), 2, 1, archivo);
  return a;
}

void insertar(FILE* archivo, int reg, Alumno a, short sig){
  long pos = 79 * reg;
  Alumno2 a2;
  strncpy(a2.matricula, a.matricula, 10);
  strncpy(a2.nombre, a.nombre, 51);
  strncpy(a2.correo, a.correo, 19);
  a2.siguiente = sig;
  fseek(archivo, pos, SEEK_CUR);
  fputs(a2.matricula, archivo);
  fputs(a2.nombre, archivo);
  fputs(a2.correo, archivo);
  fprintf(archivo, "%hd", a2.siguiente);
}

void recorrido(FILE* file){
 
int main()
{
    FILE *fptr;
 
    char filename[100], c;
 
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("No se puede abrir \n");
        exit(0);
    }

    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }
 
    fclose(fptr);
    return 0;
}

}

int comparacion(Alumno a1, Alumno a2,int i){
  int encuentra = 0;
  int ind = -2;
  int dif = -100;
  for(int m = 1;m <= strlen(a1.nombre); m++){
    int comp = strncmp(a1.nombre,a2.nombre,m);
    if(encuentra == 0){
      if(comp < 0 && comp > dif){
        dif = comp;
        ind = i;
        encuentra = 1;
      }
      if(comp > 0){
        encuentra=1;
      }
    }

  }
  if(i==1){
    return dif;
  }
  if(i==2){
    return ind;
  }
  return -1;
}



int main(int argc, char const *argv[]) {


    FILE *alumno1 = fopen("estudiantes", "rb");
    FILE *alumno2 = fopen("estudiantes2","wb+");

    fseek(alumno1, 0, SEEK_END);
    fseek(alumno2, 0, SEEK_END);

    int regs = ftell(alumno1)/77;
    int nums [regs];
    int menor = 0;
    int encontrado = 0;

    for (int i = 0; i < regs; i++) {
      Alumno a = lee(alumno1, i);
      int letra = -1;
      int dif = -30;
      int sig = -1;
      //int encuentra = 0;
      for (int j = 0; j < regs; j++) {
        Alumno a1 = lee(alumno1, j);
        if(j!=i){
          int comp1 = comparacion(a,a1,1);
          int comp2 = comparacion(a,a1,2);
          if(letra <= comp2){
            if(letra == comp2 && dif == comp1){
              int comp3 = strcmp(lee(alumno1, sig).nombre, a1.nombre);
              if(!(comp3 <= 0)){
                dif=comp1;
                letra=comp2;
                sig=j;
              }
            }
            if(((letra < comp2)||(letra == comp2 && comp1 > dif))){
              dif = comp1;
              letra = comp2;
              sig=j;
            }
          }
        }
      }
      nums[i]=sig	;
      short aux = (short) nums[i];
      fseek(alumno2, 2, SEEK_SET);
      insertar(alumno2, i, a, aux);
      Alumno2 alumno = lee2(alumno2, i);
      alumno.siguiente = aux;
     impresion(alumno);
    }
    for(int i = 0;i < regs; i++){
      for(int j = 0; j < regs; j++){
        if(nums[j] == i){
          encontrado = 1;
        }
        if(j == regs-1 && nums[j] != i && encontrado == 0){
          menor = i;
        }
      }
      encontrado=0;
    }

    fseek(alumno2, 0, SEEK_SET);
    fprintf(alumno2, "%hd", (short)menor);
    //recorrido(estudiantes2);

    fclose(alumno1);
    fclose(alumno2);

  

  return 0;
}
