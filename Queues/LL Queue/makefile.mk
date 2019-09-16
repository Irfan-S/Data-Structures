a.out: ll_queue.o client.o
	gcc ll_queue.o client.o

ll_queue.o: ll_queue.c ll_queue.h
	gcc -c ll_queue.c

client.o: client.c ll_queue.h
	gcc -c client.c