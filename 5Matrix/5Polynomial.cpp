#include <iostream>
using namespace std;

struct Term {
    int exp;
    int coeff;
};

struct Poly {
    int n;
    struct Term *t;
};

struct Poly add(struct Poly *p1,struct Poly *p2){
          struct Poly *sum;
          sum = new struct Poly;
          sum->t= new struct Term[p1->n+p2->n];
          int i=0,j=0,k=0;
          while(i<p1->n && j<p2->n){
          if(p1->t[i].exp < p2->t[i].exp){
            sum->t[k++]=p2->t[j++];
          }
          else if(p1->t[i].exp > p2->t[i].exp){
            sum->t[k++]=p1->t[i++];
          }
          else{
            sum->t[k].exp=p1->t[i].exp;
            sum->t[k++].coeff=p1->t[i++].coeff+p2->t[j++].coeff; 
          }
        }
        for(;i<p1->n;i++)sum->t[k++]=p1->t[i];
        for(;j<p2->n;j++)sum->t[k++]=p2->t[j];

        sum->n=k;
        return *sum;
}

void create(struct Poly *p) {
    cout<<"no. of terms"<<endl;
    cin >> p->n;
    cout<<"enter Terms"<<endl;
    p->t = new Term[p->n];
    for (int i = 0; i < p->n; i++) {
        cin >> p->t[i].coeff >> p->t[i].exp;
    }
}  
void Display(struct Poly p){
    for(int i=0;i<p.n;i++){
        cout<<p.t[i].coeff<<"x^"<<p.t[i].exp<<"+";
    }
}


int main(){
    struct Poly p1,p2,sum;
    create(&p1);
    create(&p2);
    sum=add(&p1,&p2);
    Display(sum);
    return 0;
}