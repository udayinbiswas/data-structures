// LinkedList circular integer class
// Author : Udayin Biswas, Date : 10/09/2020
#include <iostream>
using namespace std;

class  Node {
    public:
        int data;
        Node *next;
};

class HashTable {
    public:
        Node **A; // note double pointer here, it means pointing to an array of node pointers
        // Constructor
        HashTable(){
            A = new Node*[10];
            for (int i=0;i<10;i++){
                A[i] = NULL;
            }
        }
        // Destructor
        ~HashTable() {
            for (int i=0; i<10; i++){
                Node* p = A[i];
                while (A[i]){
                    A[i] = A[i]->next;
                    delete p;
                    p = A[i];
                }
            }
            delete [] A;
        }
        int hashFunction(int key){
            return key%10;
        }
        
        void Insert(int key){
            int hashValue = hashFunction(key);
            Node* head = A[hashValue];
            Node* node = new Node;
            node->data = key;
            node->next = NULL;
            if (head==NULL){
                A[hashValue] = node;
            } else {
                Node* p = head;
                Node* prev = NULL;
                // Insert in sorted position
                while (p!=NULL && p->data<key){
                    if (p==head){
                        prev = head;
                    } else {
                        prev = prev->next;
                    }
                    p = p->next;
                }
                prev->next = node;
                node->next = p;
            }
            return;
        }
        // Return the index at which key was found in the linked list
        int Search(int key){
            int val = hashFunction(key);
            Node* p = A[val];
            int count = 0;
            while (p!=NULL){
                if (p->data==key){
                    return count;
                } else {
                    p=p->next;
                    count++;
                }
            }
            return -1;
        }
        
};

int main(){
    HashTable H;
    int array[7] = {1,4,5,14,15,84,21};
    for (int i=0;i<7;i++){
        H.Insert(array[i]);
    }
    for (int i=0;i<7;i++){
        cout<<"Searching for "<<array[i]<<",Found at index:"<<H.Search(array[i])<<endl;
    }
    return 0;
}