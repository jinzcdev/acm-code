// https://pintia.cn/problem-sets/994805046380707840/problems/994805056195379200
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k, np, a, b;
    scanf("%d%d", &n, &m);
    vector<vector<int> > e(n + 1);
    vector<int> num(n + 1, 0);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        num[a]++;
        num[b]++;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &k);
        vector<int> tnum(num);
        while (k--) {
            scanf("%d", &a);
            tnum[a] = 0;
            for (auto it : e[a]) tnum[it]--;
        }
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (tnum[i] > 0) {
                flag = false;
                break;
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}