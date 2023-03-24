#include <iostream>
using namespace std;

int fact(int n){
    if(n<2)
      return n;
    return fact(n-1)*n;
}

int main(){
    cout<<fact(5);
    return 0;
}