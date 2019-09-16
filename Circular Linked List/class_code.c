#include<stdio.h>
#include<stdalign.h>
typedef struct node{
    int exp;
    int coeff;
    struct node* link;
};
typedef struct node polynode;

void attach(polynode* start,int exp,int c){
    if (c!=0){
        polynode* d_start = start;
        polynode* new_node = malloc(sizeof(polynode));
        new_node->coeff = c;
        new_node->exp = exp;
        new_node->link= NULL;
        while(d_start->link!=start){
            d_start = d_start->link;
        }
        d_start->link = new_node;
        new_node->link = start;
    }
}

void readpoly(polynode* start){
    int c,e,ch=1;
    while(ch){
        polynode* d_start = start;
        scanf("%d %d",&c,&e);
       
        scanf("%d",&ch);
    }

}

void addpoly(polynode* a, polynode* b, polynode* c){
     polynode *da, *db;
     da = a->link;
     db = b->link;
     while(da->link!=a && db->link!=db){
         //case1 - exp of current term of a is greater than b.
        if(da->exp>db->exp){
            attach(c,da->exp,da->coeff);
            da = da->link;
        }
         //case2 - exp of current term of B>A.
        else if(db->exp>da->exp){
            attach(c,db->exp,db->coeff);
            db = db->link;
        }
         //case3 - exp of A==B
        else{
            attach(c,da->exp,da->coeff+db->coeff);
            da = da->link;
            db = db->link;
        }
     }
     for(;da->link!=a;da=da->link){
         attach(c,da->exp,da->coeff);
     }
     for(;db->link!=b;db=db->link){
         attach(c,db->exp,db->coeff);
     }
}

//destroy and display

int main(){
    polynode* starta,*startb,*startc;
    starta = malloc(sizeof(polynode));
    startb = malloc(sizeof(polynode));
    startc = malloc(sizeof(polynode));

    starta->link = starta;
    startb->link = startb;
    startc->link = startc;

    readpoly(starta);
    readpoly(startb);
    addpoly(starta,startb,startc);
    display(startc);
    //destroy all memory being used.
    
}
