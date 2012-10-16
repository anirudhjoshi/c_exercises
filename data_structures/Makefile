all: linked skip_list

linked: main.o linked.o
	$(CC) -o linked main.o linked.o -lm

skip_list: main.o skip_list.o
	$(CC) -o skip_list main.o skip_list.o -lm

main.o: Makefile
linked.o: Makefile
skip_list.o: Makefile

clean:
	rm *.o linked skip_list

CC=gcc

CFLAGs= -O0 -g -std=c99 -Wall -pedantic -Wwrite-strings -Wpointer-arith -Wcast-qual -Wcast-align -Wstrict-prototypes -Wmissing-prototypes -Wnested-externs -Wshadow -Winline -O

