//S = Static D=Dynamic
#include <iostream>
using namespace std;

int main(){
    //To Allocate memory in stack
    int A[5]={1,2,3,4,5};
    cout<<A[1]<<endl;
     
    //To Allocate memory in Heap
    int *B;
    B= new int[5];
    B[0]=1,B[1]=3,B[2]=7,B[3]=5,B[3]=9;
    cout<<B[1];
    delete []B;//To Dealocate the memory
    return 0;
}