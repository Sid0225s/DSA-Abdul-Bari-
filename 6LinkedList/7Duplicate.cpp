#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next; 
}*first=NULL;

void create(int A[],int n){
    struct Node *t,*last;
    first=new struct Node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    
    for(int i=1;i<n;i++){
        t= new struct Node;  
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

void deleteDuplicate(struct Node *p){
    struct Node *q;
    q=p->next;
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

int main(){
    int A[]={3,5,5,10,15};
    create(A,5);
    Display(first);
    deleteDuplicate(first);
    cout<<endl;
    Display(first);
    return 0;
}