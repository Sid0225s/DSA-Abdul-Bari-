#include <iostream>
using namespace std;


// int fib (int n){
//     if (n<2)
//         return n;
//     return fib(n-2) + fib(n-1);
// }
// int main(){
//     cout<<fib(7);
//     return 0;
// }

// Using Memoisation
int F[10];
int mfib(int n){
    if(n<2){
        F[n]=n;
        return n;
    }
    else{
        if(F[n-2]== -1)
            F[n-2] = mfib(n-2);
        if(F[n-1]== -1)
            F[n-1] = mfib(n-1);
        return F[n-2]+ F[n-1];
    }

}
int main(){
    int i;
    for(i=1;i<10;i++){
        F[i]=-1;
    }
  cout<<mfib(6);
  return 0;
}