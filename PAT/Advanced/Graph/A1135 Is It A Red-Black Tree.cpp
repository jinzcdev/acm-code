// https://pintia.cn/problem-sets/994805342720868352/problems/994805346063728640
#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left, *right;
    node(int x) : data(x) { left = right = NULL; }
};
void insert(node* &root, int x) {
    if (root == NULL) {
        root = new node(x);
        return;
    }
    if (abs(x) < abs(root->data)) insert(root->left, x);
    else insert(root->right, x);
}
bool isrbt;
int cntBlack = -1;
void dfs(node* root, int cnt) {
    if (root == NULL) {
        if (cntBlack == -1) cntBlack = cnt;
        else if (cntBlack != cnt) isrbt = false;
        return;
    }
    if (root->data < 0) {
        if (root->left != NULL && root->left->data < 0) isrbt = false;
        if (root->right != NULL && root->right->data < 0) isrbt = false;
    }
    dfs(root->left, root->data > 0 ? cnt + 1 : cnt);
    dfs(root->right, root->data > 0 ? cnt + 1 : cnt);
}
int main() {
    int k, n, x;
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &n);
        node* root = NULL;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            insert(root, x);
        }
        if (root->data < 0) printf("No\n");
        else {
            isrbt = true;
            cntBlack = -1;
            dfs(root, 0);
            printf("%s\n", isrbt ? "Yes" : "No");
        }
    }
    return 0;
}