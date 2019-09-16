#include <stdio.h>
#include <stdlib.h>
#include"basic_queue.h"

int main(){
    Queue* m_queue = init_queue();
    while(1){
        char ch;
        int d;
        scanf("%c",&ch);
        switch (ch)
        {
            case '+':
                scanf("%d",&d);
                push(m_queue,d);
                break;
            case '-':
                pop(m_queue);
                break;
            case 'v':
                view(m_queue);
                break;
            case 'q':
                return 0;
            default:
                break;
        }
    }
}