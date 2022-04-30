// https://pintia.cn/problem-sets/994805342720868352/problems/994805482919673856
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
vector<int> e[N], ans;
int maxDepth = -1, tempMaxDepth = -1;
bool vis[N] = {false};
void dfs(int u, int depth) {
    vis[u] = true;
    tempMaxDepth = max(tempMaxDepth, depth);
    for (auto it : e[u]) {
        if (!vis[it]) {
            dfs(it, depth + 1);
        }
    }
}
int main() {
    int n, a, b, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 1);
            cnt++;
        }
    }
    if (cnt > 1)
        printf("Error: %d components\n", cnt);
    else {
        for (int i = 1; i <= n; i++) {
            fill(vis, vis + N, false);
            tempMaxDepth = -1;
            dfs(i, 1);
            if (tempMaxDepth > maxDepth) {
                maxDepth = tempMaxDepth;
                ans.clear();
                ans.push_back(i);
            } else if (tempMaxDepth == maxDepth) {
                ans.push_back(i);
            }
        }
        for (auto it : ans) printf("%d\n", it);
    }
    return 0;
}