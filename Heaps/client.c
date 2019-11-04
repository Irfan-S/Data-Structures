#include <stdio.h>
#include "headers.h"

int main(){
    printf("Program to demonstrate heap\n---------------------------------------------\n");
    printf("Length of heap?");
    int len =0;
    scanf("%d",&len);
    heap* hp = create_heap(len);
    printf("\n- 1 x to insert 'x' element\n- 2 x to delete 'x' from heap\n- 3 to return max of heap\n- 4 to print heap\n- 0 to exit\n---------------------------------------\n");
    int ch=1;
    while(ch){
        //Enter your choice.
        scanf("%d",&ch);
        int ele;
        switch (ch)
        {
        case 1:
            scanf("%d",&ele);
            insert_heap(ele,hp);
            break;
        case 2:
            scanf("%d",&ele);
            delete_ele(ele,hp);
            break;
        case 3:
            max_ele(hp);
            break;
        case 4:
            print_heap(hp);
            break;
        default:
            break;
        }
    }
    return 0;
}