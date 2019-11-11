a.out: trie_functions.o client.o
	gcc trie_functions.o client.o

trie_functions.o: trie_functions.c headers.h
	gcc -c trie_functions.c

client.o: client.c headers.h
	gcc -c client.c