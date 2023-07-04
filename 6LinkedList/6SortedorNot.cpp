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

int Check(struct Node *p){
    int x;
    struct Node *q=first;
    x=first->data;
    first=first->next;
    while(p!=NULL){
        if(p->data<x){
            return 0;
        }
        x=p->data;
        p=p->next;
    } 
    return 1;
    
}

void Display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}


int main(){
    int A[]={3,5,4,10,15};
    create(A,5);
    if(Check(first)){
        cout<<"sorted";
    }
    else{
        cout<<"Not sorted";
    }
    return 0;
}