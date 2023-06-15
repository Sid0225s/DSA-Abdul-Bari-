#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[],int n){
    struct  Node *t,*sec;
    first=new struct Node; 
    first->data=A[0];
    first->next=NULL;
    sec=first;
   
    for(int i=1;i<n;i++){
        t=new struct Node;
        t->data=A[i]; 
        t->next=NULL;
        sec->next=t;
        sec=t;
    }
}
int count(struct Node *p){
    int cont=0;
    while(p!=0){
       cont++;
       p=p->next;
    }
    cout<<endl;
    cout<<cont;
    return 0;
}

int sum(struct Node *p){
    int cont=0;
    while(p!=0){
       cont=cont+p->data;
       p=p->next;
    }
    cout<<endl;
    cout<<cont;
    return 0;
}

void Display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}

int max(struct Node *p){
    int m=-32000;
    while(p!=0){
        if(p->data>m){
            m=p->data;
            p=p->next;
        }
    }
    cout<<endl;
    cout<<m;
    return 0;
}

int main(){
    int A[]={3,5,7,10,15};
    create(A,5);
    Display(first);
    count(first);
    max(first);
    sum(first);
    return 0;
}