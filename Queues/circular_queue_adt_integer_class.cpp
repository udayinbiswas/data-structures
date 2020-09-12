// Circular queue integer class implementation
// Author : Udayin Biswas, Date : 12/09/2020

#include <iostream>
using namespace std;

class CircularQueue {
    private:
        int *A;
        int front; // points to the first element in queue
        int rear; // points to the last element in queue
        int size; // size of array
    public:
        CircularQueue();
        CircularQueue(int size);
        ~CircularQueue();
        bool isFull();
        bool isEmpty();
        void enqueue(int x);
        int dequeue();
        void display();
};

CircularQueue::CircularQueue(){
    A = new int[100];
    front = rear = -1;
}

CircularQueue::CircularQueue(int size){
    this->size = size; // don't forget this
    A = new int[size];
    front = rear = -1;
}

CircularQueue::~CircularQueue(){
    delete []A;
}

bool CircularQueue::isFull(){
    if (front%size==(rear+1)%size){
        return true;
    }
    return false;
}

bool CircularQueue::isEmpty(){
    // When front=rear=-1,queue is empty
    if (front==-1){
        return true;
    }
    return false;
}

void CircularQueue::enqueue(int x){
    
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

int CircularQueue::dequeue(){
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

void CircularQueue::display(){
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
    CircularQueue q(20);
    cout<<q.isEmpty()<<endl;
    q.enqueue(3);
    q.enqueue(4);
    q.display();
    q.enqueue(7);
    q.dequeue();
    q.display();
    return 0;
}