a.out: graph.o client.o
	gcc graph.o client.o

graph.o: graph.c defs.h
	gcc -c graph.c

client.o: client.c defs.h
	gcc -c client.c