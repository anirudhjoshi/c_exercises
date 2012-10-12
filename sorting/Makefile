

all: linked

linked: main.o linked.o
	$(CC) -o linked main.o linked.o -lm

main.o: Makefile
linked.o: Makefile

clean:
	rm *.o linked

CC=gcc

CFLAGs= -O0 -g -std=c99 -Wall -pedantic -Wwrite-strings -Wpointer-arith -Wcast-qual -Wcast-align -Wstrict-prototypes -Wmissing-prototypes -Wnested-externs -Wshadow -Winline -O
