#include <iostream>
using namespace std;

class Node {
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class bst {
private:
    Node *root;
public:
    bst() { root = NULL; }
    Node* getRoot(){ return root; }
    void Insert(int x);
    void Preorder(){Preorder(root);}
    void Preorder(Node *p); // Added Node parameter
    Node *Search(int key);
    Node *Rinsert(Node *t,int key);
    Node *Delete(Node *p,int key);
    int Height(Node *p);
    Node* InPre(Node *p);
    Node* InSucc(Node *p);
};

void bst::Insert(int x) {
    Node *t = root;
    Node *r = nullptr, *p = nullptr;
    if (t == nullptr) {
        p = new Node;
        p->data = x;
        p->lchild = p->rchild = nullptr;
        root = p; // Update the root
        return; // Return after inserting the root node
    }
    while (t != nullptr) {
        r = t;
        if (t->data > x) {
            t = t->lchild;
        } else if (t->data < x) {
            t = t->rchild;
        } else {
            return; // If the node with the same value already exists, return
        }
    }
    p = new Node;
    p->data = x;
    p->lchild = p->rchild = nullptr;
    if (p->data > r->data) {
        r->rchild = p;
    } else {
        r->lchild = p;
    }
}


void bst::Preorder(Node *p) {
    if (p) {
        cout << p->data << " ";
        Preorder(p->lchild); // Recursive call for left subtree
        Preorder(p->rchild); // Recursive call for right subtree
    }
}

Node *bst::Search(int key){
    Node *current = root;
        while (current != nullptr) {
            if (current->data == key) {
                return current; // Found the node with the key
            } else if (current->data > key) {
                current = current->lchild; // Go to the left subtree
            } else {
                current = current->rchild; // Go to the right subtree
            }
        }
        return nullptr;
}

Node *bst::Rinsert(Node *t,int key){
    Node *p=nullptr;
    if(t==nullptr){
        p=new Node;
        p->data=key;
        p->lchild=p->rchild=nullptr;
        return p;
    }  
    if (key < t->data){
        t->lchild = Rinsert(t->lchild, key);
    } else if (key > t->data){
        t->rchild = Rinsert(t->rchild, key);
    }
    return t;  // key == p->data?
}
Node* bst::Delete(Node *p, int key) {
    Node* q;
 
    if (p == nullptr){
        return nullptr;
    }
 
    if (p->lchild == nullptr && p->rchild == nullptr){
        if (p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }
 
    if (key < p->data){
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data){
        p->rchild = Delete(p->rchild, key);
    } else {
        if (Height(p->lchild) > Height(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}
 
int bst::Height(Node *p) {
    int x;
    int y;
    if (p == nullptr){
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}
 
Node* bst::InPre(Node *p) {
    while (p && p->rchild != nullptr){
        p = p->rchild;
    }
    return p;
}
 
Node* bst::InSucc(Node *p) {
    while (p && p->lchild != nullptr){
        p = p->lchild;
    }
    return p;
}


int main() {
    bst tree;
    tree.Insert(5);
    tree.Insert(3);
    tree.Insert(8);
    tree.Insert(2);
    tree.Insert(4);
    tree.Rinsert(tree.getRoot(),9);
    tree.Delete(tree.getRoot(),2);
    cout<<"Preorder: ";
    tree.Preorder(); // Calling Preorder traversal function
    cout<<endl;
    cout.flush();

    if(tree.Search(9)){
        cout<<"found";
    }else{
        cout<<"not found";
    }
    return 0;
}
