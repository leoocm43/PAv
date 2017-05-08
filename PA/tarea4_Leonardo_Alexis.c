1.- ¿Qué se entiende por una función en línea? (5 puntos)

Es un macro que se utiliza para sustituir una función que puede ocupar bastante código en el return y no así en el cuerpo de la misma. 
2.- En el lenguaje C, ¿Cuál es la utilidad del estatuto typedef?(5 puntos)

Sirve para definir un nuevo tipo de dato y funciona como un “alias” de ese tipo de dato en específico.

3.- Defina una estructura en C que represente un libro. Al menos deberá contener el nombre del libro, uno o más autores, su ISBN y la editorial. (10 puntos)

Typedef struct libro{
    char nombre[];
    char ISBN[];
    char editorial[];
    char *autores[]:

}

4.-Analice el siguiente programa en C y diga lo que imprime

a = 10	a = 10	
a = 55	a = 10	
a = 9	a = 11	a = 11	
a = 9	a = 10	
a = 10	a = 10	
a = 0	a = 1000	
a = 0	a = 100	
a = 0	a = 10	
