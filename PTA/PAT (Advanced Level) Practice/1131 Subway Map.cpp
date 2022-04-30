// https://pintia.cn/problem-sets/994805342720868352/problems/994805347523346432
#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
int n, m, k, st, dest, minCntStop, minCntTransfer;
bool vis[N];
unordered_map<int, int> line;
vector<int> e[N], path, tempPath;
int getTransferCount(vector<int> &v) {
    int preline = line[v[0] * 10000 + v[1]], cnt = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        int nowline = line[v[i] * 10000 + v[i + 1]];
        if (nowline != preline) {
            preline = nowline;
            cnt++;
        }
    }
    return cnt;
}
void dfs(int u, int cntStop) {
    vis[u] = true;
    tempPath.push_back(u);
    if (u == dest) {
        int cntTransfer = getTransferCount(tempPath);
        if (cntStop < minCntStop || cntTransfer < minCntTransfer) {
            minCntTransfer = cntTransfer;
            minCntStop = cntStop;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    for (auto next : e[u]) {
        if (!vis[next] && cntStop + 1 <= minCntStop) {
            dfs(next, cntStop + 1);
            vis[next] = false;
        }
    }
    tempPath.pop_back();
}
int main() {
    int preStop, stop;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &m, &preStop);
        for (int j = 0; j < m - 1; j++) {
            scanf("%d", &stop);
            e[preStop].push_back(stop);
            e[stop].push_back(preStop);
            line[preStop * 10000 + stop] = line[stop * 10000 + preStop] = i;
            preStop = stop;
        }
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &st, &dest);
        tempPath.clear();
        path.clear();
        minCntStop = minCntTransfer = 0x3f3f3f3f;
        fill(vis, vis + N, false);
        dfs(st, 0);
        printf("%d\n", path.size() - 1);
        int preline = line[path[0] * 10000 + path[1]], preStop = path[0];
        for (int i = 1; i < path.size() - 1; i++) {
            int nowline = line[path[i] * 10000 + path[i + 1]];
            if (nowline != preline) {
                printf("Take Line#%d from %04d to %04d.\n", preline, preStop, path[i]);
                preline = nowline;
                preStop = path[i];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preline, preStop, dest);
    }
    return 0;
}