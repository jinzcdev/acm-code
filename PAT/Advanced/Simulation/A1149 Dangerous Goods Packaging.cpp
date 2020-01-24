// https://pintia.cn/problem-sets/994805342720868352/problems/1038429908921778176
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, a, b;
    cin >> n >> m;
    map<int, vector<int> > mp;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &n);
        bool vis[100000] = {false}, flag = true;
        vector<int> v(n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &v[j]);
            if (mp[v[j]].size() != 0) {
                for (auto it : mp[v[j]]) {
                    vis[it] = true;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            if (vis[v[j]]) {
                flag = false;
                break;
            }
        }
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}