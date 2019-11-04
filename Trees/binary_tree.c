#include "headers.h"

Node* create_node(int data){
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
int search(int* arr, int ele,int start,int end){
    int i;
    for(i=start;i<end;i++){
        if(arr[i]==ele){
            return i;
        }
    }
}

void tree_generator_handler(Tree* tree){
    printf("\nEnter the number of elements in the tree:");
            int n=0;
            scanf("%d",&n);
            int* inOrder = (int*)malloc(sizeof(int)*n);
            int* preOrder = (int*)malloc(sizeof(int)*n);
            printf("%d",n);
            printf("\nEnter the elements in inorder:");
            for(int i=0;i<n;i++){
                scanf("%d",(inOrder+i));
                printf("%d",*(inOrder+i));
            }
            printf("\nEnter the elements in preorder:");
            for(int i=0;i<n;i++){
                scanf("%d",(preOrder+i));
                printf("%d",*(preOrder+i));
            }
            tree->root = build_tree(inOrder,preOrder,0,n-1);
            printf("\nTree successfully built...\n");
}

Node* build_tree(int* in, int* pre,int inStart, int inEnd){
    static int preIndex =0;
    if(inStart>inEnd){
        return NULL;
    }
    int ele = pre[preIndex++];
    Node* tNode = create_node(ele);
    if(inStart==inEnd){
        return tNode;
    }
    int inIndex = search(in,tNode->data,inStart,inEnd);
    tNode->left = build_tree(in,pre,inStart,inIndex-1);
    tNode->right = build_tree(in,pre,inIndex+1,inEnd);
    return tNode;
}

// void build_tree(Tree* tree,int* in, int* pre,int inStart, int inEnd){
//     tree->root = node_build_tree(in,pre,inStart,inEnd);
// }

void tree_initialize(Tree *tree)
{
    tree->root = NULL;
}

void tree_insert(Tree *tree, int data)
{
    Node* t = create_node(data);
    if(tree->root==NULL){
        tree->root = t;
    }else{
        Tree* nt = malloc(sizeof(Tree));
        if(tree->root->data > data){
            nt->root = tree->root->left;
            tree_insert(nt,data); 
            tree->root->left = nt->root;
        }else if(tree->root->data < data){
            nt->root = tree->root->right;
            tree_insert(nt,data);
            tree->root->right = nt->root;
        }
    }
}

void tree_inorder(Node *r)
{
    if(r==NULL){
        return;
    }else{
        tree_inorder(r->left);
        printf("%d ",r->data);
        tree_inorder(r->right);
    }
    // TODO
}

void tree_preorder(Node *r)
{
    if(r==NULL){
        return;
    }else{
        printf("%d ",r->data);
        tree_preorder(r->left);
        tree_preorder(r->right);
    }
    // TODO
}

void tree_postorder(Node *r)
{
    if(r==NULL){
        return;
    }else{
        
        tree_postorder(r->left);
        tree_postorder(r->right);
        printf("%d ",r->data);
    }
    // TODO
}

void postorder(Tree *t)
{
    tree_postorder(t->root);
    printf("\n");
    // TODO
}

void preorder(Tree *t)
{
    tree_preorder(t->root);
    printf("\n");
    // TODO
}

void inorder(Tree *t)
{
    tree_inorder(t->root);
    printf("\n");
    // TODO
}

void destroy(Node *r)
{
    if(r){
        destroy(r->left);
        destroy(r->right);
        free(r);
    }else{
        return;
    }
    // TODO
}

void tree_destroy(Tree *t)
{
    destroy(t->root);
    // TODO
}