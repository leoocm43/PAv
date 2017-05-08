/*Leonardo Campuzano A01214855
Alexis Gonazlez A01333499*/
#include <stdio.h>
#include <stdlib.h>
char ** jugar(char *jug1[2], char *jug2[2]){

  //printf("%s\n", jug1[1]);
  //printf("%s\n", jug2[1]);
  
  if(jug1[1][0] == 'P'){
	if(jug2[1][0] == 'R'){
 	  return jug1;
	}
	if(jug2[1][0] == 'P'){
	  return jug1;
	}
	if(jug2[1][0] == 'S'){
	  return jug2;
	}	
  }

  if(jug1[1][0] == 'R'){
	if(jug2[1][0] == 'R'){
 	  return jug1;
	}
	if(jug2[1][0] == 'P'){
	  return jug2;
	}
	if(jug2[1][0] == 'S'){
	  return jug1;
	}	
  }

  if(jug1[1][0] == 'S'){
	if(jug2[1][0] == 'R'){
 	  return jug2;
	}
	if(jug2[1][0] == 'P'){
	  return jug1;
	}
	if(jug2[1][0] == 'S'){
	  return jug1;
	}	
  }

  

}



int main(){

char * jug1[] = {"Armando", "P"};
char * jug2[] = {"Dave", "S"};
//#define n_array (sizeof (jug1) / sizeof (const char *))

char ** ganador;
ganador = jugar(jug1, jug2);
printf("%s %s\n", *(ganador), *(ganador+ 1));
  
  return 0;
}




