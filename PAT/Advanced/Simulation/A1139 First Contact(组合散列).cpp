// https://pintia.cn/problem-sets/994805342720868352/problems/994805344776077312
#include <bits/stdc++.h>
using namespace std;
struct node {
    int a, b;
};
bool cmp(node a, node b) { return a.a != b.a ? a.a < b.a : a.b < b.b; }
int main() {
    int n, m, k;
    string a, b;
    vector<int> f[10000];
    map<int, bool> isfriend;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        int ia = abs(stoi(a)), ib = abs(stoi(b));
        if (a.length() == b.length()) {
            f[ia].push_back(ib);
            f[ib].push_back(ia);
        }
        isfriend[ia * 10000 + ib] = isfriend[ib * 10000 + ia] = true;
    }
    scanf("%d", &k);
    while (k--) {
        int ta, tb;
        scanf("%d%d", &ta, &tb);
        ta = abs(ta);
        tb = abs(tb);
        vector<node> ans;
        for (auto c : f[ta]) {
            if (c == tb) continue;
            for (auto d : f[tb]) {
                if (d == ta) continue;
                if (isfriend[c * 10000 + d]) {
                    ans.push_back({c, d});
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