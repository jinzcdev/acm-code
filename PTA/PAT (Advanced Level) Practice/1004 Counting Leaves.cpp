// https://pintia.cn/problem-sets/994805342720868352/problems/994805521431773184
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 110;
vector<int> tree[maxn];
int ans[maxn] = {0}, maxDepth = 1;
void DFS(int root, int depth) {
    if (tree[root].size() == 0) {
        ans[depth]++;
        maxDepth = max(depth, maxDepth);
        return;
    }
    for (int i = 0; i < tree[root].size(); i++) {
        DFS(tree[root][i], depth + 1);
    }
}
void BFS(int root) {
    queue<int> q;
    q.push(root);
    int h[maxn] = {0};
    h[root] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (tree[now].size() == 0) ans[h[now]]++;
        maxDepth = max(h[now], maxDepth);
        for (int i = 0; i < tree[now].size(); i++) {
            h[tree[now][i]] = h[now] + 1;
            q.push(tree[now][i]);
        }
    }
}
int main() {
    int n, m, k, parent, child;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &parent, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            tree[parent].push_back(child);
        }
    }
    DFS(1, 1);
    // BFS(1);
    for (int i = 1; i <= maxDepth; i++) {
        if (i != 1) printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}