// https://pintia.cn/problem-sets/994805342720868352/problems/994805358663417856
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3FFFFFFF;
int G[510][510], T[510][510], d[510], t[510], num[510];
vector<int> dispath, timepath, dispre(510), timepre(510);
int st, dest, n, m;

void dfsDis(int dest) {
    if (dest == st) {
        dispath.push_back(dest);
        return;
    }
    dfsDis(dispre[dest]);
    dispath.push_back(dest);
}

void dfsTime(int dest) {
    if (dest == st) {
        timepath.push_back(dest);
        return;
    }
    dfsTime(timepre[dest]);
    timepath.push_back(dest);
}

void dijkstraDis(int u) {
    bool vis[510] = {false};
    int temp[510];
    fill(d, d + n, INF);
    fill(temp, temp + n, INF);
    d[u] = temp[u] = 0;
    while (u != -1) {
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    dispre[v] = u;
                    temp[v] = temp[u] + T[u][v];
                } else if (d[v] == d[u] + G[u][v] && temp[u] + T[u][v] < temp[v]) {
                    dispre[v] = u;
                    temp[v] = T[u][v] + temp[u];
                }
            }
        }
        u = -1;
        for (int i = 0, MIN = INF; i < n; i++) {
            if (vis[i] == false && d[i] < MIN) {
                MIN = d[i];
                u = i;
            }
        }
    }
}

void dijkstraTime(int u) {
    bool vis[510] = {false};
    fill(t, t + n, INF);
    fill(num, num + n, INF);
    t[u] = 0;
    num[u] = 0;
    while (u != -1) {
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && T[u][v] != INF) {
                if (t[u] + T[u][v] < t[v]) {
                    t[v] = t[u] + T[u][v];
                    timepre[v] = u;
                    num[v] = num[u] + 1;
                } else if (t[u] + T[u][v] == t[v] && num[u] + 1 < num[v]) {
                    timepre[v] = u;
                    num[v] = num[u] + 1;
                }
            }
        }
        u = -1;
        for (int i = 0, MIN = INF; i < n; i++) {
            if (vis[i] == false && t[i] < MIN) {
                MIN = t[i];
                u = i;
            }
        }
    }
}

void printPath(vector<int> &path) {
    for (int i = 0; i < path.size(); i++) {
        if (i != 0) printf(" ->");
        printf(" %d", path[i]);
    }
}

int main() {
    fill(G[0], G[0] + 510 * 510, INF);
    fill(T[0], T[0] + 510 * 510, INF);
    scanf("%d%d", &n, &m);
    int u, v, oneway;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &oneway);
        scanf("%d%d", &G[u][v], &T[u][v]);
        if (oneway == 0) {
            G[v][u] = G[u][v];
            T[v][u] = T[u][v];
        }
    }
    scanf("%d%d", &st, &dest);
    dijkstraTime(st);
    dijkstraDis(st);
    dfsTime(dest);
    dfsDis(dest);
    if (dispath == timepath) {
        printf("Distance = %d; Time = %d:", d[dest], t[dest]);
        printPath(dispath);
    } else {
        printf("Distance = %d:", d[dest]);
        printPath(dispath);
        printf("\nTime = %d:", t[dest]);
        printPath(timepath);
    }
    return 0;
}