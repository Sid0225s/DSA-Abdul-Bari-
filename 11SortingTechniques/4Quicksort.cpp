#include <iostream>
#include <vector>
using namespace std;

void Swap(int &x,int &y){
    int temp;
    temp=x;
    x=y;
    y=temp;
}

int Partition(vector<int> &A,int l,int h){
    int pivot=A[l];
    int i=l;
    int j=h;
    do
    {
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        if(i<j){
            Swap(A[i],A[j]);
        }
    } while (i<j);
    Swap(A[l],A[j]);
    return j;
}

void Quicksort(vector<int> &A,int l,int h){
    int j;
    if(l<h){
        j=Partition(A,l,h);
        Quicksort(A,l,j);
        Quicksort(A,j+1,h);
    } 

}

int main(){
    vector <int>A={56,78,45,89,34,12,54,90};
    Quicksort(A,0,A.size());
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    return 0;
}