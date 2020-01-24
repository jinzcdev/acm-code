#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left, *right;
    node(int _data) : data(_data) { left = right = NULL; }
};
void insert(node*& root, int x) {
    if (root == NULL) {
        root = new node(x);
        return;
    }
    if (abs(x) < abs(root->data)) insert(root->left, x);
    else insert(root->right, x);
}
bool a, b;
int cntBlack = -1;
void dfs(node* root, int cnt) {
    if (root == NULL) {
        if (cntBlack == -1) cntBlack = cnt;
        else if (cntBlack != cnt) b = false;
        return;
    }
    if (root->data < 0) {
        if ((root->left != NULL && root->left->data < 0) ||
            (root->right != NULL && root->right->data < 0))
            a = false;
    }
    dfs(root->left, root->data > 0 ? cnt + 1 : cnt);
    dfs(root->right, root->data > 0 ? cnt + 1 : cnt);
}
int main() {
    int k, n, x;
    cin >> k;
    while (k--) {
        cin >> n;
        node* root = NULL;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            insert(root, x);
        }
        if (root->data < 0) {
            printf("No\n");
        } else {
            a = b = true;
            cntBlack = -1;
            dfs(root, 1);
            printf("%s\n", a && b ? "Yes" : "No");
        }
    }
    return 0;
}