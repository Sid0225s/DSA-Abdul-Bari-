#include <iostream>
using namespace std;

struct Matrix
{
    int A[10];
    int n;
};

void Set(struct Matrix *m, int i,int j, int x){
    if(i==j){
        m->A[i-1]=x;
    }
}
int get(struct Matrix m,int i , int j){
    if(i!=j){
        cout<<0;
    }
    else{
        cout<<m.A[i-1];
    }
    return 0;
}
void Display(struct Matrix m){
    int i,j;
    for(i=0;i<m.n;i++){
     for(j=0;j<m.n;j++){
        if(i==j){
            cout<<m.A[i];
        }
        else{
            cout<<0;
        }
     }
     cout<<endl;
    }
}

int main(){
    Matrix m;
    m.n=4;
    Set(&m,1,1,5); Set(&m,2,2,6); Set(&m,3,3,2); Set(&m,4,4,1);

    Display(m);
    return 0;
}