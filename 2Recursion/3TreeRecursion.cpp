#include <bits/stdc++.h>
using namespace std;

int fun(int n){
    if(n>0){
        cout<<n<<endl;
        fun(n-1);
        fun(n-1);
    }
    return 0;
}

int main(){
    fun(3);
    return 0;
}