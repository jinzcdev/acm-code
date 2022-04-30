// https://pintia.cn/problem-sets/994805342720868352/problems/994805355987451904
#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left, *right;
    node(int x) : data(x) { left = right = NULL; }
};
int cnt[1010] = {0}, maxDepth = -1;
void insert(node *&root, int x, int depth) {
    if (root == NULL) {
        root = new node(x);
        cnt[depth]++;
        if (depth > maxDepth) maxDepth = depth;
        return;
    }
    if (x <= root->data) insert(root->left, x, depth + 1);
    else insert(root->right, x, depth + 1);
}
void dfs(node *root, int depth) {
    if (root == NULL) return;
    cnt[depth]++;
    if (depth > maxDepth) maxDepth = depth;
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}
int main() {
    int n, x;
    scanf("%d", &n);
    node *root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(root, x, 1);
    }
    // dfs(root, 1);
    printf("%d + %d = %d", cnt[maxDepth], cnt[maxDepth - 1], cnt[maxDepth] + cnt[maxDepth - 1]);
    return 0;
}