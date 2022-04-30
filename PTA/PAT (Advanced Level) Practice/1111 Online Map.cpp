// https://pintia.cn/problem-sets/994805342720868352/problems/994805358663417856
#include <bits/stdc++.h>
using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
vector<int> e[N];
int n, m, st, dest, Dist[N][N], Time[N][N], d[N], t[N], num[N];
vector<int> dispre(N), timepre(N), dispath, timepath;
void dijkstraDistance(int s) {
    for (int i = 0; i < N; i++) dispre[i] = i;
    fill(d, d + N, INF);
    fill(t, t + N, INF);
    d[s] = t[s] = 0;
    bool vis[N] = {false};
    while (true) {
        int u = -1, MIN = INF;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && d[i] < MIN) {
                u = i;
                MIN = d[i];
            }
        }
        if (u == -1) break;
        vis[u] = true;
        for (auto v : e[u]) {
            if (!vis[v]) {
                if (d[u] + Dist[u][v] < d[v]) {
                    d[v] = d[u] + Dist[u][v];
                    t[v] = t[u] + Time[u][v];
                    dispre[v] = u;
                } else if (d[u] + Dist[u][v] == d[v] && t[u] + Time[u][v] < t[v]) {
                    t[v] = t[u] + Time[u][v];
                    dispre[v] = u;
                }
            }
        }
    }
}
void dijkstraTime(int s) {
    for (int i = 0; i < N; i++) timepre[i] = i;
    fill(num, num + N, INF);
    fill(t, t + N, INF);
    num[s] = t[s] = 0;
    bool vis[N] = {false};
    while (true) {
        int u = -1, MIN = INF;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && t[i] < MIN) {
                u = i;
                MIN = t[i];
            }
        }
        if (u == -1) break;
        vis[u] = true;
        for (auto v : e[u]) {
            if (!vis[v]) {
                if (t[u] + Time[u][v] < t[v]) {
                    t[v] = t[u] + Time[u][v];
                    num[v] = num[u] + 1;
                    timepre[v] = u;
                } else if (t[u] + Time[u][v] == t[v] && num[u] + 1 < num[v]) {
                    num[v] = num[u] + 1;
                    timepre[v] = u;
                }
            }
        }
    }
}
void dfsPath(vector<int> &pre, vector<int> &path, int u) {
    if (u == st) {
        path.push_back(u);
        return;
    }
    dfsPath(pre, path, pre[u]);
    path.push_back(u);
}
void printPath(vector<int> &path) {
    for (int i = 0; i < path.size(); i++) {
        if (i != 0) printf(" -> ");
        printf("%d", path[i]);
    }
    printf("\n");
}
int main() {
    scanf("%d%d", &n, &m);
    int a, b, oneway, len, time;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d%d%d", &a, &b, &oneway, &len, &time);
        e[a].push_back(b);
        if (oneway == 0) e[b].push_back(a);
        Dist[a][b] = Dist[b][a] = len;
        Time[a][b] = Time[b][a] = time;
    }
    scanf("%d%d", &st, &dest);
    dijkstraDistance(st);
    dijkstraTime(st);
    dfsPath(dispre, dispath, dest);
    dfsPath(timepre, timepath, dest);
    if (dispath == timepath) {
        printf("Distance = %d; Time = %d: ", d[dest], t[dest]);
        printPath(dispath);
    } else {
        printf("Distance = %d: ", d[dest]);
        printPath(dispath);
        printf("Time = %d: ", t[dest]);
        printPath(timepath);
    }
    return 0;
}