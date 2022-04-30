// https://pintia.cn/problem-sets/994805342720868352/problems/994805379664297984
#include <bits/stdc++.h>
using namespace std;
const int N = 210, INF = 0x3f3f3f3f;
int e[N][N], d[N], weight[N] = {0}, n, m, st = 0, dest, cntPath = 0;
vector<int> pre[N], path, tempPath;
void dijkstra(int s) {
    fill(d, d + N, INF);
    d[s] = 0;
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
int maxW = -1;
double maxAvg = -1;
void dfs(int u, int sum, int cnt) {
    tempPath.push_back(u);
    if (u == st) {
        cntPath++;
        if (sum < maxW) return;
        int tempAvg = sum * 1.0 / cnt;
        if (sum > maxW || tempAvg > maxAvg) {
            maxW = sum;
            maxAvg = tempAvg;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    for (auto next : pre[u]) dfs(next, sum + weight[next], cnt + 1);
    tempPath.pop_back();
}
int main() {
    int temp, a, b;
    string start, s, city1, city2;
    cin >> n >> m >> start;
    unordered_map<string, int> nametoid;
    unordered_map<int, string> idtoname;
    for (int i = 1; i <= n - 1; i++) {
        cin >> s >> weight[i];
        nametoid[s] = i;
        idtoname[i] = s;
    }
    fill(e[0], e[0] + N * N, INF);
    for (int i = 0; i < m; i++) {
        cin >> city1 >> city2 >> temp;
        int a = nametoid[city1], b = nametoid[city2];
        e[a][b] = e[b][a] = temp;
    }
    dest = nametoid["ROM"];
    dijkstra(0);
    dfs(dest, weight[dest], 0);
    printf("%d %d %d %d\n%s", cntPath, d[dest], maxW, (int)maxAvg, start.c_str());
    for (int i = path.size() - 2; i >= 0; i--)
        printf("->%s", idtoname[path[i]].c_str());
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
const int N = 210, INF = 0x3f3f3f3f;
int e[N][N], d[N], hp[N] = {0}, n, m, cntRoute = 0;
vector<int> pre[N], path, tempPath;
void dijkstra(int s) {
    fill(d, d + N, INF);
    d[s] = 0;
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
int maxHp = -1;
double maxAvg = -1;
void dfs(int u) {
    tempPath.push_back(u);
    if (pre[u].size() == 0) {
        int tempHp = 0;
        for (int i = 0; i < tempPath.size(); i++) tempHp += hp[tempPath[i]];
        double tempAvg = tempHp * 1.0 / (tempPath.size() - 1);
        if (tempHp > maxHp || (tempHp == maxHp && tempAvg > maxAvg)) {
            maxHp = tempHp;
            maxAvg = tempAvg;
            path = tempPath;
        }
        tempPath.pop_back();
        cntRoute++;
        return;
    }
    for (auto v : pre[u]) dfs(v);
    tempPath.pop_back();
}
int main() {
    int temp, a, b;
    string st, s, city1, city2;
    cin >> n >> m >> st;
    unordered_map<string, int> nametoid;
    unordered_map<int, string> idtoname;
    for (int i = 1; i <= n - 1; i++) {
        cin >> s >> hp[i];
        nametoid[s] = i;
        idtoname[i] = s;
    }
    fill(e[0], e[0] + N * N, INF);
    for (int i = 0; i < m; i++) {
        cin >> city1 >> city2 >> temp;
        int a = nametoid[city1], b = nametoid[city2];
        e[a][b] = e[b][a] = temp;
    }
    int dest = nametoid["ROM"];
    dijkstra(0);
    dfs(dest);
    printf("%d %d %d %d\n%s", cntRoute, d[dest], maxHp, (int)maxAvg, st.c_str());
    for (int i = path.size() - 2; i >= 0; i--)
        printf("->%s", idtoname[path[i]].c_str());
    return 0;
}
*/