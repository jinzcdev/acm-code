// https://pintia.cn/problem-sets/994805342720868352/problems/994805343043829760
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    vector<vector<int> > e(n + 1);
    vector<int> in(n + 1, 0);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        in[v]++;
    }
    int k;
    scanf("%d", &k);
    vector<int> ans, top(n);
    for (int i = 0; i < k; i++) {
        bool flag = true;
        vector<int> tin(in);
        for (int j = 0; j < n; j++) scanf("%d", &top[j]);
        for (int j = 0; j < n; j++) {
            if (tin[top[j]] != 0) {
                flag = false;
                break;
            }
            for (auto it : e[top[j]]) tin[it]--;
        }
        if (!flag) ans.push_back(i);
    }
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}