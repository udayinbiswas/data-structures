// Displaying a linked list
// Author : Udayin Biswas, Date : 08/09/2020
#include <iostream>
#include <string>
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

void display(Node *head){
    while (head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}


int main(){
    int A[] = {3,5,7,10,15};
    Node *head = create(A,5);
    display(head);
}