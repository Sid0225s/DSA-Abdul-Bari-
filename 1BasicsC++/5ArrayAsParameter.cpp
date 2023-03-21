#include <bits/stdc++.h>
using namespace std;

void fun(int A[ ],int n){
    for(int i=0;i<5;i++){
        cout<<A[i]<<endl;
    }
};
 
int main(){
    int A[]= {2,3,4,5,6};
    int n=5;
    fun(A,n);
    for(int x:A ){//for each loop is used
        cout<<x<<endl;
    }
    return 0;
}