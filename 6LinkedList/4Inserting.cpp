#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n){
    int i;
    struct Node *t,*last;
    first = new struct Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=new struct Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void Insert(struct Node *p,int x,int pos ){
    Node *t=new Node;
    if(pos==0){
      t->data=x;
      t->next=first;
      first=t;
    }
    else{
        t->data=x;
        p=first;
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}
void Sortinsert(struct Node *p,int x){
    struct Node *q;
    p=first;
    q=NULL;
    while(p && p->data < x){
        q=p;
        p=p->next;   
    }
    struct Node *t;
    t=new struct Node;
    t->data=x;
    t->next=q->next;
    q->next=t;
}
void Display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}


int main(){
    int A[]={3,5,7,10,15};
    create(A,5);
    Insert(first,2,2);
    Sortinsert(first,9);
    Display(first);
    return 0;
}