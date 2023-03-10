#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main(){
    struct Rectangle r;
    r.length = 12;
    r.breadth = 15;
    int area = (r.length)*(r.breadth);
    cout<<area<<endl;
    return 0;
}