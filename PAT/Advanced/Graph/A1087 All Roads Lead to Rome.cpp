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
/*
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
const int maxn = 210;
const int INF = 0x7FFFFFFF;
int n, k, st = 0, rom;                  // 基本输入信息
int G[maxn][maxn], weight[maxn];        // 矩阵表示图, 各vertex权值(题中即happiness)
int d[maxn], cntPath = 0, maxW = -1;    // 最短路径, 最短路径个, 最短路径点权值和(题中即总开心值)
double maxAvg = -1;                     // 各个顶点平均开心值
bool vis[maxn] = {false};
map<string, int> cityToIndex;   // city  ->  index
map<int, string> indexToCity;   // index ->  city
vector<int> pre[maxn];          // 最短路径树(保存满足第一标尺的多条路径成树结构以做DFS).pre[v][u]表示u是v的上个邻接点
vector<int> path, tempPath;

void Dijkstra(int s){
    fill(d, d + maxn, INF);     // 出发点至各顶点距离为无穷大
    d[s] = 0;
    for (int i = 0; i < n; i++){
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++){
            if (!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < n; v++){
            if (!vis[v] && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {        // 出现更短的路径值
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (d[u] + G[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int v) {       // 终点向回DFS
    if (v == st) {      // 递归边界: 到达叶子节点(即出发地点)
        cntPath++;
        tempPath.push_back(v);
        // ------------------ 逻辑起点 ------------------
        int tempW = 0;
        for (int i = tempPath.size() - 1 - 1; i >= 0; i--){     // 计算点权和(即开心值)
            tempW += weight[tempPath[i]];
        }
        double tempAvg = tempW * 1.0 / (tempPath.size() - 1);   // 途径的地点数需剪去出发地(即-1)
        if (tempW > maxW) {                             // 开心值优先
            maxW = tempW;
            maxAvg = tempAvg;
            path = tempPath;
        } else if (tempW == maxW && tempAvg > maxAvg) { // 开心值相等, 则比较平均开心值
            maxAvg = tempAvg;
            path = tempPath;
        }
        // ------------------ 逻辑结束 ------------------
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for (int u = 0; u < pre[v].size(); u++){
        DFS(pre[v][u]);
    }
    tempPath.pop_back();
}

int main(){
    string start, city, city1, city2;
    cin >> n >> k >> start;
    cityToIndex[start] = 0;
    indexToCity[0] = start;
    for (int i = 1; i <= n - 1; i++){
        cin >> city >> weight[i];
        cityToIndex[city] = i;
        indexToCity[i] = city;
    }
    fill(G[0], G[0] + maxn * maxn, INF);
    for (int i = 0; i < k; i++){
        cin >> city1 >> city2;
        int c1 = cityToIndex[city1], c2 = cityToIndex[city2];
        cin >> G[c1][c2];
        G[c2][c1] = G[c1][c2];
    }
    rom = cityToIndex["ROM"];
    Dijkstra(st);
    DFS(rom);
    printf("%d %d %d %d\n", cntPath, d[rom], maxW, (int)maxAvg);
    for (int i = path.size() - 1; i >= 0; i--){
        if (i != path.size() - 1) printf("->");
        cout << indexToCity[path[i]];
    }
    return 0;
}
*/