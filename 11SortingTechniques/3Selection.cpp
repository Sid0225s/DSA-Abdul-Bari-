#include <iostream>
#include <vector>
using namespace std;

void Swap(int &x,int &y){
    int temp;
    temp=x;
    x=y;
    y=temp;
}

void Selection(vector <int> &A){
    int n=A.size();
    for(int i=0;i<n-1;i++){
      int j,k=i;
      j=k+1;
      while(j<n){
        if(A[j]<A[k]){
            k=j;
        }
        j++;
      }
      Swap(A[i],A[k]);
    }
}

int main(){
    vector <int>A={56,78,34,12,54,90};
    Selection(A);
    for(int i=0;i<6;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}