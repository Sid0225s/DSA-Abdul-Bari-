#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};
void Reverse( struct Array *arr){
    int i,j;
    int *B;
    B= new int[10];
     for(i=arr->length-1,j=0;i>=0;i--,j++){
       B[j]=arr->A[i]; 
     }
     for(i=0;i<arr->length;i++){
            arr->A[i]=B[i];
        } 
      delete []B;

    // 2ND METHOD 
    //Without use of B
    // for(i=arr->length-1,j=0;j<i;i--,j++){
    //   int temp = arr->A[i];
    //   arr->A[i]=arr->A[j];
    //   arr->A[j]=temp;
    // }
}
int Display(struct Array arr){
    for(int i=0;i<arr.length;i++){
        cout<<arr.A[i]<<endl;
    }
    return 0;
}
int main(){
    Array arr={{1,2,3,5,9},6,5};
    Reverse(&arr);
    Display(arr); 
    return 0;
}