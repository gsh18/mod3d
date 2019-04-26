##***************************************************##
##  GIANFRANCO DE SOUZA HARRES      - GRR: 20180103  ##
##  VINICIUS AUGUSTO DILAY DE PAULA - GRR: 20182597  ##
##***************************************************##
##                    MAKEFILE                       ##
##***************************************************##
##         Make para o ASCII - BOUDERDASH            ##
##***************************************************##


DEPS = datatypes.h

CC = gcc

CFLAGS = -Wall

BIB = -lSDL2 -lSDL2_gfx -lm

all: wireframe

wireframe: wireframe.o objread.o perspect.o graphics.o
	$(CC) -o wireframe wireframe.o objread.o perspect.o graphics.o $(BIB)

perspect.c: perspect.h
objread.c:  objread.h
graphics.c:  graphics.h

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	-rm -f *~ *\# \#* *.o

purge: clean
	-rm -f wireframe
