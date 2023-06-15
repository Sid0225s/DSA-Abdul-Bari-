// IN CPP

#include <iostream>
using namespace std;

class Diagonal{
   private:
    int *A;
    int n;
   public:
      Diagonal(){
        n=2;
        A = new int[2];
      }
      Diagonal(int n){
        this->n=n;
        A= new int[n];
      }
      ~Diagonal(){
        delete[]A;
      }
      void Set(int i,int j, int x);
      int get(int i, int j);
      void display();
};
 
void Diagonal::Set (int i,int j,int x){
   if(i==j){
    A[i-1]=x;
   }

}
int Diagonal::get(int i,int j){
    if(i==j){
        cout<<A[i-1];
    }
    else{
        cout<<0;
    }
    return 0;
}
void Diagonal::display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                cout<<A[i];
            }
            else{
                cout<<0;
            }
        }
        cout<<endl;
    }
}


int main(){
    Diagonal d(4);
    d.Set(1,1,5); d.Set(2,2,6); d.Set(3,3,2); d.Set(4,4,1);
    d.display();
    return 0;
}
//In C language

// #include <iostream>
// using namespace std;

// struct Matrix
// {
//     int A[10];
//     int n;
// };

// void Set(struct Matrix *m, int i,int j, int x){
//     if(i==j){
//         m->A[i-1]=x;
//     }
// }
// int get(struct Matrix m,int i , int j){
//     if(i!=j){
//         cout<<0;
//     }
//     else{
//         cout<<m.A[i-1];
//     }
//     return 0;
// }
// void Display(struct Matrix m){
//     int i,j;
//     for(i=0;i<m.n;i++){
//      for(j=0;j<m.n;j++){
//         if(i==j){
//             cout<<m.A[i];
//         }
//         else{
//             cout<<0;
//         }
//      }
//      cout<<endl;
//     }
// }

// int main(){
//     Matrix m;
//     m.n=4;
//     Set(&m,1,1,5); Set(&m,2,2,6); Set(&m,3,3,2); Set(&m,4,4,1);

//     Display(m);
//     return 0;
// }