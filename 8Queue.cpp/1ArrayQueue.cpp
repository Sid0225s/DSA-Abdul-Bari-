#include <iostream>
using namespace std;

class Queue{
    private :
        int size;
        int front;
        int rear;
        int *Q;
    public:
        void create();
        void EnQueue(int x);
        int DeQueue();
        void Display();
};

void Queue::create(){
    cout<<"Enter size of Queue :";
    cin>>size;
    Q=new int[size];
    front=rear=-1;
}

void Queue::EnQueue(int x){
    if(rear==size-1){
        cout<<"Queue is full"<<endl;
    }
    else{
        rear++;
        Q[rear]=x;
    }
}

int Queue::DeQueue(){
    int x=-1;
    if(front==rear){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        front++;
        x=Q[front];
    }
    return x;
}

void Queue::Display() {
    for (int i = front + 1; i <= rear; i++) {
        cout << Q[i] << " ";
    }
    cout << endl;
}

int main(){
    Queue q;
    q.create();
    q.EnQueue(2); q.EnQueue(5); q.EnQueue(31); q.EnQueue(15); q.EnQueue(21);
    q.Display();
    cout<<"Removed Element : "<<q.DeQueue()<<endl;
    q.Display();
    return 0;
}