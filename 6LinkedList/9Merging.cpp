#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

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
void create2(int B[], int n){
    int i;
    struct Node *t,*last;
    second = new struct Node;
    second->data=B[0];
    second->next=NULL;
    last=second;

    for(i=1;i<n;i++){
        t=new struct Node;
        t->data=B[i];
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

//For sorted LinkedList
void Merge(struct Node *p, struct Node *q) {
    struct Node  *last;

    if (p->data < q->data) {
        third = last = p;
        p = p->next;
        last->next = NULL;
    } else {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }

    while (p && q) {
        if (p->data < q->data) {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        } else {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p) {
        last->next = p;
    } else if (q) {
        last->next = q;
    }
}



int main(){
    int A[]={3,5,7,10,15};
    int B[]={1,2,6,8,9};
    create(A,5);
    create2(B,5);
    Display(first);
    cout<<endl;
    Display(second);
    cout<<endl;
    Merge(first,second);
    Display(third);
    return 0;
}