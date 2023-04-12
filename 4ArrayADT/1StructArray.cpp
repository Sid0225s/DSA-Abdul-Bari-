#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

int Display(struct Array arr){
    for(int i=0;i<arr.length;i++){
        cout<<arr.A[i]<<endl;
    }
    return 0;
}

int main(){
    Array arr;
    int n,i;
    cin>>arr.size;
    arr.A = new int[arr.size];
    arr.length = 0;
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr.A[i];
    }
    arr.length=n;
    Display(arr);
    return 0;
}