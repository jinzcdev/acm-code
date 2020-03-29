// https://pintia.cn/problem-sets/15/problems/843
#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left, *right;
    node(int x) : data(x) {}
};
vector<int> pre, preMirror;
int n, cnt = 0;
bool isMirror = false;
void insert(node*& root, int x) {
    if (root == NULL) {
        root = new node(x);
        return;
    }
    if (x < root->data) insert(root->left, x);
    else insert(root->right, x);
}
void preOrder(node* root) {
    if (root == NULL) return;
    pre.push_back(root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void preOrderMirror(node* root) {
    if (root == NULL) return;
    preMirror.push_back(root->data);
    preOrderMirror(root->right);
    preOrderMirror(root->left);
}
void postOrder(node* root) {
    if (!root) return;
    if (isMirror) {
        postOrder(root->right);
        postOrder(root->left);
    } else {
        postOrder(root->left);
        postOrder(root->right);
    }
    printf("%d", root->data);
    if (++cnt < n) printf(" ");
}
int main() {
    scanf("%d", &n);
    vector<int> v(n);
    node* root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        insert(root, v[i]);
    }
    preOrder(root);
    preOrderMirror(root);
    if (v == pre || v == preMirror) {
        printf("YES\n");
        if (v == preMirror) isMirror = true;
        postOrder(root);
    } else {
        printf("NO\n");
    }
}