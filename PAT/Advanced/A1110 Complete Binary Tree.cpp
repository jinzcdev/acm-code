// https://pintia.cn/problem-sets/994805342720868352/problems/994805359372255232
#include <bits/stdc++.h>
using namespace std;
struct node {
    int left, right;
} Node[25];
int n, maxn = -1, ans;
void dfs(int root, int index) {
    if (root == -1) return;
    if (index > maxn) {
        maxn = index;
        ans = root;
    }
    dfs(Node[root].left, index * 2);
    dfs(Node[root].right, index * 2 + 1);
}
int main() {
    scanf("%d", &n);
    char a[5], b[5];
    int root = 0, has[25] = {0};
    for (int i = 0; i < n; i++) {
        Node[i].left = Node[i].right = -1;
        scanf("%s %s", a, b);
        if (a[0] != '-') {
            Node[i].left = stoi(a);
            has[stoi(a)] = 1;
        }
        if (b[0] != '-') {
            Node[i].right = stoi(b);
            has[stoi(b)] = 1;
        }
    }
    while (has[root]) root++;
    dfs(root, 1);
    if (maxn == n) printf("YES %d", ans);
    else printf("NO %d", root);
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
struct node {
    int left, right;
} Node[25];
int n, cnt = 0, last = -1;
bool iscbt(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty() && cnt++ < n) {
        int now = q.front();
        q.pop();
        if (now == -1) return false;
        last = now;
        q.push(Node[now].left);
        q.push(Node[now].right);
    }
    return true;
}
int main() {
    scanf("%d", &n);
    char a[5], b[5];
    int root = 0, has[25] = {0};
    for (int i = 0; i < n; i++) {
        Node[i].left = Node[i].right = -1;
        scanf("%s %s", a, b);
        if (a[0] != '-') {
            Node[i].left = stoi(a);
            has[stoi(a)] = 1;
        }
        if (b[0] != '-') {
            Node[i].right = stoi(b);
            has[stoi(b)] = 1;
        }
    }
    while (has[root]) root++;
    if (iscbt(root)) printf("YES %d", last);
    else printf("NO %d", root);
    return 0;
}
*/


/*
#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int maxn = 30;
struct node {
    int lchild, rchild;
} CBT[maxn];

int N, root, last = 2;
bool flag[maxn] = {false}, isCBT = true;

void BFS(int _root) {
    queue<int> q;
    q.push(_root);
    int count = 0, k = -1, now;
    while (!q.empty() && count++ < N) {
        now = q.front();
        q.pop();
        if (now == -1) isCBT = false;
        q.push(CBT[now].lchild);
        q.push(CBT[now].rchild);
    }
    last = now;
}

int convertInteger(string s) {
    if (s == "-") return -1;
    if (s.length() == 1) return s[0] - '0';
    else return (s[0] - '0') * 10 + (s[1] - '0');
}

int getRoot() {
    int i = 0;
    while (flag[i] && i < N) i++;
    return i;
}

int main() {
    scanf("%d", &N);
    string ls, rs;
    int lchild, rchild, temp, root;
    for (int i = 0; i < N; i++) {
        cin >> ls;
        cin >> rs;
        lchild = convertInteger(ls);
        rchild = convertInteger(rs);
        CBT[i].lchild = lchild;
        CBT[i].rchild = rchild;
        if (lchild != -1) flag[lchild] = true;
        if (rchild != -1) flag[rchild] = true;
    }
    root = getRoot();
    BFS(root);
    if (!isCBT) cout << "NO " << root;
    else cout << "YES " << last;
    return 0;
}
*/