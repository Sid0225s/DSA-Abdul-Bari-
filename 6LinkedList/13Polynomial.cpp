#include <iostream>
using namespace std;

struct Node{
    int coeff;
    int exp;
    struct Node *next;
}*poly=NULL;

void create(int n){
  struct Node *t,*last;
  for(int i=0;i<n;i++){
    t=new struct Node;
     cin>>t->coeff>>t->exp;
     if(poly==NULL){
      poly=last=t;
     }
     else{
      last->next=t;
      last=t;
     }
  }
} 

void Display(struct Node *p){
   while(p){
    cout<<p->coeff<<"x^"<<p->exp<<"+";
    p=p->next;
   }
}


int main(){
  create(3);
  Display(poly);
  return 0;
}