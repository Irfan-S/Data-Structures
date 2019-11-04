typedef struct heap{
    int len;
    int max;
    int* arr;
} heap;

heap* create_heap(int len);
void insert_heap(int ele, heap* heap);
void max_ele(heap* heap);
void print_heap(heap* heap);
void delete_ele(int ele, heap* hp);
