#include <iostream>
using namespace std;

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n){
    struct Node *t,*last;
    first = new struct Node;
    first->data = A[0];
    first->prev=first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){
        t=new struct Node;
        t->data=A[i];
        t->prev=last;
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p){
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}

void Insert(struct Node *p,int x,int n){
    struct Node *t;
    t=new struct Node;
    t->data=x;
    struct Node *q=first;
    if(n==0){
        t->next=first;
        t->prev=NULL;
        first->prev=t;
        first=t;
    }
    else{
        for(int i=0;i<n-1;i++){
            q=q->next;
        }
        t->next=q->next;
        t->prev=q;
        q->next->prev=t;
        q->next=t;
    }
}

void Delete(struct Node *p,int n){
    struct Node *t;
    t=first;
    struct Node *q;
    if(n==0){
    first=first->next;
    first->prev=NULL;
    delete t;
    }
    else{
        for(int i=0;i<n;i++){
            q=t;
            t=t->next;
           
        }
        q->next=t->next;
        t->next->prev=q;
        delete t;
    }
}

void Reverse(struct Node *q){
    struct Node *t;
    while(q!=NULL){
     t=q->next;
     q->next=q->prev;
     q->prev=t;
     q=q->prev;

     if(q!=NULL && q->next== NULL){
        first=q;
     }
    } 
    
}

int main(){
    int A[]={3,5,7,10,15};
    create(A,5);
    Reverse(first);
    Display(first);
    return 0;
}