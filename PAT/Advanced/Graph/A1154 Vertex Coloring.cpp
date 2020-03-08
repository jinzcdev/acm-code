// https://pintia.cn/problem-sets/994805342720868352/problems/1071785301894295552
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k, a, b;
    scanf("%d%d", &n, &m);
    vector<pair<int, int> > e;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        e.push_back({a, b});
    }
    scanf("%d", &k);
    while (k--) {
        vector<int> color(n);
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            scanf("%d", &color[i]);
            s.insert(color[i]);
        }
        bool isproper = true;
        for (auto it : e) {
            if (color[it.first] == color[it.second]) {
                isproper = false;
                break;
            }
        }
        if (isproper) printf("%d-coloring\n", s.size());
        else printf("No\n");
    }
    return 0;
}