a.out: infix_to_postfix.o postfix_solver.o client.o
	gcc infix_to_postfix.o postfix_solver.o client.o
infix_to_postfix.o: infix_to_postfix.c conv.h
	gcc -c infix_to_postfix.c
postfix_solver.o: postfix_solver.c conv.h
	gcc -c postfix_solver.c
client.o: client.c conv.h
	gcc -c client.c