#include <stdio.h>
#include "headers.h"

int main(){

    int choice, loop = 1;
    int inOrder[] = {4,2,5,1,3};
    int preOrder[] = {1,2,4,5,3};
    printf("-------------------------------------\nProgram to create a binary tree\n");
    printf("- 1 for input\n- 2 for inorder\n- 4 for postorder\n- 3 for preorder\n- 5 for tree creation\n- Any key to quit\n--------------------------------------\n");
    Tree my_tree;
    tree_initialize(&my_tree);
    while (loop)
    {
        scanf("%d", &choice);
        switch (choice)
        {
            int number_of_elements, element, index;
            int data;
        case 1:
            /* Insert elements */
            scanf("%d", &element);
            tree_insert(&my_tree, element);
            break;
        case 2:
            /* Print elements in the inorder fashion */
            printf("\nPrinting inorder\n--------------------------------\n");
            preorder(&my_tree);
            break;
        case 3:
            /* Print elements in the preorder fashion */
             printf("\nPrinting preorder\n--------------------------------\n");
            inorder(&my_tree);
            break;
        case 4:
            /* Print elements in the postorder fashion */
            printf("\nPrinting postorder\n--------------------------------\n");
            postorder(&my_tree);
            break;
        case 5:
            /*Accepts inorder and preorder traversals of a tree and creates a Tree*/
            tree_generator_handler(&my_tree);
            break;
        default:
            tree_destroy(&my_tree);
            loop = 0;
            break;
        }
    }
    return 0;
}