#include <iostream>
using namespace std;

void Swap(int &x,int &y){
    int temp;
    temp=x;
    x=y;
    y=temp;
}

void BubbleSort(int A[],int n){
    for(int i=0;i<n-1;i++){
        int flag=0;
        for(int j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                Swap(A[j],A[j+1]);
                flag=1;
            }
        }
        if(!flag){
           break;
        }
    }
}

int main(){
    int A[]={56,78,34,12,54,90};
    int n=6;
    BubbleSort(A,n);
    for(int i=0;i<6;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}