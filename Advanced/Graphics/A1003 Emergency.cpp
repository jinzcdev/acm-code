// https://pintia.cn/problem-sets/994805342720868352/problems/994805523835109376
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int INF = 0x7FFFFFFF; // 用16进制表示整型最大值

int n, m, start, dest;              // start, dest 分别表示起点终点
int G[maxn][maxn], weight[maxn];    // 矩阵表示图/每个结点的权值
int d[maxn], w[maxn] = {0}, num[maxn] = {0};    // 最短路径数组, w[u]表示从s->u的最大点权和, num[u]表示从s->u的最短路径个数
bool vis[maxn] = {false};

void Dijkstra(int s){
    fill(d, d + n, INF);    // 用无穷大表示起点s->all都无路径
    d[s] = 0;               // s->s的最短距离为0
    w[s] = weight[s];       // s->s的最小点权和为0
    num[s] = 1;             // s->s的最短路径个数为1
    for (int i = 0; i < n; i++){        // 循环n次, 每一次都从离上个起点最近的点开始继续向下记录
        int u = -1, MIN = INF;          // 最小值取INF, 只要小于INF则表示连通
        for (int j = 0; j < n; j++){
            if (!vis[j] && d[j] < MIN){ // "未访问"以避免选中上一个起点
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;            // u=-1表示u的上一个出发结点并无与之连通的结点
        vis[u] = true;                  // 只对出发的起点做已访问的标记
        for (int v = 0; v < n; v++){
            if (!vis[v] && G[u][v] != INF) {    // v未访问过, 且u->v存在边
                if (d[u] + G[u][v] < d[v]) {    // d[v]可能是INF也可能是之前记录过的最短距离
                    d[v] = d[u] + G[u][v];      // 更新s->v的最短距离
                    w[v] = w[u] + weight[v];    // 更新s->v的点权
                    num[v] = num[u];            // 出现新的最短距离, 那么u与v连通则s->u的最短路径个数就是s->v的最短路径个数
                } else if (d[u] + G[u][v] == d[v]) {
                    if (w[u] + weight[v] > w[v]) {
                        w[v] = w[u] + weight[v];    // 同时更新u->v, 在满足最短路径的情况下
                    }
                    num[v] += num[u];           // u与v连通,u->v的最短距离与之前记录过的相同, 则s->u的最短路径个数即为新增的u->v的最短路径个数
                }
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d", &n, &m, &start, &dest);
    for (int i = 0; i < n; i++){
        scanf("%d", &weight[i]);
    }
    int u, v;
    fill(G[0], G[0] + maxn * maxn, INF);
    for (int i = 0; i < m; i++){
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijkstra(start);
    printf("%d %d", num[dest], w[dest]);
    return 0;
}