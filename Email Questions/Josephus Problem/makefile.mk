a.out: josephus_functions.o client.o
	gcc josephus_functions.o client.o

josephus_functions.o: josephus_functions.c josephus.h
	gcc -c josephus_functions.c

client.o: client.c josephus.h
	gcc -c client.c