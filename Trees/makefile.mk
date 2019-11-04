a.out: binary_tree.o client.o
	gcc binary_tree.o client.o

binary_tree.o: binary_tree.c headers.h
	gcc -c binary_tree.c

client.o: client.c headers.h
	gcc -c client.c