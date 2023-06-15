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
int search(struct Node *p,int x){
    struct Node *q;
    while(p!=0){
        if(x==p->data){
          q->next=p->next;
          p->next=first;
          first=p;
          return p->data;
        }
        else{
            q=p;
            p=p->next;
        }
    }
    return NULL;
    
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
    Display(first);
    search(first,7);
    // Display(first);
    return 0;
}