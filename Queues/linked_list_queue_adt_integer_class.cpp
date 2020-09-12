// Queue integer class implementation using linked list
// Author : Udayin Biswas, Date : 12/09/2020

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class Queue {
    private:
        Node *front;
        Node *rear;
    public:
        Queue();
        ~Queue();
        // No need for isFull() method here since it can be of any size in heap
        bool isEmpty();
        void enqueue(int x);
        int dequeue();
        void display();
};

Queue::Queue(){
    front = NULL;
    rear = NULL;
}

Queue::~Queue(){
    Node *p = front;
    while (p!=NULL){
        delete p;
        p = p->next;
    }
}

bool Queue::isEmpty(){
    if (front==NULL) return true;
    return false;
}

void Queue::enqueue(int x){
    Node *n = new Node;
    // Important condition for checking overflow in heap, this happens when heap is full
    if (n==NULL){
        cout<<"Queue overflow in heap"<<endl;
        return;
    }
    n->data = x;
    n->next = NULL;
    if (front==NULL){
        front=n;
        rear=n;
    } else {
        rear->next = n;
        rear = rear->next;
    }
}

int Queue::dequeue(){
    if (isEmpty()){ return -1;}
    if (front==rear){
        int val = front->data;
        Node *p = front;
        front = rear = NULL;
        delete p;
        return val;
    } else {
        int val = front->data;
        Node *p = front;
        front = front->next;
        delete p;
        return val;
    }
}

void Queue::display(){
    Node *p = front;
    while (p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main(){
    Queue q;
    cout<<q.isEmpty()<<endl;
    q.enqueue(3);
    q.enqueue(4);
    q.display();
    q.enqueue(7);
    q.dequeue();
    q.display();
    return 0;
}