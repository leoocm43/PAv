#include <stdio.h>
#include <unistdio.h>
#include <string.h>


void reduce(){

    FILE *fpOut;
    FILE *fpIn;
	fpIn = fopen("mapfruit.txt", "r");
    char temp;
    char *string = malloc(sizeof(char));
    int charCount = 0;
    int wordCount = 0;
    
    while ((temp = fgetc(fpIn)) != EOF) {
        
        if (temp == '\n') {
            wordCount ++;
            

            
            charCount = 0;
            
        } else {
            if (charCount == 0) {
                string = malloc(0, sizeof(char));
            }
            string[charCount] = temp;
            charCount ++;
        }
    }
	fclose(fpIn);

}


int main(){
  

reduce();

}



