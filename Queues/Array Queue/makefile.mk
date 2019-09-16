a.out: basic_queue.o client_basic.o
	gcc basic_queue.o client_basic.o

basic_queue.o: basic_queue.c basic_queue.h
	gcc -c basic_queue.c

client_basic.o: client_basic.c basic_queue.h
	gcc -c client_basic.c