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

void Delete(struct Node *p,int pos){
    if(pos>0){
        struct Node *p=first;
        struct Node *q=NULL;
        for(int i=0;i<pos-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
    }
    else{
        struct Node *p=first;
        first=first->next;
        delete p;
    }
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
    Delete(first,1);
    Display(first);
    return 0;
}