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
void Display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}

void Reverse1(struct Node *p){
    int i=0;
    int A[10];
    while(p!=NULL){
        A[i]=p->data;
        p=p->next;
        i++;
    }
    p=first;i--;
    while (p!=NULL)
    {
        p->data=A[i--];
        p=p->next;
    }
    
}

void Reverse2(struct Node *p){
    struct Node *q,*r;
    p=first;
    q=NULL;
    r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next; 
        q->next=r;
    }
    first=q;//now q will becom first Node
}

// using Recursion 
void Reverse3(struct Node *q,struct Node *p){
    if(p){
        Reverse3(p,p->next);
        p->next=q;
    }
    else{
        first=q;
    }
}


int main(){
    int A[]={3,5,7,10,15};
    create(A,5);
    // Reverse1(first);
    // Reverse2(first);
    Reverse3(NULL,first);
    Display(first);
    return 0;
}