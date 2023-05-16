#include <iostream>
using namespace std;


struct Array {
    int A[10];
    int length=10;
    int size =10;
};

int binarySearch(struct Array arr, int key){
    int s,e,mid;
    s=0;
    e=arr.length-1;
    while(s<=e){
        mid=(s+e)/2;
    if(arr.A[mid]==key){
        return mid;
    }
    else if(arr.A[mid]<key){
        s=mid+1;
    }
    else{
        e=mid-1;
    }
    }
    return -1;
}
int main(){
    Array arr = {{1,2,3,4,5,7,5,32,2},10,9};
    cout<<binarySearch(arr,3);
    
    return 0;
}