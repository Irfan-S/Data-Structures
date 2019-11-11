#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct c
{
    struct t* array[26];
    bool end_of_word;
    char* word_so_far;
} trie;


trie* init_trie();
void insert(char* word, trie* trie);
bool search(char* word, trie* trie);

//TODO create a suggestion system
