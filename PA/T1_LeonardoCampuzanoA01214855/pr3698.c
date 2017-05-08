#include <stdio.h>

int main(){
int countLower;
int countUpper;
int n;
char str[11];
scanf("%d %s", &n, str);
printf("%d %s\n",n, str);

//strn[n] = '\0';
int i;

while(str[i] != '\0' && i < n){     																																																																																																																																																																																																																																																																																				
	if(str[i] >= 'a' && str[i] <= 'z')
	{

	  countLower++;
	}

	if(str[i] >= 'A' && str[i] <= 'Z')
	{

	  countUpper++;
	}
	i++;

 }


printf("%d %d\n",countUpper, countLower);



return 0;

}
