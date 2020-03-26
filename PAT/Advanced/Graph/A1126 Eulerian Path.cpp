// https://pintia.cn/problem-sets/994805342720868352/problems/994805349851185152
#include <bits/stdc++.h>
using namespace std;
const int N = 510;
vector<int> e[N];
bool vis[N] = {false};
void dfs(int u) {
    vis[u] = true;
    for (auto it : e[u])
        if (!vis[it]) dfs(it);
}
int main() {
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    int cntOdd = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i != 1) printf(" ");
        printf("%d", e[i].size());
        cntOdd += e[i].size() % 2 != 0;
        if (!vis[i]) {
            dfs(i);
            cnt++;
        }
    }
    if (cnt != 1 || (cntOdd != 0 && cntOdd != 2)) printf("\nNon-Eulerian");
    else printf("\n%s\n", cntOdd == 0 ? "Eulerian" : "Semi-Eulerian");
    return 0;
}