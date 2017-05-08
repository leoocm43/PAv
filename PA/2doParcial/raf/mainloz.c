#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Alumno1 {
    char matricula[10];
    char nombre[51];
    char correo[19];
} Alumno1;

typedef struct Alumno2 {
    char matricula[10];
    char nombre[51];
    char correo[19];
    short sig;
} Alumno2;

#define tam_reg1 77
#define tam_reg2 79


Alumno1 lee(FILE *archivo,int reg) {
    Alumno1 al;
    fseek(archivo, reg*tam_reg1, SEEK_SET);
    fread(al.matricula,sizeof(char)*9,1,archivo);
    al.matricula[9] = '\0';
    fread(al.nombre,sizeof(char),50,archivo);
    al.nombre[50] = '\0';
    fread(al.correo,sizeof(char),18,archivo);
    al.correo[18] = '\0';
    return al;
}

Alumno2 lee2(FILE *archivo,int reg) {
    Alumno2 al;
    fseek(archivo, reg*tam_reg2 + sizeof(short), SEEK_SET);
    fread(al.matricula,sizeof(char)*9,1,archivo);
    al.matricula[9] = '\0';
    fread(al.nombre,sizeof(char),50,archivo);
    al.nombre[50] = '\0';
    fread(al.correo,sizeof(char),18,archivo);
    al.correo[18] = '\0';
    fread(&(al.sig),sizeof(short),1,archivo);
    return al;
}

void imprime(Alumno1 al) {
    printf("%s\t%s\t%s\n",al.matricula,al.nombre,al.correo);
}

void imprime2(Alumno2 al) {
    printf("%s\t%s\t%s\t%d\n",al.matricula,al.nombre,al.correo,al.sig);
}

void inserta(FILE *al2, Alumno1 al) {
    fseek(al2,0,SEEK_END);
    short inicio;
    if (ftell(al2) == 0) {
        fseek(al2,0,SEEK_SET);
        inicio = 0;
        fwrite(&inicio,sizeof(short),1,al2);
        inicio = -1;
        fwrite(al.matricula,sizeof(char),9,al2);
        fwrite(al.nombre,sizeof(char),50,al2);
        fwrite(al.correo,sizeof(char),18,al2);
        fwrite(&inicio,sizeof(short),1,al2);
        return;
    }
    fseek(al2,0,SEEK_SET);
    fread(&inicio,sizeof(short),1,al2);
    short i1 = inicio;
    short i2 = inicio;
    Alumno2 a2 = lee2(al2,i1);
    while (i1 >= 0 && strcmp(al.nombre,a2.nombre) > 0) {
        i2 = i1;
        i1 = a2.sig;
        if (a2.sig >= 0)
            a2 = lee2(al2,a2.sig);
    }
    fseek(al2,0,SEEK_END);
    short reg = (short) (ftell(al2) / tam_reg2);
    fwrite(al.matricula,sizeof(char),9,al2);
    fwrite(al.nombre,sizeof(char),50,al2);
    fwrite(al.correo,sizeof(char),18,al2);
    if (i1 == i2) { // al inicio lógico
        fwrite(&inicio,sizeof(short),1,al2);
        fseek(al2,0,SEEK_SET);
        fwrite(&reg,sizeof(short),1,al2);
    }
    else  {
        fwrite(&i1,sizeof(short),1,al2);
        fseek(al2,sizeof(short) + i2 * tam_reg2 + tam_reg1,SEEK_SET);
        fwrite(&reg, sizeof(short), 1, al2);
    }
}

void imprimeAlumno2Fisico(FILE *archivo) {
    fseek(archivo, 0, SEEK_SET);
    short inicio;
    fread(&inicio, sizeof(short), 1, archivo);
    printf("inicio = %d\n",inicio);
    fseek(archivo,0,SEEK_END);
    long regs = ftell(archivo)/tam_reg2;
    int i = 0;
    for(i = 0; i < regs; i++) {
        Alumno2 al2 = lee2(archivo, i);
        imprime2(al2);
    }
}

void imprimeAlumno2Logico(FILE *archivo) {
    fseek(archivo, 0, SEEK_SET);
    short inicio;
    fread(&inicio, sizeof(short), 1, archivo);
    while (inicio != -1) {
        Alumno2 al2 = lee2(archivo, inicio);
        imprime2(al2);
        inicio = al2.sig;
    }
}

int main() {
    printf("%d,%d\n",tam_reg1,tam_reg2);
    FILE *alumno1 = fopen("estudiantes","rb");
    FILE *alumno2 = fopen("estudiantes2","wb+");
    int i = 0;
    fseek(alumno1,0,SEEK_END);
    long regs = ftell(alumno1)/tam_reg1;
    for (i = 0; i < regs; i++) {
        Alumno1 al = lee(alumno1,i);
        inserta(alumno2,al);
    }
    /*while (!feof(alumno1) ) {
        Alumno1 al = lee(alumno1,i++);
        inserta(alumno2,al);
    }*/
    imprimeAlumno2Fisico(alumno2);
    printf("------\n");
    imprimeAlumno2Logico(alumno2);
    fclose(alumno1);
    fclose(alumno2);
    return 0;
}







    
