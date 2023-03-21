#include <bits/stdc++.h>
using namespace std;

class Rectangle{
    private:
    int length,breadth;

    public:
    Rectangle(int l,int b){
        length=l;
        breadth=b;
    }
    int area(){
        return length*breadth;
    }
    int perimeter(){
        return 2*length+2*breadth;
    }

};
int main(){
    Rectangle r={10,15};
    int a=r.area();
    int b=r.perimeter();
    cout<<a<<" "<<b;
    return 0;
}