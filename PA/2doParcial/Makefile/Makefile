sumaMain : suma.o mainsuma.o
	gcc -o sumaMain suma.o mainsuma.o

main.o : mainsuma.c suma.h
	gcc -c -o mainsuma.o mainsuma.c

suma.o : suma.c suma.h
	gcc -c -o suma.o suma.c


clean :
	@rm -f *.o
	@rm -f sumaMain
