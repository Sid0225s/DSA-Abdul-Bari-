#include <iostream>
using namespace std;

struct Array
{
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


void append(struct Array *arr,int x){
    // if(arr->length<arr->size) This is for to check is their is free space avilaible or not
       arr->A[arr->length++]=x;
}
void insert(Array*arr,int index,int x){
    int i;
    if(index>=0 && index <=arr->length){
        for(i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;      
    }
}
int main(){
    Array arr ={{2,3,4,5},10,4};
    append(&arr,10);
    insert(&arr,2,13);
    Display(arr);
    return 0;
}