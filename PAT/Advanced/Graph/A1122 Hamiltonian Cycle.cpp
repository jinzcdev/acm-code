// https://pintia.cn/problem-sets/994805342720868352/problems/994805351814119424
#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int main() {
    int n, m, k, a, b, e[N][N] = {0};
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        e[a][b] = e[b][a] = 1;
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &m);
        vector<int> v(m);
        for (int i = 0; i < m; i++) scanf("%d", &v[i]);
        if (m != n + 1 || v[0] != v[m - 1]) {
            printf("NO\n");
            continue;
        }
        bool vis[N] = {false}, flag = true;
        for (int i = 0; i < m - 1; i++) {
            if (vis[v[i]] == true || e[v[i]][v[i + 1]] == 0) {
                flag = false;
                break;
            }
            vis[v[i]] = true;
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}