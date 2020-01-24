#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node* left;
    node* right;
    node(int _data) : data(_data) { left = right = NULL; };
};
void visit(node* root) { cout << root->data; }
void preOrder1(node* root) {
    stack<node*> s;
    node* p = root;
    while (p != NULL || !s.empty()) {
        while (p != NULL) {
            s.push(p);
            p = p->left;
        }
        if (!s.empty()) {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}
void preOrder(node* root) {
    stack<node*> s;
    s.push(root);
    char ans[9999];
    while (!s.empty()) {
        node* p = s.top();
        s.pop();
        visit(p);
        if (p->right != NULL) s.push(p->right);
        if (p->left != NULL) s.push(p->left);
    }
}

int main() {
    node* root = new node(1);
    node* left = new node(2);
    left->left = new node(4);
    left->right = new node(5);
    node* right = new node(3);
    // right->right = new node(6);
    root->left = left;
    root->right = right;
    preOrder(root);
    return 0;
}