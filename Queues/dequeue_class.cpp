// Circular queue integer class implementation
// Author : Udayin Biswas, Date : 12/09/2020

#include <iostream>
using namespace std;

class Dequeue {
    private:
        int *A;
        int front; // points to the first element in queue
        int rear; // points to the last element in queue
        int size; // size of array
    public:
        Dequeue();
        Dequeue(int size);
        ~Dequeue();
        bool isFull();
        bool isEmpty();
        void enqueueFront(int x);
        void enqueueRear(int x);
        int dequeueFront();
        int dequeueRear();
        void display();
};

Dequeue::Dequeue(){
    A = new int[100];
    front = rear = -1;
}

Dequeue::Dequeue(int size){
    this->size = size; // don't forget this
    A = new int[size];
    front = rear = -1;
}

Dequeue::~Dequeue(){
    delete []A;
}

bool Dequeue::isFull(){
    if (front%size==(rear+1)%size){
        return true;
    }
    return false;
}

bool Dequeue::isEmpty(){
    // When front=rear=-1,queue is empty
    if (front==-1){
        return true;
    }
    return false;
}

void Dequeue::enqueueFront(int x){
    if (isFull()) cout<<"Queue is full,cannot enequeue element "<<x<<endl;
    if (isEmpty()){ // i.e. no element in queue
        front = (front+1)%size; // becomes 0th index since front=-1
        rear = (rear+1)%size; // becomes 0th index since rear=-1
    } else {
        front = (size+(front-1))%size;
    }
    A[front]=x;
    return;
}

void Dequeue::enqueueRear(int x){
    if (isFull()) cout<<"Queue is full,cannot enequeue element "<<x<<endl;
    if (isEmpty()){ // i.e. no element in queue
        front = (front+1)%size; // becomes 0th index since front=-1
        rear = (rear+1)%size; // becomes 0th index since rear=-1
    } else {
        rear = (rear+1)%size;
    }
    A[rear]=x;
    return;
}

int Dequeue::dequeueFront(){
    if (isEmpty()) cout<<"Queue is empty,cannot dequeue element"<<endl;
    int val = -1;
    if (front==rear){
        val = A[front];
        front = rear = -1; // reset front and rear to -1 to represent empty queue
    } else {
        val = A[front];
        front = (front+1)%size;
    }
    return val;
}

int Dequeue::dequeueRear(){
    if (isEmpty()) cout<<"Queue is empty,cannot dequeue element"<<endl;
    int val = -1;
    if (front==rear){
        val = A[rear];
        front = rear = -1; // reset front and rear to -1 to represent empty queue
    } else {
        val = A[rear];
        rear = (size+rear-1)%size;
    }
    return val;
}

void Dequeue::display(){
    int p = front;
    if (p!=-1){
        while (p%size!=rear%size){
            cout<<A[p]<<" ";
            p = (p+1)%size;
        }
        cout<<A[p]<<endl;
    }
}

int main(){
    Dequeue q(20);
    cout<<q.isEmpty()<<endl;
    q.enqueueFront(3);
    q.enqueueFront(4);
    cout<<"Display one:"<<endl;
    q.display();
    q.enqueueRear(7);
    cout<<"Display two:"<<endl;
    q.display();
    q.dequeueFront();
    cout<<"Display three:"<<endl;
    q.display();
    q.dequeueRear();
    cout<<"Display four:"<<endl;
    q.display();
    return 0;
}