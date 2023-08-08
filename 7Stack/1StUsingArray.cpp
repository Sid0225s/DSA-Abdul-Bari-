#include <iostream>
using namespace std;

struct Stack{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st){
    cout<<"Enter size of stack ";
    cin >> st->size;
    st->S = new int[st->size];
    st->top = -1;
}

void Display(struct Stack *st){
    for (int i = st->top; i >= 0; i--){ 
        cout << st->S[i] << " ";
    }
    cout << endl;
}

void push(struct Stack *st, int x){
    if(st->top == st->size - 1){
        cout << "stack overflow" << endl;
    }
    else{
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st){
    int x = -1;
    if(st->top == -1){
        cout << "stack Underflow" << endl;
    }
    else{
        x = st->S[st->top--];  
    }
    return x;     
}

int peek(struct Stack *st,int pos){
    int x=-1;
    if(st->top-pos+1<0){
       cout<<"invalid position"<<endl;
    }
    else{
        x=st->S[st->top-pos+1];
    }
    return x;
}

int main(){
    struct Stack st; // No need to use pointer here, directly use a struct variable.
    create(&st);
    push(&st, 3);
    push(&st, 11);
    push(&st, 17);
    push(&st, 19);
    push(&st, 26);
    pop(&st);
    cout<<peek(&st,4)<<endl;
    Display(&st);

    return 0;
}
