// Binary Search Tree
// Author : Udayin, 13/09/20

#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
};

class BinarySearchTree{
    private:
        Node *root;
    public:
        BinarySearchTree(){root=NULL;}

        void Insert(int key){
            
            Node *n = new Node;
            n->data = key;
            n->left = n->right = NULL;
            if (root==NULL){
                root = n;
                return;
            }
            Node *p =root;
            Node *t = NULL;
            while (p!=NULL){
                t = p;
                if (p->data==key){
                    return;
                } else if (p->data>key){
                    p = p->left;
                } else {
                    p = p->right;
                }
            }
            if (t->data>key){
                t->left = n; 
            } else {
                t->right = n;
            }
            return;
        }

        void inOrderTraversal(){
            inOrderTraversal(root);
        }

        void inOrderTraversal(Node *p){
            if (p!=NULL){
                inOrderTraversal(p->left);
                cout<<p->data<<" ";
                inOrderTraversal(p->right);
            }
        }

        Node* Search(int key){
            Node *p = root;
            while (p!=NULL){
                if (p->data==key){
                    return p;
                } else if (p->data<key){
                    p = p->right;
                } else {
                    p = p->left;
                }
            }
            return NULL;
        }

};

int main(){
    
    BinarySearchTree bst;
 
    // Insert
    bst.Insert(10);
    bst.Insert(5);
    bst.Insert(20);
    bst.Insert(8);
    bst.Insert(30);
 
    // Inorder traversal
    bst.inOrderTraversal();
    cout << endl;
 
    // Search
    Node* temp = bst.Search(2);
    if (temp != NULL){
        cout << temp->data << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}