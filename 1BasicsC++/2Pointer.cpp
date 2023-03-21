#include <iostream>
using namespace std;
int main(){
    // int A[5] = {1,2,3,4,5};
    // int *p,a;
    // // a=10;
    // // p=&a;
    // p=A; // if you use '&' than you may get error
  

    //CREATING A POINTER TO GET MEMORY IN HEAP
     int *p;
     p = new int [5];
     p[0]=1;p[1]=2;p[2]=3;p[3]=4;p[4]=5;
     
     for (int i=0; i<5;i++){
        cout<<p[i]<<endl;
    }
    cout<<sizeof(p);//POINTER ALWAYS TAKE 8 BYTE OF MEMORY in 64 bit system
    delete [ ] p;// used to dealocating the memory in Heap
    return 0;
}