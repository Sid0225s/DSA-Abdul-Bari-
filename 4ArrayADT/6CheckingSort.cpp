#include <iostream>
using namespace std;


struct  Array 
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{ for(int i=0;i<arr.length;i++){
    cout<<arr.A[i]<<" ";
}  
};

void insertSort(struct Array *arr,int x){
    int i=arr->length-1;
    while(i>=0 && arr->A[i]>x){
        arr->A[i+1]=arr->A[i];
        i--;
    }
   arr->A[i+1]=x;
}

void Rearrange(struct Array *arr)
{
   int i,j;
   i=0;
   j=arr->length-1;
   while(i<j){
   while(arr->A[i]<0)i++;
   while(arr->A[j]>0)j--;
   if(i<j){
    int temp = arr->A[i];
    arr->A[i]=arr->A[j];
    arr->A[j]=temp;
     }
   }
};

int main(){
    Array arr = {{1,2,-3,4,-6,8,9},9,7};
    // insertSort(&arr,-8);
    Rearrange(&arr);
    Display(arr);

    return 0;
}