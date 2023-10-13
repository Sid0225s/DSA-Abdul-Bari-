#include <iostream>
#include <vector>
using namespace std;

void Insertion(vector <int> &A){
    int n=A.size();
    for(int i=1;i<n;i++){
        int j=i-1;
        int x=A[i];
        while(x<A[j] && j>-1){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}

int main(){
    vector <int>A={56,78,34,12,54,90};
    Insertion(A);
    for(int i=0;i<6;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}