a.out: towers_of_hanoi_functions.o client.o
	gcc towers_of_hanoi_functions.o client.o

towers_of_hanoi_functions.o: towers_of_hanoi_functions.c func.h
	gcc -c towers_of_hanoi_functions.c

client.o: client.c func.h
	gcc -c client.c