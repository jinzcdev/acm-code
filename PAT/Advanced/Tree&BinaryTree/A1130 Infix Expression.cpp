// https://pintia.cn/problem-sets/994805342720868352/problems/994805347921805312
#include <bits/stdc++.h>
using namespace std;
struct node {
    string val;
    int left, right;
} bt[25];
int root = 1;
bool isleaf(int i) { return bt[i].left == -1 && bt[i].right == -1; }
void infixExp(int i) {
    if (i == -1) return;
    if (isleaf(i)) {
        cout << bt[i].val;
        return;
    }
    if (i != root) printf("(");
    infixExp(bt[i].left);
    cout << bt[i].val;
    infixExp(bt[i].right);
    if (i != root) printf(")");
}
int main() {
    int n;
    cin >> n;
    bool vis[25] = {false};
    for (int i = 1; i <= n; i++) {
        cin >> bt[i].val >> bt[i].left >> bt[i].right;
        if (bt[i].left != -1) vis[bt[i].left] = true;
        if (bt[i].right != -1) vis[bt[i].right] = true;
    }
    while (vis[root]) root++;
    infixExp(root);
    return 0;
}

/*
// https://pintia.cn/problem-sets/994805342720868352/problems/994805347921805312
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
    if (n == 1) cout << bt[root].data;
    else {
        string ans = inOrder(root);
        cout << ans.substr(1, ans.length() - 2);
    }
    return 0;
}

*/