#include <iostream>
using namespace std;

class Lowertri{
    private:
      int *A;
      int n;
    public:
      Lowertri(){
        n=2;
        A=new int[2];
      }  
      Lowertri(int n){
        this->n=n;
        A = new int[n];
      }
      ~Lowertri(){
        delete[]A;
      }
      void Set(int i,int j, int x);
      int get(int i, int j);
      void display();
};
void Lowertri::Set (int i,int j,int x){
   if(i>=j){
    A[i*(i+1)/2+j-1]=x;
   }

}
int Lowertri::get(int i,int j){
    if(i>=j){
        cout<<A[i*(i+1)/2+j-1];
    }
    else{
        cout<<0;
    }
    return 0;
}
void Lowertri::display(){
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(i>=j){
                cout<<A[i*(i+1)/2+j-1];
            }
            else{
                cout<<0;
            }
        }
        cout<<endl;
    }
}

int main(){
    Lowertri mat(3);
    mat.Set(1,1,2);mat.Set(2,1,3); mat.Set(3,1,9); mat.Set(2,2,5);mat.Set(3,2,6);mat.Set(3,3,8);
    mat.display();
    
    return 0;
}