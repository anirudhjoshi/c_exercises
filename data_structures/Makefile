all: linked skip_list bst

linked: main.o linked.o
	$(CC) -o linked main.o linked.o -lm

skip_list: main.o skip_list.o
	$(CC) -o skip_list main.o skip_list.o -lm

bst: main.o bst.o
	$(CC) -o bst main.o bst.o -lm
	
main.o: Makefile
linked.o: Makefile
skip_list.o: Makefile
bst.o: Makefile

clean:
	rm *.o linked skip_list bst

CC=gcc

CFLAGs= -O0 -g -std=c99 -Wall -pedantic -Wwrite-strings -Wpointer-arith -Wcast-qual -Wcast-align -Wstrict-prototypes -Wmissing-prototypes -Wnested-externs -Wshadow -Winline -O

