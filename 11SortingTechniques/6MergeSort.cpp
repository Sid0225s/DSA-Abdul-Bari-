#include <iostream>
#include <vector>
using namespace std;

vector<int> Merge(vector<int> &A,vector<int> &B){
    int m=A.size();
    int n=B.size();
    int i,j,k;
    i=j=k=0;
    vector<int> C(m+n, 0);
    while(i<m && j<n){
        if(A[i]<B[j]){
            C[k++]=A[i++];
        }else{
            C[k++]=B[j++];
        }
    }
    for(;i<m;i++){
        C[k++]=A[i];
    }
    for(i=0;i<n;i++){
        C[k++]=B[i];
    }
    return C;
}

int main(){
    vector<int> A={2,5,6,7,8};
    vector<int> B={2,7,12,44,100};
    vector<int> C = Merge(A, B);

    for (int i = 0; i < C.size(); i++) {
        cout << C[i] << " ";
    }

    
    return 0;
}