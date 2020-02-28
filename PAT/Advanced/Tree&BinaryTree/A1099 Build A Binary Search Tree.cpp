// https://pintia.cn/problem-sets/994805342720868352/problems/994805367987355648
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
struct node {
    int data, left, right;
} Node[N];
int in[N], n, pos = 0;
void inOrder(int i) {
    if (i == -1) return;
    inOrder(Node[i].left);
    Node[i].data = in[pos++];
    inOrder(Node[i].right);
}
void bfs(int root) {
    queue<int> q;
    q.push(root);
    int cnt = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        printf("%d", Node[now].data);
        if (++cnt < n) printf(" ");
        if (Node[now].left != -1) q.push(Node[now].left);
        if (Node[now].right != -1) q.push(Node[now].right);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%d", &Node[i].left, &Node[i].right);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    sort(in, in + n);
    inOrder(0);
    bfs(0);
    return 0;
}