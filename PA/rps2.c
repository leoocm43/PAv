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

char ** compiteTorneo(char** arr, int num){
  if(num == 2){
    char** j1 = (char**)malloc(sizeof(char)*50);
    char** j2 = (char**)malloc(sizeof(char)*50);
    j1[0]=*(arr);
    j1[1]=*(arr+1);
    j2[0]=*(arr+2);
    j2[1]=*(arr+3);

    return compite(j1,j2);
  }
  else{
    int conteo = 0;
    char ** aux = (char**)malloc(sizeof(char)*50*n);
    for(int i = 0; i < n ; i += 2){

      char** p1 = (char**)malloc(sizeof(char)*50);
      char** p2 = (char**)malloc(sizeof(char)*50);
      p1[0]=*(arr+conteo);
      p1[1]=*(arr+conteo+1);
      p2[0]=*(arr+conteo+2);
      p2[1]=*(arr+conteo+3);
      char** gana = compite(p1,p2);
      aux[i] = gana[0];
      aux[i+1] = gana[1];
      conteo += 4;
    }

     return compiteTorneo(aux, n/2);
   }
}



int main(){

char* juego2[][2][2][2] = {
        {
            {{"Armando","P"}, {"Dave","T"}},
            {{"Richard", "R"}, {"Michael", "T"}}
        }, 
        {
            {{"Allen", "T"}, {"Omer", "P"}},
            {{"David E.", "R"}, {"Richard X.", "P"}}
        }
    };

char* encuentro[][2][2][2] = {
  {
				
	{{*(juego2 + 1), *(juego2 + 2), {*(juego2 + 3), *(juego2 + 4)}},
	{{*(juego2 + 5), *(juego2 + 6)}, {*(juego2 + 7), *(juego2 + 8)}}
  }
		};
		char ** arr = (char **) encuentro;
		char ** ganador = compiteTorneo(arr, 4);
		printf("%s %s\n", *(ganador), *(ganador+1));




/*char ** ganador;
ganador = jugar(jug1, jug2);
printf("%s %s\n", *(ganador), *(ganador+ 1));*/
  
  return 0;
}




