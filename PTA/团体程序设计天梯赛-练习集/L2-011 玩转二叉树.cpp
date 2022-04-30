// https://pintia.cn/problem-sets/994805046380707840/problems/994805065406070784
#include <bits/stdc++.h>
using namespace std;
const int N = 35;
int n, cnt = 0, maxDepth = -1, pre[N], in[N];
vector<int> ans[N];
void solve(int prel, int prer, int inl, int inr, int depth) {
    if (prel > prer) return;
    maxDepth = max(maxDepth, depth);
    ans[depth].push_back(pre[prel]);
    int k = inl;
    while (in[k] != pre[prel]) k++;
    int numleft = k - inl;
    solve(prel + numleft + 1, prer, k + 1, inr, depth + 1);
    solve(prel + 1, prel + numleft, inl, k - 1, depth + 1);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    solve(0, n - 1, 0, n - 1, 0);
    for (int i = 0; i <= maxDepth; i++) {
        for (auto it : ans[i]) {
            printf("%d", it);
            if (++cnt < n) printf(" ");
        }
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
const int N = 35;
struct node {
    int data;
    node *left, *right;
    node(int x) : data(x) { left = right = NULL; }
};
int n, pre[N], in[N], cnt = 0;
node *create(int prel, int prer, int inl, int inr) {
    if (prel > prer) return NULL;
    node *root = new node(pre[prel]);
    int k = inl;
    while (in[k] != pre[prel]) k++;
    int numleft = k - inl;
    root->left = create(prel + numleft + 1, prer, k + 1, inr);
    root->right = create(prel + 1, prel + numleft, inl, k - 1);
    return root;
}
void bfs(node *root) {
    queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        node *now = q.front();
        q.pop();
        printf("%d", now->data);
        if (++cnt < n) printf(" ");
        if (now->left != NULL) q.push(now->left);
        if (now->right != NULL) q.push(now->right);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    node *root = create(0, n - 1, 0, n - 1);
    bfs(root);
    return 0;
}
*/