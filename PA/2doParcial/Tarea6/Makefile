
#Alexis Gonzalez A01333499
#Leonardo Campuzano A01214855


OBJS = flip.o getopt.o
CC = gcc
CFLAGS = -DBSD -DNDEBUG -O -c

all : flip man
.PHONY : all

flip : $(OBJS)
	$(CC) -s -o flip flip.o getopt.o

flip.o : flip.c 
	$(CC) $(CFLAGS) flip.c

getopt.o : getopt.c
	$(CC) $(CFLAGS) getopt.c

man : flip.1
	nroff -man flip.1 > flip.man

$(OBJS) : flip.h

clean :
	@rm -f *.o
	@rm -f flip
	@rm -f flip.man

	
