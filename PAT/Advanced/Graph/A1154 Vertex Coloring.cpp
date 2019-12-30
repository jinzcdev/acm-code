// https://pintia.cn/problem-sets/994805342720868352/problems/1071785301894295552
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
vector<int> g[N];
bool vis[N] = {false}, flag;
int color[N];
void dfs(int u) {
    vis[u] = true;
    for (int i = 0; i < g[u].size(); i++) {
        if (!vis[g[u][i]]) {
            if (color[u] == color[g[u][i]]) flag = false;
            dfs(g[u][i]);
        }
    }
}
int main() {
    int n, m, u, v, k, c;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    scanf("%d", &k);
    while (k--) {
        // bool ht[99999] = {false};
        map<int, int> mp;
        fill(vis, vis + n, false);
        int cnt = 0;
        flag = true;
        for (int i = 0; i < n; i++) {
            scanf("%d", &color[i]);
            // if (!ht[color[i]]) {
            //     cnt++;
            //     ht[color[i]] = true;
            // }
            mp[color[i]] = 1;
        }
        dfs(u);
        cnt = mp.size();
        if (flag)
            printf("%d-coloring\n", cnt);
        else
            printf("No\n");
    }
    return 0;
}