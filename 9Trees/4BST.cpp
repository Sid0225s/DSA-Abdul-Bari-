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
    void Insert(int x);
    void Preorder(Node *p); // Added Node parameter
    void Preorder(); // Added this function declaration
};

void bst::Insert(int x) {
    Node *t = root;
    Node *r, *p;
    if (t == NULL) {
        p = new Node;
        p->data = x;
        p->lchild = p->rchild = NULL;
        t = p;
        r = t;
    }
    while (t != NULL) {
        if (t->data > x) {
            r = t;
            t = t->lchild;
        } else if (t->data < x) {
            r = t;
            t = t->rchild;
        } else {
            return;
        }
    }
    p = new Node;
    p->data = x;
    p->lchild = p->rchild = NULL;
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

void bst::Preorder() {
    Preorder(root); // Starting Preorder traversal from the root
}

int main() {
    bst tree;
    tree.Insert(5);
    tree.Insert(3);
    tree.Insert(8);
    tree.Insert(2);
    tree.Insert(4);
    cout<<"Preorder: ";
    tree.Preorder(); // Calling Preorder traversal function
    cout<<endl;
    return 0;
}
