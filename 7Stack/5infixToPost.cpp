#include <iostream>
#include <cstring>
using namespace std;

class Stack {
private:
    char* S;
    int size;
    int top;

public:
    Stack() { top = -1; }
    void create();
    void push(char x);
    char pop();
    void Display();
    bool isEmpty();
    int Pre(char x);
    int stackTop();
    int isOperand(char x);
    char* Convert(char* infix);
    int EvalPost(char *postfix);
};

void Stack::create() {
    cout << "Enter size of Stack" << endl;
    cin >> size;
    S = new char[size];
    top = -1;
}

void Stack::push(char x) {
    if (top == size - 1) {
        cout << "stack overflow" << endl;
    } else {
        top++;
        S[top] = x;
    }
}

char Stack::pop() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return '\0'; // Return some error value as stack is empty.
    } else {
        char temp = S[top];
        top--;
        return temp;
    }
}

void Stack::Display() {
    for (int i = top; i >= 0; i--) {
        cout << S[i] << " ";
    }
    cout << endl;
}

int Stack::stackTop() {
    if (top == -1) {
        cout << "stack is empty" << endl;
        return -1; // Return some error value as stack is empty.
    } else {
        return S[top];
    }
}

bool Stack::isEmpty() {
    if (top == -1) {
        return true;
    } else {
        return false;
    }
}

int Stack::isOperand(char x) {
    if (x == '+' || x == '-' || x == '/' || x == '*') {
        return 0;
    } else {
        return 1;
    }
}

int Stack::Pre(char x) {
    if (x == '+' || x == '-') {
        return 1;
    } else if (x == '/' || x == '*') {
        return 2;
    } else {
        return 0;
    }
}

char* Stack::Convert(char* infix) {
    int len = strlen(infix);
    char* postfix;
    postfix = new char[len + 1];
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            if (isEmpty() || Pre(infix[i]) > Pre(stackTop())) {
                push(infix[i++]);
            } else {
                postfix[j++] = pop();
            }
        }
    }
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix ;
        delete []postfix;
}

int Stack::EvalPost(char* postfix){
    int i,x1,x2,r;
    for(i=0;postfix[i]!='\0';i++){
        if(isOperand(postfix[i])){
           push(postfix[i]-'0');
        }
        else{
            x2=pop();
            x1=pop();
            switch (postfix[i])
            {
            case '+':
                r=x1+x2;
                break;
            case '-':
                r=x1-x2;
                break;
            case '/':
                r=x1/x2;
                break;
            case '*':
                r=x1*x2;
                break;
            }
            push(r);
        }
  } return pop();
}

int main() {
    Stack st;
    st.create();
    char infix[] = "3+5*2-9/3";//only for single digit
    char* postfix = st.Convert(infix);
    cout<<"Postfix expression : "<<postfix<<endl;
    cout<<"Calculated value : "<<st.EvalPost(postfix)<<endl;
    return 0;
}
