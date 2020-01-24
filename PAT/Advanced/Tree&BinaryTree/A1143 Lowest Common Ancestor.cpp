// https://pintia.cn/problem-sets/994805342720868352/problems/994805343727501312
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, u, v;
    cin >> m >> n;
    vector<int> pre(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
        mp[pre[i]] = 1;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        if (mp[u] == 0 && mp[v] == 0) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        } else if (mp[u] == 0 || mp[v] == 0) {
            printf("ERROR: %d is not found.\n", mp[u] == 0 ? u : v);
        } else {
            int ans;
            for (int j = 0; j < n; j++) {
                ans = pre[j];
                if ((u <= pre[j] && v >= pre[j]) ||
                    (u >= pre[j] && v <= pre[j])) {
                    break;
                }
            }
            if (u == ans || v == ans) printf("%d is an ancestor of %d.\n", ans, ans == u ? v : u);
            else printf("LCA of %d and %d is %d.\n", u, v, ans);
        }
    }
    return 0;
}