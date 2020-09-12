// Tree construction from user input
// Author : Udayin Biswas, Date : 10/09/2020
#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
        Node *left;
        Node *right;
        int data;
};

class Tree {
    private:
        Node *root;
    public:
        Tree();
        ~Tree();
        void CreateTree();
        void Preorder(Node *p);
        void Preorder() {Preorder(root);}
        void Inorder(Node *p);
        void Inorder() {Inorder(root);}
        void Postorder(Node *p);
        void Postorder() {Postorder(root);}
        void Levelorder(Node *p);
        void Levelorder() {Levelorder(root);}
        int Height(Node *p);
        int Height(){return Height(root);}
};

Tree::Tree(){
    root=NULL;
}

Tree::~Tree(){
    
}

void Tree::CreateTree(){
    root = new Node;
    int x;
    cout<<"Enter root data: ";
    cin>>x;
    root->data = x;
    root->left = NULL;
    root->right = NULL;
    queue<Node*> queue;
    queue.push(root);
    Node *p;
    while (queue.size()!=0){
        p = queue.front();
        queue.pop();
        cout<<"Enter left child of "<<p->data<<":";
        cin>>x;
        if (x!=-1){
            Node *q = new Node;
            q->data = x;
            q->left = NULL;
            q->right = NULL;
            p->left = q;
            queue.push(q);
        }
        cout<<"Enter right child of "<<p->data<<":";
        cin>>x;
        if (x!=-1){
            Node *q = new Node;
            q->data = x;
            q->left = NULL;
            q->right = NULL;
            p->right = q;
            queue.push(q);
        }
    }
}

void Tree::Preorder(Node *p) {
    if (p){
        cout << p->data << ", " << flush;
        Preorder(p->left);
        Preorder(p->right);
    }
}
 
void Tree::Inorder(Node *p) {
    if (p){
        Inorder(p->left);
        cout << p->data << ", " << flush;
        Inorder(p->right);
    }
}
 
void Tree::Postorder(Node *p) {
    if (p){
        Postorder(p->left);
        Postorder(p->right);
        cout << p->data << ", " << flush;
    }
}
 
void Tree::Levelorder(Node *p) {
    queue<Node*> q;
    cout << root->data << ", " << flush;
    q.push(root);
 
    while (! q.empty()){
        p = q.front();
        q.pop();
 
        if (p->left){
            cout << p->left->data << ", " << flush;
            q.push(p->left);
        }
 
        if (p->right){
            cout << p->right->data << ", " << flush;
            q.push(p->right);
        }
    }
}
 
int Tree::Height(Node *p) {
    int l = 0;
    int r = 0;
    if (p == NULL){
        return 0;
    }
 
    l = Height(p->left);
    r = Height(p->right);
 
    if (l > r){
        return l + 1;
    } else {
        return r + 1;
    }
}
 
int main() {
 
    Tree bt;
 
    bt.CreateTree();
    cout << endl;
 
    cout << "Preorder: " << flush;
    bt.Preorder();
    cout << endl;
 
    cout << "Inorder: " << flush;
    bt.Inorder();
    cout << endl;
 
    cout << "Postorder: " << flush;
    bt.Postorder();
    cout << endl;
 
    cout << "Levelorder: " << flush;
    bt.Levelorder();
    cout << endl;
 
    cout << "Height: " << bt.Height() << endl;
 
    return 0;
}