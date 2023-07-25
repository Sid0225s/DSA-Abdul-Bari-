#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*Head;


void create(int A[],int n){
    struct Node *t,*last;
    Head = new struct Node;
    Head->data=A[0];
    Head->next=Head;
    last=Head;

    for(int i=1;i<n;i++){
        t=new struct Node;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
void display(struct Node *h){ 
    do{
        cout<<h->data<<" ";
        h=h->next;
    }while(h!=Head);
}
void Insert(struct Node *p,int x,int n){
    struct Node *t;
    struct Node *q=Head;
    t=new struct Node;
    t->data=x;
    if(n==0){ 
        t->next=Head;
        while(q->next!=Head){
            q=q->next;
        }
        q->next=t;
        Head=t;
    }
    else {
       for(int i=0;i<n-1;i++){
        q=q->next;
       }
       t->next=q->next;
       q->next=t;
    }
    
}


int main(){
    int A[]={1,2,3,4,5};
    create(A,5);
    Insert(Head,9,5);
    display(Head);   
    return 0;
}