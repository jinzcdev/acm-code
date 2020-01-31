// https://pintia.cn/problem-sets/1203317538312806400/problems/1203317626619691011
#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left, *right;
    node (int x) : data(x) {
        left = right = NULL;
    }
};
int n;
vector<int> v;
int findMinIndex(int left, int right) {
    int pos = left, Min = v[left];
    for (int i = left; i <= right; i++) {
        if (v[i] < Min) {
            Min = v[i];
            pos = i;
        }
    }
    return pos;
}
node* create(int left, int right) {
    if (left > right) return NULL;
    int rootIndex = findMinIndex(left, right);
    node* root = new node(v[rootIndex]);
    root->left = create(left, rootIndex - 1);
    root->right = create(rootIndex + 1, right);
    return root;
}
int cnt = 0;
void bfs(node *root) {
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* now = q.front();
        q.pop();
        printf("%d", now->data);
        if (++cnt < n) printf(" ");
        if (now->left != NULL) q.push(now->left);
        if (now->right != NULL) q.push(now->right);
    }
}
int main() {
    scanf("%d", &n);
    v.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    node* root = create(0, n - 1);
    bfs(root);
    return 0;
}