// https://pintia.cn/problem-sets/994805342720868352/problems/994805464397627392
#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int INF = 0x7fffffff;
int n, m, st, dest, e[N][N], cost[N][N] = {0}, d[N];
vector<int> path, tempPath, pre[N];
int minCost = INF;
void dfs(int u) {
    tempPath.push_back(u);
    if (u == st) {
        int tempCost = 0;
        for (int i = 0; i < tempPath.size() - 1; i++)
            tempCost += cost[tempPath[i]][tempPath[i + 1]];
        if (tempCost < minCost) {
            minCost = tempCost;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    for (auto it : pre[u]) dfs(it);
    tempPath.pop_back();
}
void dijkstra(int s) {
    fill(d, d + N, INF);
    d[s] = 0;
    bool vis[N] = {false};
    while (true) {
        int u = -1, MIN = INF;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && d[i] < MIN) {
                MIN = d[i];
                u = i;
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (!vis[v] && e[u][v] != INF) {
                if (d[u] + e[u][v] < d[v]) {
                    d[v] = d[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (d[u] + e[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}
int main() {
    scanf("%d%d%d%d", &n, &m, &st, &dest);
    int u, v, tdist, tcost;
    fill(e[0], e[0] + N * N, INF);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d%d", &u, &v, &tdist, &tcost);
        e[u][v] = e[v][u] = tdist;
        cost[u][v] = cost[v][u] = tcost;
    }
    dijkstra(st);
    dfs(dest);
    for (int i = path.size() - 1; i >= 0; i--) printf("%d ", path[i]);
    printf("%d %d", d[dest], minCost);
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int INF = 0x7fffffff;
int n, m, st, dest, e[N][N], cost[N][N] = {0}, d[N], c[N];
vector<int> pre(N);
int minCost = INF;
void dfs(int u) {
    if (u == st) {
        printf("%d ", u);
        return;
    }
    dfs(pre[u]);
    printf("%d ", u);
}
void dijkstra(int s) {
    fill(d, d + N, INF);
    fill(c, c + N, INF);
    d[s] = c[s] = 0;
    bool vis[N] = {false};
    while (true) {
        int u = -1, MIN = INF;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && d[i] < MIN) {
                MIN = d[i];
                u = i;
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (!vis[v] && e[u][v] != INF) {
                if (d[u] + e[u][v] < d[v]) {
                    d[v] = d[u] + e[u][v];
                    c[v] = c[u] + cost[u][v];
                    pre[v] = u;
                } else if (d[u] + e[u][v] == d[v] && c[u] + cost[u][v] < c[v]) {
                    c[v] = c[u] + cost[u][v];
                    pre[v] = u;
                }
            }
        }
    }
}
int main() {
    scanf("%d%d%d%d", &n, &m, &st, &dest);
    int u, v, tdist, tcost;
    fill(e[0], e[0] + N * N, INF);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d%d", &u, &v, &tdist, &tcost);
        e[u][v] = e[v][u] = tdist;
        cost[u][v] = cost[v][u] = tcost;
    }
    dijkstra(st);
    dfs(dest);
    printf("%d %d", d[dest], c[dest]);
    return 0;
}
*/