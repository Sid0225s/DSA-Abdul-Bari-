#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() { top = NULL; }
    void push(int x);
    int pop();
    void Display();
};

void Stack::push(int x) {
    Node* t = new Node;
    if (t == NULL) {
        cout << "stack is full" << endl;
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop() {
    int x = -1;
    if (top == NULL) {
        cout << "stack underflow" << endl;
    } else {
        x = top->data;
        Node* t = top;
        top = top->next;
        delete t;
    }
    return x; // Added return statement
}

void Stack::Display() {
    Node* p = top;
    while (p) {
        cout << p->data << " "; // Added space between data elements for better readability
        p = p->next;
    }
    cout << endl;
}

int main() {
    Stack St;
    St.push(1);
    St.push(10);
    St.push(15);
    St.push(12);
    St.push(14);
    St.Display();
    cout<<St.pop()<<endl;
    St.Display();
    return 0;
}
