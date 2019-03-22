# makefile Michel Caluwaerts
# projet de prog OXO, BAC1HD 2015 (version corrigée 13/5/2015)
CC = gcc
CFLAGS = -W
LFLAGS=-std=c99 -lm
LINK = gcc 


all: a

OBJECTS =  main.o bwt.o mtf.o


a: $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o a $(OBJECTS) $(LFLAGS)


clean: 
	rm -f *.o
	rm -f a