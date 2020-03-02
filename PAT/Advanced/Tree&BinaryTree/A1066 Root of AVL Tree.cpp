// https://pintia.cn/problem-sets/994805342720868352/problems/994805404939173888
#include <bits/stdc++.h>
using namespace std;
struct node {
    int data, height;
    node *left, *right;
    node(int x) : data(x) {
        height = 1;
        left = right = NULL;
    }
};
int getHeight(node *root) {
    if (root == NULL) return 0;
    return root->height;
}
void updateHeight(node *root) {
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}
int getBalanceFactor(node *root) {
    return getHeight(root->left) - getHeight(root->right);
}
void L(node *&root) {
    node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
void R(node *&root) {
    node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
void insert(node *&root, int x) {
    if (root == NULL) {
        root = new node(x);
        return;
    }
    if (x < root->data) {
        insert(root->left, x);
        updateHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->left) == -1) L(root->left);
            R(root);
        }
    } else {
        insert(root->right, x);
        updateHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->right) == 1) R(root->right);
            L(root);
        }
    }
}
int main() {
    int n, temp;
    scanf("%d", &n);
    node *root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        insert(root, temp);
    }
    printf("%d", root->data);
    return 0;
}