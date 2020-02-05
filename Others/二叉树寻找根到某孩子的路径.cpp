#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left, *right;
    node(int x) : data(x) { left = right = NULL; }
};
int pre[] = {1, 4, 3, 5, 8, 9, 2, 6, 7}, in[] = {3, 4, 8, 5, 9, 1, 6, 2, 7};
node* create(int prel, int prer, int inl, int inr) {
    if (prel > prer) return NULL;
    node* root = new node(pre[prel]);
    int k = inl;
    while (in[k] != pre[prel]) k++;
    int numleft = k - inl;
    root->left = create(prel + 1, prel + numleft, inl, k - 1);
    root->right = create(prel + numleft + 1, prer, k + 1, inr);
    return root;
}
// 寻找从根节点到x的路径
bool findPath(node* root, int x) {
    if (root == NULL) return false;
    if (root->data == x) {
        printf("%d ", x);
        return true;
    }
    if (findPath(root->left, x) || findPath(root->right, x)) {
        printf("%d ", root->data);
        return true;
    }
    return false;
}
int main() {
    int n = 9;
    // for (int i = 0; i < n; i++) scanf("%d", pre + i);
    // for (int i = 0; i < n; i++) scanf("%d", in + i);
    node* root = create(0, n - 1, 0, n - 1);
    findPath(root, 8);
    return 0;
}