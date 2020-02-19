#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left, *right;
    node(int x) : data(x) { left = right = NULL; }
};
vector<int> a;
void inOrder(node* root) {
    stack<node*> s;
    node* p = root;
    while (!s.empty() || p != NULL) {
        while (p != NULL) {
            s.push(p);
            p = p->left;
        } 
        p = s.top();
        s.pop();
        cout << p->data << " ";
        p = p->right;
    }
}
node* create(vector<int>& a, int i) {
    if (i >= a.size() || a[i] == -1) return NULL;
    node* root = new node(a[i]);
    root->left = create(a, i * 2);
    root->right = create(a, i * 2 + 1);
    return root;
}
int main() {
    int temp[] = {-1, 5, 1, 4, -1, -1, 3, 6};
    for (int i = 0; i < 8; i++) {
        a.push_back(temp[i]);
    }
    node* root = create(a, 1);
    inOrder(root);
    return 0;
}