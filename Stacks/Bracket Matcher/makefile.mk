a.out: bracket_checker.o client.o
	gcc bracket_checker.o client.o
bracket_checker.o: bracket_checker.c conv.h
	gcc -c bracket_checker.c
client.o: client.c conv.h
	gcc -c client.c