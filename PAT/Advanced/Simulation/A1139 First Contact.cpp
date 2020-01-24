// https://pintia.cn/problem-sets/994805342720868352/problems/994805344776077312
#include <bits/stdc++.h>
using namespace std;
vector<int> f[10000];
struct node {
    int a, b;
};
bool cmp(node a, node b) { return a.a != b.a ? a.a < b.a : a.b < b.b; }
int main() {
    int n, m, k, a, b;
    map<int, int> gender;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        string sa, sb;
        cin >> sa >> sb;
        a = abs(stoi(sa));
        b = abs(stoi(sb));
        if (sa[0] == '-') gender[a] = 1;
        if (sb[0] == '-') gender[b] = 1;
        f[a].push_back(b);
        f[b].push_back(a);
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &a, &b);
        a = abs(a);
        b = abs(b);
        vector<node> ans;
        for (auto c : f[a]) {
            if (c == b) continue;
            for (auto d : f[b]) {
                if (d == a) continue;
                if (find(f[c].begin(), f[c].end(), d) != f[c].end()) {
                    if (gender[a] == gender[c] && gender[b] == gender[d]) {
                        ans.push_back({c, d});
                    }
                }
            }
        }
        printf("%d\n", ans.size());
        sort(ans.begin(), ans.end(), cmp);
        for (auto it : ans) {
            printf("%04d %04d\n", it.a, it.b);
        }
    }
    return 0;
}