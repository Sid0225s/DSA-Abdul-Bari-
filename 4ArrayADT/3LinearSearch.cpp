#include <iostream>
using namespace std;


struct Array {
    int A[10];
    int length=10;
    int size =10;
};

int linearSearch(struct Array arr,int key){
    int i;
    for(i=0;i<arr.length;i++){
        if(key==arr.A[i])
            cout<<i;
    }
    return 0;
}
int main(){
    Array arr = {{1,2,3,4,5,7,5,32,2},10,9};
    linearSearch(arr,32);
    return 0;
}