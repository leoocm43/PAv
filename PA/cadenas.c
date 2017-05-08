#include <stdio.h>
#include <stdlib.h>

int main(){

char *str;
char str1[] = "123456890";
printf("%lu\n", (unsigned long) str);
//printf("%lu\n", (unsigned long) str1);
str = (char*) malloc(sizeof(char) * 11);
//str = str1;
printf("%lu\n",(unsigned long) str);
scanf("%s", str);
printf("%lu\n",(unsigned long) str);
printf("%s\n", str);



return 0;

}
