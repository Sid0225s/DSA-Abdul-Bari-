#include <bits/stdc++.h>
using namespace std;

int main(){
    int a=4;
    int &r = a; // r is like a nick name 
    cout<<a<<endl<<r<<endl;
    r=20;
    cout<<a<<endl<<r;
    return 0;
}