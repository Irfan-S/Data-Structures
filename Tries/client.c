#include "headers.h"

int main(){
    printf("\nTrie Program\n---------------------------------------\n\n");
    printf("Options:\n-1 word -> insert\n-2 word -> search for given word\n-3 -> delete\n-4 ->print all branches\n-Anything else to quit\n------------------------\n");
    char* word;
    trie* m_trie= init_trie();
    int ch;
    while(1){
        printf("Enter choice:\n");
        scanf("%d",&ch);
    switch(ch){
        case 1:
            scanf("%s",word);
            insert(word,m_trie);
            break;
        case 2:
            scanf("%s",word);
            search(word,m_trie);
            break;
        case 3:
        //TODO delete
            break;
        default:
            printf("\n-----------------------\nExiting\n-------------------------\n");
            return 0;
    }}
    return 0;
}