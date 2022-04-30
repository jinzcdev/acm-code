// https://pintia.cn/problem-sets/994805342720868352/problems/994805367987355648
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
struct node {
    int x, left, right;
} bst[N];
int in[N], n, cnt = 0, pos = 0;
void inOrder(int i) {
    if (i == -1) return;
    inOrder(bst[i].left);
    bst[i].x = in[pos++];
    inOrder(bst[i].right);
}
void levelOrder(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        printf("%d", bst[now].x);
        if (++cnt < n) printf(" ");
        if (bst[now].left != -1) q.push(bst[now].left);
        if (bst[now].right != -1) q.push(bst[now].right);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &bst[i].left, &bst[i].right);
    }
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    sort(in, in + n);
    inOrder(0);
    levelOrder(0);
    return 0;
}