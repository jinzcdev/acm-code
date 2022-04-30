// https://pintia.cn/problem-sets/15/problems/714
#include <bits/stdc++.h>
using namespace std;
int e[10][10], n, m;
bool vis[10];
void dfs(int u) {
    vis[u] = true;
    printf(" %d", u);
    for (int v = 0; v < n; v++)
        if (e[u][v] != 0 && !vis[v]) dfs(v);
}
void bfs(int u) {
    queue<int> q;
    q.push(u);
    vis[u] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        printf(" %d", now);
        for (int v = 0; v < n; v++) {
            if (e[now][v] != 0 && !vis[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        e[a][b] = e[b][a] = 1;
    }
    for (int i = 0; i < 2; i++) {
        fill(vis, vis + n, false);
        for (int u = 0; u < n; u++) {
            if (!vis[u]) {
                printf("{");
                if (i == 0)
                    dfs(u);
                else
                    bfs(u);
                printf(" }\n");
            }
        }
    }
    return 0;
}