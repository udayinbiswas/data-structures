// LinkedList circular integer class
// Author : Udayin Biswas, Date : 10/09/2020
#include <iostream>
using namespace std;
#define SIZE 10

class  Node {
    public:
        int data;
        Node *next;
};

class HashTable {
    public:
        int *A; // note double pointer here, it means pointing to an array of node pointers
        // Constructor
        HashTable(){
            A = new int[SIZE];
            for (int i=0;i<SIZE;i++){
                A[i] = 0;
            }
        }
        // Destructor
        ~HashTable() {
            delete []A;
        }
        int hashFunction(int key){
            return key%10;
        }
        
        void Insert(int key){
            int hashValue = hashFunction(key);
            // Linear Probing to find next empty slot in hashtable
            int i = 0;
            while (A[(hashValue+i)%SIZE]!=0){
                i++;
            }
            A[(hashValue+i)%SIZE] = key;
        }
        // Return the index at which key was found in the linked list
        int Search(int key){
            int hashValue = hashFunction(key);
            int i = 0;
            while (A[(hashValue+i)%SIZE]!=key){
                i++;
            }
            return (hashValue+i)%SIZE;
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