#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

typedef struct tree
{
    Node *root;
} Tree;

void tree_initialize(Tree *tree);
void tree_insert(Tree *tree, int data);

void inorder(Tree *tree);
void preorder(Tree *tree);
void postorder(Tree *tree);

void tree_destroy(Tree *tree);
Node* build_tree(int*,int*,int,int);
void tree_generator_handler(Tree* tree);

/**
 * TODO Implement following:
 * - Delete node
 * - Copy
 * - Mirror
 * - Create a tree given inorder and pre/postorder?
 **/
