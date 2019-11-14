#include "headers.h"

#define SIZE 26

trie* init_trie(){
    //printf("Initializing new trie node\n");
    trie *pNode = NULL; 
  
    pNode = malloc(sizeof(trie)); 

        int i; 
  
        pNode->end_of_word = false; 
  
        for (i = 0; i < SIZE; i++) 
            pNode->array[i] = NULL;  
    // pNode->word_so_far = prev;
    return pNode; 
}


void insert(char* word, trie* tr){
    printf("Inserting %s\n------------------------------\n",word);
    trie* temp = tr;
    for(int i=0;word[i];i++){
        if(temp->array[word[i]-'a']==NULL){
            temp->array[word[i]-'a'] = init_trie(NULL);
        }
        temp = temp->array[word[i]-'a'];
    }
    temp->end_of_word = true;
}

void search(char* word, trie* tr){
    printf("Searching for %s\n------------------------------\n",word);
    trie* temp = tr;
    for(int i=0;word[i];i++){
        if(temp->array[word[i]-'a']){
            temp = temp->array[word[i]-'a'];
        }
        else{
            printf("Word not found\n------------------------------------\n");
            return;
        }
    }
    if(temp->end_of_word){
        printf("Word found\n------------------------------------\n");
    }else{
        printf("Word not found\n------------------------------------\n");
    }
}