a.out: adjacency_multilist.o client.o
	gcc adjacency_multilist.o client.o

adjacency_multilist.o: adjacency_multilist.c headers.h
	gcc -c adjacency_multilist.c

client.o: client.c headers.h
	gcc -c client.c