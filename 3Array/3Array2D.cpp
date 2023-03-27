#include <iostream>
using namespace std;

int main(){
    int A[3][4]={{1,2,3,4},{5,3,4,5},{3,2,0,3}};
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<A[i][j]<<"  ";
        }
        cout<<endl;
    }
    int *B[3];
    B[0]= new int[4];
    B[1]= new int[4];
    B[2]= new int[4];
    return 0;
}