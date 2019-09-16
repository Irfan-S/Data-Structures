#include <stdio.h>
#include "linkedlist.h"

int main() {
	int choice;
	List *list = list_initialize();
	do {
		scanf("%d", &choice);
        //printf("User entered: %d\n",choice);
		switch(choice) {
			int element;
			case 1:
				/* Insert an element at beginning of the list */ 
					scanf("%d", &element);
					list_insert_beginning(list, element);
					break;
			case 2:
				/* Remove rear elements */ 
					list_delete_rear(list);
					break;
			case 3:
				/* Print list contents */ 
				    list_print(list);
				    break;
            case 4:
                /* Sort list */
                list_sort(list);
                break;        
			default: 
				    list_destroy(list);
				    break;
		}
	} while(choice >= 1 && choice < 5);
	
	return 0;
}