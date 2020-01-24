#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *lchild, *rchild;
};
int n;
vector<int> pre, in;
int solve(node* root) {
    if (root == NULL) return -1;
    if (root->lchild == NULL && root->rchild == NULL) return root->data;
    if (root->lchild != NULL) return solve(root->lchild);
    return solve(root->rchild);
}
node* create(int preL, int preR, int inL, int inR) {
    if (inL > inR) return NULL;
    node* root = new node;
    root->data = pre[preL];
    int k = inL;
    while (in[k] != pre[preL]) k++;
    int leftNum = k - inL;
    root->lchild = create(preL + 1, preL + leftNum, inL, k - 1);
    root->rchild = create(preL + leftNum + 1, preR, k + 1, inR);
    return root;
}
int main() {
    scanf("%d", &n);
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    node* root = create(0, n - 1, 0, n - 1);
    printf("%d", solve(root));
    return 0;
}
