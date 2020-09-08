// Displaying a linked list
// Author : Udayin Biswas, Date : 08/09/2020
#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* create(int A[],int n){
    Node *head = new Node;
    Node *p = head;
    for (int i=0;i<n;i++){
        p->next = new Node();
        p = p->next;
        p->data = A[i];
        p->next = NULL;
    }
    return head->next;
}

void IterativeDisplay(Node *head){
    while (head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void RecursiveDisplay(Node *head){
    if (head!=NULL){
        cout<<head->data<<" ";
        RecursiveDisplay(head->next);
    }
}

int IterativeMax(Node *head){
    int val = INT_MIN;
    while (head!=NULL){
        val = max(head->data,val);
        head = head->next;
    }
    return val;
}

int RecursiveMax(Node *head){
    if (head==NULL){
        // Notice how we are passing INT MIN in terminating condition 
        // and compare it with how we passed INT MIN in beginning for iterative function
        return INT_MIN;
    }
    int x = max(head->data,RecursiveMax(head->next));
    return x;
}


int main(){
    int A[] = {3,5,7,10,15};
    Node *head = create(A,5);
    RecursiveDisplay(head);
    cout<<endl;
    cout<<"max:"<<RecursiveMax(head)<<endl;
}