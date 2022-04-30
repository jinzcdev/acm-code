// https://pintia.cn/problem-sets/994805342720868352/problems/994805365537882112
#include <bits/stdc++.h>
using namespace std;
struct node {
    int data, left, right;
} Node[10];
int n, cnt = 0;
void inOrder(int root) {
    if (root == -1) return;
    inOrder(Node[root].left);
    printf("%d", Node[root].data);
    if (++cnt < n) printf(" ");
    inOrder(Node[root].right);
}
void bfs(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        printf("%d", Node[now].data);
        if (++cnt < n) printf(" ");
        if (Node[now].left != -1) q.push(Node[now].left);
        if (Node[now].right != -1) q.push(Node[now].right);
    }
    printf("\n");
}
int main() {
    scanf("%d", &n);
    char a, b;
    bool hash[10] = {false};
    for (int i = 0; i < n; i++) {
        getchar();
        Node[i].data = i;
        Node[i].left = Node[i].right = -1;
        scanf("%c %c", &a, &b);
        if (a != '-') {
            Node[i].right = a - '0';
            hash[a - '0'] = true;
        }
        if (b != '-') {
            Node[i].left = b - '0';
            hash[b - '0'] = true;
        }
    }
    int root = 0;
    while (hash[root]) root++;
    bfs(root);
    cnt = 0;
    inOrder(root);
    return 0;
}