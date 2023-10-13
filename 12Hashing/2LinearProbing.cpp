#include <iostream>
using namespace std;

int hash1(int key){
    return key%10;
}

void Insert(int key,int H[10]){
    int index = hash1(key);
    int i=0;
    while(i<10){
    if(H[index]==0){
        H[index]=key;
        break;
    }
    else{
        index = index +1;
        i++;
    }
    }
}

bool Search(int key, int H[10]){
    int index = hash1(key);   
    for(int i=0;i<10;i++){
        if(H[i]==key){
            return true;
        }     
    }
    return false;  
}

int main(){
    int H[10]={0};
    Insert(2,H);
    if(Search(2,H)){
        cout<<"successful"<<endl;
    }else{
        cout<<"unsuccessful"<<endl;
    }

    return 0;
}