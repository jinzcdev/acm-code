// 4
// 7 1001 3212 1003 1204 1005 1306 7797
// 9 9988 2333 1204 2006 2005 2004 2003 2302 2001
// 13 3011 3812 3013 3001 1306 3003 2333 3066 3212 3008 2302 3010 3011
// 4 6666 8432 4011 1306
// 3
// 3011 3013
// 6666 2001
// 2004 3001
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
vector<int> e[N];
bool vis[N] = {false};
vector<int> path, tempPath;
int st, dest;
void dfs(int u) {
    vis[u] = true;
    tempPath.push_back(u);
    if (u == dest) {
        for (auto it : tempPath) {
            printf("%04d ", it);
        }
        cout << endl;
        // vis[u] = false;
        // tempPath.pop_back();
        // return;
    }
    for (auto it : e[u]) {
        if (!vis[it]) dfs(it);
    }
    vis[u] = false;
    tempPath.pop_back();
}
int main() {
    int n, m, k, pre, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &m, &pre);
        for (int j = 0; j < m - 1; j++) {
            scanf("%d", &a);
            e[pre].push_back(a);
            e[a].push_back(pre);
            pre = a;
        }
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &st, &dest);
        dfs(st);
    }
    return 0;
}