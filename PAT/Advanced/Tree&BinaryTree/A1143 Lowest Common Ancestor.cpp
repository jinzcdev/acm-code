// https://pintia.cn/problem-sets/994805342720868352/problems/994805343727501312
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    vector<int> pre(m);
    unordered_map<int, bool> exist;
    for (int i = 0; i < m; i++) {
        scanf("%d", &pre[i]);
        exist[pre[i]] = true;
    }
    while (n--) {
        scanf("%d%d", &a, &b);
        if (!exist[a] && !exist[b]) printf("ERROR: %d and %d are not found.\n", a, b);
        else if (!exist[a] || !exist[b]) printf("ERROR: %d is not found.\n", !exist[a] ? a : b);
        else {
            int ans = -1;
            for (int i = 0; i < m; i++) {
                ans = pre[i];
                if ((ans >= a && ans <= b) || (ans >= b && ans <= a)) break;
            }
            if (a == ans || b == ans) printf("%d is an ancestor of %d.\n", ans, a == ans ? b : a);
            else printf("LCA of %d and %d is %d.\n", a, b, ans);
        }
    }
    return 0;
}