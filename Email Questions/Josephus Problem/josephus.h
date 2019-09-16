typedef struct n{
    int position;
    struct n* next;   
} Person;

typedef struct q{
    int person_count;
    Person* first;
} Queue;

Queue* init_queue();

//TODO