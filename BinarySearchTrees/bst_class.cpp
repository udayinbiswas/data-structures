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

        void IterativeInsert(int key){
            
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

        void RecursiveInsert(int key){RecursiveInsert(key,root);}

        // Notice how recursive insert is done by pointing the left or right pointer to returning node from a call to child.
        Node* RecursiveInsert(int key,Node *p){
            if (root==NULL){
                Node *n = new Node;
                n->data = key;
                n->left = n->right = NULL;
                root = n;
                return n;
            }

            if (p==NULL){
                Node *n = new Node;
                n->data = key;
                n->left = n->right = NULL;
                return n;
            }
        
            if (p->data>key){
                p->left = RecursiveInsert(key,p->left);
            } else {
                p->right = RecursiveInsert(key,p->right);
            }
            return p;
        }

        void RecursiveDelete(int key){RecursiveDelete(key,root);}

        // Notice how recursive DELETE is done by pointing the left or right pointer to returning node from a call to child.
        Node* RecursiveDelete(int key,Node *p){
            if (p==NULL){
                return NULL;
            }
            if (p->data==key){
                if (p->left!=NULL){
                    Node *pred = inorderPredecessor(p);
                    p->data = pred->data;
                    p->left = RecursiveDelete(pred->data,p->left);
                } else if (p->right!=NULL){
                    Node *succ = inorderSuccessor(p);
                    p->data = succ->data;
                    p->right = RecursiveDelete(succ->data,p->right);
                } else {
                    // it is a leaf
                    if (p==root){
                        root = NULL;
                    }
                    delete p;
                    return NULL;
                }
            } else if (p->data>key){
                p->left = RecursiveDelete(key,p->left);
            } else {
                p->right = RecursiveDelete(key,p->right);
            }
            return p;
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

        Node* inorderPredecessor(Node *p){
            if (p->left!=NULL){
                p = p->left;
                while (p->right!=NULL){
                    p = p->right;
                }
                return p;
            }
            return NULL;
        }

        Node* inorderSuccessor(Node *p){
            if (p->right!=NULL){
                p = p->right;
                while (p->left!=NULL){
                    p = p->left;
                }
                return p;
            }
            return NULL;
        }


};

int main(){
    
    BinarySearchTree bst;
 
    // Insert
    bst.RecursiveInsert(10);
    bst.inOrderTraversal(); cout<<endl;
    bst.RecursiveInsert(5);
    bst.inOrderTraversal(); cout<<endl;
    bst.RecursiveInsert(20);
    bst.inOrderTraversal(); cout<<endl;
    bst.RecursiveInsert(8);
    bst.inOrderTraversal(); cout<<endl;
    bst.RecursiveInsert(30);
    bst.inOrderTraversal(); cout<<endl;
    bst.RecursiveDelete(20);
    bst.inOrderTraversal(); cout<<endl;
    // Inorder traversal
    bst.RecursiveDelete(10);
    bst.inOrderTraversal(); cout << endl;
    
 
    // Search
    Node* temp = bst.Search(8);
    if (temp != NULL){
        cout << temp->data << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}