// LinkedList template class
// Author : Udayin Biswas, Date : 08/09/2020
#include <iostream>
using namespace std;

template<class T> 
class  Node {
    public:
        T data;
        Node *next;
};

template<class T> 
class LinkedList {
    private:
        Node<T> *head;
    public:
        // Constructors
        LinkedList(){head=NULL;}
        LinkedList(T array[],int length){
            head = new Node<T>; // declaring head in heap, not stack
            // if we did Node *head; and then head=b where b is in heap, head will still be in stack and returning pointer 
            // would be useless in this to main function
            Node<T> *p = head;
            for (int i=0;i<length;i++){
                p->next = new Node<T>;
                p = p->next;
                p->data = array[i];
                p->next= NULL; // PUT THIS OTHERWISE SEGMENTATION FAULT WHILE DISPLAYING LATER. Last node should point to NULL 
                // If we don't, it won't assume NULL on its own.
            }
            head = head->next;
        }
        // Destructor
        ~LinkedList(){
            Node<T> *p = head;
            while (p!=NULL){
                delete p;
                p = p->next;
            }
        }
        // Display linked list
        void Display(){
            Node<T> *p = head;
            while (p!=NULL){
                cout<<p->data<<" ";
                p = p->next;
            }
            cout<<endl;
            
        }
        // Length of linked list
        int Length(){
            Node<T> *p = head;
            int count = 0;
            while (p!=NULL){
                count++;
                p = p->next;
            }
            return count;
        }
        // Insert in Linked list
        void Insert(T val, int index){
            Node<T> *n = new Node<T>;
            n->data = val;
            if (index==0){
                n->next = head;
                head = n;
                return;
            } 
            Node<T> *p = head;
            int count = 1;
            while (p!=NULL){
                if (index==count){
                    // Insert
                    Node<T> *q = p->next;
                    p->next = n;
                    n->next = q;
                    p = p->next;
                    break;
                } else {
                    p = p->next;
                    count++;
                }
            }
        }

        // Delete from linked list
        T Delete(int index){ // 0 indexed
            if (index<0 || index>=Length()){
                return -1;
            }
            if (index==0){
                int val = head->data;
                Node<T> *p = head;
                head = head->next;
                delete p;
                return val;
            }
            Node<T> *p = head;
            int count = 1;
            while (p!=NULL){
                if (index==count){
                    if (p->next!=NULL){
                        int val = p->next->data;
                        Node<T> *q = p->next->next;
                        delete p->next;
                        p->next = q;
                        return val;
                    }
                } else {
                    count++;
                    p = p->next;
                }
            }
            return -1;
        }
};

int main(){
    float x[5] = {1,3.5,5,7,10};
    LinkedList<float> l = LinkedList<float>(x,5);
    l.Display();
    cout<<"Length:"<<l.Length()<<endl;
    l.Insert(9,4);
    l.Display();
    l.Delete(1);
    l.Delete(0);
    l.Display();
}