a.out: cll_queue.o client.o
	gcc cll_queue.o client.o

cll_queue.o: cll_queue.c cll_queue.h
	gcc -c cll_queue.c

client.o: client.c cll_queue.h
	gcc -c client.c