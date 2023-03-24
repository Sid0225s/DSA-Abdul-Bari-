#include <iostream>
using namespace std;

// Using recursion 
int pow(int m, int n){
    if(n==0)
       return 1;
    return pow(m,n-1)*m;
}

//To reduce number of Multiplications
int power(int m ,int n){
    if(n==0){
        return 1;
    }
    if(n%2==0){
        return power(m*m,n/2); 
    }
    else{
        return m * power(m*m,(n-1)/2);
    }
}

int main(){
    cout<<pow(2,3)<<endl;
    cout<<power(3,7);
    return 0;
}