a.out: heap_functions.o client.o
	gcc heap_functions.o client.o

heap_functions.o: heap_functions.c headers.h
	gcc -c heap_functions.c

client.o: client.c headers.h
	gcc -c client.c