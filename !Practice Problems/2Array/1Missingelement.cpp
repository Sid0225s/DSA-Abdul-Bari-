#include <iostream>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

int Display(struct Array arr){
    for(int i=0;i<arr.length;i++){
        cout<<arr.A[i]<<endl;
    }
    return 0;
}

void Missing(struct Array *arr,int n){
   int i;
   int l= arr->length;
   for(i=0;i<l-1;i++){
    if(arr->A[i+1]-arr->A[i] != n){
    cout<<arr->A[i]+n<<" ";
    }
    continue; 
   }

}

int main(){
    Array arr = {{1,2,3,5,6,8,9},10,7};
    Missing(&arr,1);
    
    return 0;
}