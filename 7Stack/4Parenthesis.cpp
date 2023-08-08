#include <iostream>
using namespace std;

struct Stack {
    int size;
    int top;
    char *S;
};

void create(struct Stack *st) {
    cout << "Enter size of stack: ";
    cin >> st->size;
    st->S = new char[st->size]; // Corrected data type to char
    st->top = -1;
}

void Display(struct Stack *st) {
    for (int i = st->top; i >= 0; i--) {
        cout << st->S[i] << " ";
    }
    cout << endl;
}

void push(struct Stack *st, char x) {
    if (st->top == st->size - 1) {
        cout << "stack overflow" << endl;
    } else {
        st->top++;
        st->S[st->top] = x;
    }
}

bool isEmpty(struct Stack *st) { // Changed return type to bool and corrected function definition
    if (st->top == -1) {
        return true;
    } else {
        return false;
    }
}

void pop(struct Stack *st) {
    if (st->top == -1) {
        cout << "stack underflow" << endl;
    } else {
        st->top--;
    }
}

int isBalanced(char *exp) {
    struct Stack st;
    create(&st);
    for (int i = 0; exp[i] != '\0'; i++) { // Used == instead of =
        if (exp[i] == '(') {
            push(&st, exp[i]);
        } else if (exp[i] == ')') {
            if (isEmpty(&st)) { // Called isEmpty as a function with parentheses
                return 0;
            }
            pop(&st); // Implement the pop function to remove elements from the stack
        }
    }
    if (isEmpty(&st)) { // Called isEmpty as a function with parentheses
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char exp[] = "((a+b)-(a-b))";
    if (isBalanced(exp)) {
        cout << "Expression is balanced." << endl;
    } else {
        cout << "Expression is not balanced." << endl;
    }

    return 0;
}