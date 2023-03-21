#include <bits/stdc++.h>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

//CALL BY VALUE FOR CALL BY REFRENCE REPLACE PARAMETER r -> &r 

// void fun(struct Rectangle r){
//     r.length++;
//     cout<<r.length<<" "<<r.breadth<<endl;
// };
// int main(){
//     Rectangle r={15,10};
//     fun(r);
// cout<<r.length<<r.breadth;
// return 0;
// }


//CALL BY ADDRESS
// void fun(struct Rectangle *p){
//     p->length= 20;
//     cout<<p->length<<" "<<p->breadth<<endl;
//     };

//     int main(){
//         Rectangle r={10,5};
//         fun(&r);

//         cout<<r.length<<" "<<r.breadth<<endl;
//         return 0;
// }


//CALL BY ADDRESS TO ALLOCATE MEMORY IN HEAP
    struct Rectangle *fun(){
    struct Rectangle *p;
    p=new Rectangle;
    // p=(struct Rectangle *)malloc(sizeof(struct Rectangle)); //For c language
    p->length=15;
    p->breadth=17;
    return p;
}
int main(){
    struct Rectangle *ptr=fun();

     cout<<ptr->length<<" "<<ptr->breadth;
return 0;
}