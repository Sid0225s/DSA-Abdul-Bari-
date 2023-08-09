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
    int inStackPre(char x);
    int outStackPre(char x);
    int stackTop();
    int isOperand(char x);
    char* Convert(char* infix);
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
    if (x == '+' || x == '-' || x == '/' || x == '*'||x=='^'||x=='('||x==')') {
        return 0;
    } else {
        return 1;
    }
}

int Stack::outStackPre(char x) {
    if (x == '+' || x == '-') {
        return 1;
    } else if (x == '/' || x == '*') {
        return 3;     
    }
    else if (x == '^' || x == '*') {
        return 6;
    }
    else if(x=='('){
        return 7;   
    }  
     else {
        return 0;
    }
}
int Stack::inStackPre(char x) {
    if (x == '+' || x == '-') {
        return 2;
    } else if (x == '/' || x == '*') {
        return 4;     
    }
    else if (x == '^' || x == '*') {
        return 5;
    }  
     else {
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
            if (isEmpty() || outStackPre(infix[i]) > inStackPre(stackTop())) {
                push(infix[i++]);
            } else if (infix[i] == ')') {
                while (!isEmpty() && stackTop() != '(') {
                    postfix[j++] = pop();
                }
                if (!isEmpty()) {
                    pop(); // Pop '('
                } else {
                    cout << "Invalid expression: Unbalanced parentheses" << endl;
                    delete[] postfix;
                    return nullptr;
                }
                i++;
            } 
             else {
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


int main() {
    Stack st;
    st.create();
    char infix[] = "((a+b)*c)-d^e^f";//only for single digit
    char* postfix = st.Convert(infix);
    cout<<"Postfix expression : "<<postfix<<endl;
    return 0;
}
