a.out: linkedlist.o client.o
	gcc linkedlist.o client.o

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c

client.o: client.c linkedlist.h
	gcc -c client.c