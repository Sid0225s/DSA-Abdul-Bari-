#include <bits/stdc++.h>
using namespace std;

template <class T>
class Arithmatic{
    private:
    T a;
    T b;
    public:
    Arithmatic(T x,T y);
    T add();
    T sub();
    };

    template <class T>
    Arithmatic <T>::Arithmatic(T x,T y){
        this->a = x;
        this->b = y;
    };

    template <class T>
    T Arithmatic <T>::add() {
        T c;  
        c=a+b;
        return c;
    };

    template <class T>
    T Arithmatic <T>::sub(){
        T c;
        c=a-b;
        return c;
    };

int main(){
    Arithmatic<int> ar(7,8);
    cout<<ar.add()<<endl;
    Arithmatic<float> ap(7.8,6.5);
    cout<<ap.sub()<<endl;

    
    return 0;
}