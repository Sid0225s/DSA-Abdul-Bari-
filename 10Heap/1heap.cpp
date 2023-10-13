#include <iostream>
using namespace std;

void Insert(int A[],int n){
    int temp,i=n;
    temp=A[n];
    while(i>1 && temp>A[i/2]){
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}

int  Delete(int A[],int n){
    int x,i,j,temp,val;
    val = A[1];
    x=A[n];
    A[1]=A[n];
    A[n]=x;
    i=1;j=2*i;
    while(j<n-1){
        if(A[j+1]>A[j]){
            j=j+1;
        }
        if(A[i]<A[j]){
            temp=A[j];
            A[j]=A[i];
            A[i]=temp;
            i=j;
            j=2*j;
        }
        else{
            break;
        }
    }
    return val;
}

int main(){
    int H[]={0,5,14,16,6,9};
    for(int i=2;i<=5;i++){
        Insert(H,i);
    }
    cout<<"Deleted element : "<<Delete(H,5)<<endl;
    for(int i=1;i<=5;i++){
        cout<<H[i]<<" ";
    }
    
    return 0;
}