#include <bits/stdc++.h>
using namespace std;
struct node {
    int data, left, right;
} tree[15];
int n, root = 0, cnt = 0;
void levelOrder(int root) {
    queue<node> q;
    q.push(tree[root]);
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        printf("%d", now.data);
        if (++cnt < n) printf(" ");
        if (now.left != -1) q.push(tree[now.left]);
        if (now.right != -1) q.push(tree[now.right]);
    }
    printf("\n");
}
void inOrder(int root) {
    if (root == -1) return;
    inOrder(tree[root].left);
    printf("%d", tree[root].data);
    if (++cnt < n) printf(" ");
    inOrder(tree[root].right);
}
int main() {
    scanf("%d", &n);
    char a, b;
    bool vis[15] = {false};
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c %c", &a, &b);
        tree[i].data = i;
        tree[i].left = tree[i].right = -1;
        if (a != '-') {
            tree[i].right = a - '0';
            vis[a - '0'] = true;
        }
        if (b != '-') {
            tree[i].left = b - '0';
            vis[b - '0'] = true;
        }
    }
    while (vis[root]) root++;
    levelOrder(root);
    cnt = 0;
    inOrder(root);
}