#include <bits/stdc++.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};
int main(){

    Rectangle r= {10,5};
    cout<<r.length<<endl<<r.breadth<<endl;
    Rectangle *p= &r;
    cout<<p->length<<endl<<p->breadth;
    
    return 0;
}