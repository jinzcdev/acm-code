// https://pintia.cn/problem-sets/994805342720868352/problems/994805347921805312
#include <bits/stdc++.h>
using namespace std;
struct node {
    char data[15];
    int left, right;
} Node[30];
int n, root = 1;
bool isOperator(int i) { return Node[i].left != -1 || Node[i].right != -1; }
void inOrder(int i) {
    if (i == -1) return;
    if (i != root && isOperator(i)) printf("(");
    inOrder(Node[i].left);
    printf("%s", Node[i].data);
    inOrder(Node[i].right);
    if (i != root && isOperator(i)) printf(")");
}
int main() {
    scanf("%d", &n);
    unordered_map<int, bool> vis;
    for (int i = 1; i <= n; i++) {
        scanf("%s%d%d", Node[i].data, &Node[i].left, &Node[i].right);
        vis[Node[i].left] = vis[Node[i].right] = true;
    }
    while (vis[root]) root++;
    inOrder(root);
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
struct node {
    string data;
    int lc, rc;
} bt[25];
bool isOperator(int adr) { return bt[adr].lc != -1 || bt[adr].rc != -1; }
string inOrder(int i) {
    if (i == -1) return "";
    if (!isOperator(i)) {
        return bt[i].data;
    }
    return "(" + inOrder(bt[i].lc) + bt[i].data + inOrder(bt[i].rc) + ")";
}
int main() {
    int n;
    cin >> n;
    bool vis[25] = {false};
    for (int i = 1; i <= n; i++) {
        cin >> bt[i].data >> bt[i].lc >> bt[i].rc;
        if (bt[i].lc != -1) vis[bt[i].lc] = true;
        if (bt[i].rc != -1) vis[bt[i].rc] = true;
    }
    int root = 1;
    while (vis[root]) root++;
    if (n == 1)
        cout << bt[root].data;
    else {
        string ans = inOrder(root);
        cout << ans.substr(1, ans.length() - 2);
    }
    return 0;
}
*/