// https://pintia.cn/problem-sets/994805342720868352/problems/994805489282433024
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int INF = 0x7FFFFFFF;
int G[maxn][maxn], weight[maxn];
int d[maxn], vis[maxn] = {false};
int c, n, sp, m, st = 0;
int minRemain = INF, minNeed = INF;
vector<int> pre[maxn];          // 存放最短路径
vector<int> path, tempPath;

void Dijkstra(int s) {
    fill(d, d + maxn, INF);     // 所有顶点之间距离无穷大
    d[s] = 0;
    for (int i = 0; i <= n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j <= n; j++) {
            if (!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v <= n; v++) {
            if (!vis[v] && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
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

void DFS(int v) {
    if (v == st) {
        tempPath.push_back(v);
        int remain = 0, need = 0;
        for (int i = tempPath.size() - 2; i >= 0 ; i--) {
            int id = tempPath[i];
            if (weight[id] > 0) {       // 该站点车辆数大于完美数量
                remain += weight[id];   // 工作人员携带走的车辆数+=该点多出车辆
            } else {                    // 该站点车辆数小于完美数量
                if (remain >= abs(weight[id])) {    // 比较当前工作人员携带的富余车辆够不够填补此站点
                    remain -= abs(weight[id]);      // 够填补则"携带车辆"减去填补数
                } else {                                // 不够填补
                    need += abs(weight[id]) - remain;   // 则需要从PBMC调出的车辆数+=不够的车辆
                    remain = 0;                         // 此前携带的车辆全部填补该站点
                }
            }
        }
        if (need < minNeed) {       // "需要从PBMC携带的车辆数少"优先
            minNeed = need;
            minRemain = remain;
            path = tempPath;
        } else if (need == minNeed && remain < minRemain) { // 若多条路径需申请车辆数相同, 则"带回车辆数少"优先
            minRemain = remain;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++) {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}

int main(){
    scanf("%d%d%d%d", &c, &n, &sp, &m);
    fill(G[0], G[0] + maxn * maxn, INF);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
        weight[i] -= c / 2;     // ">0":多于完美状态车辆数, 反之亦然
    }
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijkstra(st);       // 起点为0(题目指定PBMC为0)
    DFS(sp);            // 从终点开始DFS
    printf("%d ", minNeed);
    for (int i = path.size() - 1; i >= 0; i--) {
        if (i != path.size() - 1) printf("->");
        printf("%d", path[i]);
    }
    printf(" %d", minRemain);
    return 0;
}