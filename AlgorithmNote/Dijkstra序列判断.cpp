
#include <bits/stdc++.h>
using namespace std;
const int N = 1010, INF = 0x7fffffff;
int e[N][N], d[N], a[N], n, m;
bool dijkstra(int s) {
    fill(d, d + N, INF);
    bool vis[N] = {false};
    d[s] = 0;
    for (int i = 1; i <= n; i++) {
        int u = -1, MIN = INF;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1 || d[u] != d[a[i]]) return false;
        u = a[i];
        vis[u] = true;
        for (int v = 1; v <= n; v++) {
            if (!vis[v] && e[u][v] != INF && d[u] + e[u][v] < d[v]) {
                d[v] = d[u] + e[u][v];
            }
        }
    }
    return true;
}
int main() {
    fill(e[0], e[0] + N * N, INF);
    int u, v, dist;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &u, &v, &dist);
        e[u][v] = e[v][u] = dist;
    }
    scanf("%d", &m);
    while (m--) {
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        printf("%s\n", dijkstra(a[1]) ? "Yes" : "No");
    }
    return 0;
}