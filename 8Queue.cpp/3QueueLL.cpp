#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class QueLL {
private:
    Node* front;
    Node* rear;

public:
    QueLL() { front = NULL; rear = NULL; }
    void EnQueue(int x);
    int DeQueue();
    void Display();
};

void QueLL::EnQueue(int x) {
    Node* t = new Node;
    if (t == NULL) {
        cout << "Queue is full" << endl;
    } else {
        t->data = x;
        t->next = NULL;
        if (front == NULL) front = rear = t;
        else {
            rear->next = t;
            rear = t;
        }
    }
}

int QueLL::DeQueue() {
    int x = -1;
    Node* p;
    if (front == NULL) {
        cout << "Queue is Empty" << endl;
    } else {
        p = front;
        front = front->next;
        x = p->data;
        delete p;  // Use delete to deallocate memory
    }
    return x;
}

void QueLL::Display() {
    Node* p = front;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    QueLL q;
    q.EnQueue(2);
    q.EnQueue(5);
    q.EnQueue(31);
    q.EnQueue(15);
    q.EnQueue(21);
    q.Display();
    cout << "Removed Element: " << q.DeQueue() << endl;
    q.Display();
    return 0;
}
