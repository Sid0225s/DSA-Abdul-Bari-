#include <iostream>
using namespace std;

int main(){
    int *p,*q;
    p= new int[3];
    p[0]=1,p[1]=3,p[2]=7;
    q= new int[6];
    for(int i=0;i<3;i++){
        q[i]=p[i];
    }
    delete []p;
    p=q;
    q=NULL;
    for(int i=0;i<6;i++){
        cout<<p[i]<<endl;
    }
    return 0;
}