#include "headers.h"

#define SIZE 26

trie* init_trie(char* prev){
    trie *pNode = NULL; 
  
    pNode = malloc(sizeof(trie)); 
  
    if (pNode) 
    { 
        int i; 
  
        pNode->end_of_word = false; 
  
        for (i = 0; i < SIZE; i++) 
            pNode->array[i] = NULL; 
    } 
    pNode->word_so_far = prev;
    return pNode; 
}



void insert(char* word, trie* tr){
    char ch;
    char* wrds = malloc(sizeof(char)*strlen(word));
    trie* rover = tr;
    for(int i=0;i<strlen(word);i++){
        ch = word[i];
        wrds[i]=ch;
        
        int index = atoi(ch)- atoi('a');
        if(!rover->array[index]){
            rover->array[i] = init_trie(wrds);
        }
        rover = rover->array[i];
    }
    rover->end_of_word = true;
}

bool search(char* word, trie* tr){
    char ch;
    trie* rover = tr;
    for(int i=0;i<strlen(word);i++){
        ch = word[i];
        
        int index = atoi(ch)- atoi('a');
        if(!rover->array[index]){
            return false;
        }
        rover = rover->array[i];
    }
    return (rover!=NULL && rover->end_of_word);
}