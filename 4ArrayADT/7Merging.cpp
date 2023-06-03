#include <iostream>
using namespace std;

struct  Array 
{
    int A[10];
    int size;
    int length;
};


int mergeArray(struct Array *arr1,struct Array *arr2){
  int i,j,k;
  i=0;j=0;k=0;
  int *B;
  B= new int[20];
  int m=arr1->length;
  int n=arr2->length;
  while(i<m && j<n ){
       if(arr1->A[i]<arr1->A[j]){
        B[k++]=arr1->A[i++];
       }
       else{
        B[k++]=arr1->A[j++];
       }
  }
  for(;i<m;i++){
    B[k++]=arr1->A[i++];
  }
  for(;j<n;j++){
    B[k++]=arr1->A[j++];
  }
  int d=arr1->length+arr2->length;
  for(int k=0;k<d;k++){
    cout<<B[k]<<" ";
     }
  delete []B;
  return 0;
}

int main(){
    Array arr1={{1,2,3,4,5},6,5};
    Array arr2={{2,4,5,6,7,8},7,6};
    mergeArray(&arr1,&arr2);
    
    return 0;
}