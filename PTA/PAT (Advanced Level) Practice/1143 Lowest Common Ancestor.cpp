// https://pintia.cn/problem-sets/994805342720868352/problems/994805343727501312
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, a, b;
    scanf("%d%d", &m, &n);
    unordered_map<int, bool> exist;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        exist[v[i]] = true;
    }
    while (m--) {
        scanf("%d%d", &a, &b);
        if (!exist[a] && !exist[b])
            printf("ERROR: %d and %d are not found.\n", a, b);
        else if (!exist[a] || !exist[b])
            printf("ERROR: %d is not found.\n", exist[a] ? b : a);
        else {
            int ans = -1;
            for (int i = 0; i < n; i++) {
                if ((v[i] >= a && v[i] <= b) || (v[i] >= b && v[i] <= a)) {
                    ans = v[i];
                    break;
                }
            }
            if (ans != a && ans != b)
                printf("LCA of %d and %d is %d.\n", a, b, ans);
            else
                printf("%d is an ancestor of %d.\n", ans, ans == a ? b : a);
        }
    }
    return 0;
}

