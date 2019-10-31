#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100;       // 顶点数编号0-99(算法题通常1为第一个顶点, 0为默认的起点)
vector<int> G[maxn];        // 邻接表表示图结构
bool vis[maxn];             // 标记是否访问过

int cnt = 0;                    // 计数
vector<int> path;               // 记录路径
void DFS(int u, int v) {
    vis[u] = true;
    path.push_back(u);
    if (u == v) {
        printf("Path %d: ", ++cnt);
        for (int i = 0; i < path.size(); i++) {
            if (i != 0) printf("->");
            printf("%d", path[i]);
        }
        cout << endl;
        path.pop_back();        // 回到上一层前将当前结点弹出
        vis[v] = false;
        return;
    }
    for (int i = 0; i < G[u].size(); i++) {
        if (!vis[G[u][i]]) {
            DFS(G[u][i], v);
            vis[G[u][i]] = false;   // 获取全部路径, 需要在该点被标记过后重新使其可访问
        }
    }
    path.pop_back();        // 对当前结点DFS之后从路径中弹出
}

int main() {
    int n, vt, k, ad, u, v;
    cin >> n >> u >> v;
    for (int i = 0; i < n; i++) {
        cin >> vt >> k;
        while (k--) {
            cin >> ad;
            G[vt].push_back(ad);
        }
    }
    DFS(u, v);
    return 0;
}

/*
Format:
顶点数 起点 终点
顶点编号 邻接点数 [邻接点..]
...
...

输入样例:
6 1 3
1 3 2 4 5
2 3 1 3 4 
3 2 2 4
4 4 1 2 3 6
5 2 1 6
6 2 4 5
输出样例:
Path 1: 1->2->3
Path 2: 1->2->4->3
Path 3: 1->4->2->3
Path 4: 1->4->3
Path 5: 1->5->6->4->2->3
Path 6: 1->5->6->4->3
*/