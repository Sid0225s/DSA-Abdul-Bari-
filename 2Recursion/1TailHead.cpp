#include <bits/stdc++.h>
using namespace std;


void fun(int n){
    if(n>0){
    fun(n-1);
    cout<<n<<endl;
    // fun(n-1); tail recursion
    }
}
int main(){
    int x=3;
    fun(x);
    return 0;
}