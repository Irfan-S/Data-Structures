typedef struct Node {
	int data;
	struct Node *link;
} Node;

typedef struct List {
	Node* head;
	int number_of_nodes;
} List;

/* initializes a linked list */
List* list_initialize(); 

/* Inserts a new node with data at the beginning */
void list_insert_beginning(List* list, int data);

/* Removes the last node of the linked list */
void list_delete_rear(List* list); 

/* Print the contents of a list */
void list_print(List* list); 

/* Sorts a linked list */
void list_sort(List*);

/* deallocates resources held by the list */
void list_destroy(List* list);