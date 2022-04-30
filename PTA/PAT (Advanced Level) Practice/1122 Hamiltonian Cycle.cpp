// https://pintia.cn/problem-sets/994805342720868352/problems/994805351814119424
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k, a, b, hash[210][210] = {0};
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        hash[a][b] = hash[b][a] = 1;
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &k);
        vector<int> v(k);
        unordered_set<int> s;
        for (int i = 0; i < k; i++) {
            scanf("%d", &v[i]);
            s.insert(v[i]);
        }
        if (k != n + 1 || s.size() != n || v[0] != v[k - 1]) printf("NO\n");
        else {
            bool flag = true;
            for (int i = 0; flag && i < k - 1; i++) flag = hash[v[i]][v[i + 1]];
            printf("%s\n", flag ? "YES" : "NO");
        }
    }
    return 0;
}