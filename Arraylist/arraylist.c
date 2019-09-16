#include <stdio.h>
#include <stdlib.h>

typedef struct arraylist{
    int* array;
    int count;
    int maxsize;
} ArrayList;

ArrayList initialize();
void setup(ArrayList*,int);
void delete_at_pos(ArrayList*,int);
void delete_element(ArrayList*,int);
void insert(ArrayList*,int,int);
ArrayList copy(ArrayList*);
void display(ArrayList);
ArrayList merge(ArrayList*,ArrayList*);

int main(){
    ArrayList m_arraylist;
    m_arraylist=initialize();
    //printf("Size of arraylist: ");
    int sz;
    scanf("%d",&sz);
    setup(&m_arraylist,sz);
    int ele,pos;
    char c='r';
    while(c!='q'){
        //ask user for input choice, i to insert, d to delete, e to delete element, p to print,c to copy, m to merge, s to sort, q to stop.
        scanf("%c",&c);
        switch (c)
        {
        case 'i':
            //ask user for ele and pos
            scanf("%d %d",&ele,&pos);
            insert(&m_arraylist,ele,pos);
            break;
        
        case 'd':
            //ask user for pos
            scanf("%d",&pos);
            delete_at_pos(&m_arraylist,pos);
            break;

        case 'e':
            //ask user for element to be deleted
            scanf("%d",&ele);
            delete_element(&m_arraylist,ele);
            break;

        case 'p':
            display(m_arraylist);
            break;

        case 'c':
            ArrayList m_arraylist2;
            m_arraylist2 = copy(&m_arraylist);
            printf("Printing copy..\n");
            display(m_arraylist2);
            printf("Printing original..\n");
            display(m_arraylist);
            break;

        case 'm':
            ArrayList m_arraylist_merged;
            //todo
            break;

        case 's':
            break;
                    
        default:
            break;
        }
    }
}


ArrayList initialize(){
    ArrayList a;
    a.array = NULL;
    a.count = 0;
    a.maxsize=0;
    return a;
}

void setup(ArrayList* temp, int sz){
    temp->array = (int*)malloc(sz*sizeof(int));
    temp->maxsize = sz;
}

void insert(ArrayList* temp,int ele,int pos){
    if(pos<=temp->count && temp->count<temp->maxsize){
        int t = temp->array[pos];
        temp->array[pos]=ele;
        for(int i=pos+1;i<temp->count+1;i++){
            int c = temp->array[i];
            temp->array[i]=t;
            t=c;
        }
        temp->count++;
    }else{
        printf("Invalid location entered.\n");
    }
}

void display(ArrayList temp){
    if(temp.count>0){
        printf("Printing ArrayList:\n");
        for(int i=0;i<temp.count;i++){
            printf("%d ",temp.array[i]);
        }
        printf("\n");
    }else{
        printf("Empty\n");
    }
}

void delete_at_pos(ArrayList* temp, int pos){
    if(pos<temp->count){
        int i;
        for(i=pos;i<temp->count-1;i++){
            temp->array[i] = temp->array[i+1];
        }
        temp->array[i]=NULL;
    }else
    {
        printf("No element here.\n");
    }
    
}

void delete_element(ArrayList* temp, int ele){
    int pos=-1;
    for(int i=0;i<temp->count;i++){
        if(temp->array[i]==ele){
            pos=i;
            break;
        }
    }
    if(pos>=0
    ){
        delete_at_pos(temp,pos);
    }else{
        printf("Element not present.\n");
    }
}

ArrayList copy(ArrayList* a1){
    ArrayList m_copy;
    m_copy = initialize();
    setup(&m_copy,a1->maxsize);
    m_copy.count = a1->count;
    for(int i=0;i<m_copy.count;i++){
        m_copy.array[i] = a1->array[i];
    }
    return m_copy;
}

ArrayList merge(ArrayList* a1, ArrayList* a2){
    ArrayList n;
    n = initialize();
    setup(&n,a1->count+a2->count);
    int i=0,j=0,k=0;;
    while(i<a1->count && j<a2->count){
        if(a1->array[i]<a2->array[j]){
            n.array[k]=a1->array[i];
            i++;
        }else if(a1->array[i]<a2->array[j]){
            n.array[k]=a2->array[j]; 
            j++;
        }
        k++;
    }
    while (i<a1->count)
    {
        n.array[k]=a1->array[i];
        i++,k++;
    }
    while (j<a2->count)
    {
        n.array[k]=a2->array[j];
        j++,k++;
    }
    return n;
 
}


