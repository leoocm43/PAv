#include <stdlib.h>
#include <stdio.h>
#define PR(a) printf("a = %d\t", (int)(a))
#define PRINT(a) PR(a); putchar('\n');
#define PRINT2(a,b) PR(a); PRINT(b)
#define PRINT3(a,b,c) PR(a); PRINT2(b,c)
int main(int argc, const char * argv[])
{
    int x, y, z;
    x = y = z = 0;
    while (y < 10) ++y; x += y;
    PRINT2(x,y);   /* 5 puntos */
    x = y = 0;
    while (y < 10) x += ++y;
    PRINT2(x,y); /* 5 puntos */
    y = 1;
    while (y < 10) {
        x = y++; z = ++y;
    }
    PRINT3(x, y, z); /* 5 puntos */
    for (y = 1; y < 10; y++) x = y;
    PRINT2(x, y); /* 5 puntos */
    for (y = 1; (x=y)<10; y++);
    PRINT2(x, y); /* 5 puntos */
    for (x = 0, y = 1000; y > 1; y++, y /= 10) {
        PRINT2(x, y); /* 10 puntos */
    }
    return 0;	
}
 

