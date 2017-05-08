#include <stdlib.h> 
#include <stdio.h> 

char* mifgets(char*, int, FILE*);
#define MAXLEN 100 
int main() { 

 char tline [MAXLEN]; /* Una "línea" de texto */ 
 FILE *fptr = fopen ("archivo.txt","w");
 if (fptr != NULL) {  
  while(fgets (tline, MAXLEN, fptr) != NULL) { 
  printf ("%s",tline);  
  } 
  fclose(fptr); 
 } 
 else
   fprintf(stderr,"Error al abrir el archivo\n"); 
   fprintf(stderr,"Ztra linea\n"); 
   fprintf(stderr,"Y otra\n"); 
 return 0; 
} 
