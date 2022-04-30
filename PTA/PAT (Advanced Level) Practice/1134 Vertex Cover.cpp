// https://pintia.cn/problem-sets/994805342720868352/problems/994805346428633088
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int main() {
    int n, m, k, a, b;
    scanf("%d%d", &n, &m);
    vector<pair<int, int> > e;
    while (m--) {
        scanf("%d%d", &a, &b);
        e.push_back({a, b});
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &k);
        bool hash[N] = {false}, flag = true;
        while (k--) {
            scanf("%d", &a);
            hash[a] = true;
        }
        for (auto it : e) {
            if (!hash[it.first] && !hash[it.second]) {
                flag = false;
            }
        }
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int main() {
    int n, m, k, t, u, v;
    scanf("%d%d", &n, &m);
    vector<vector<int> > e(n);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        e[u].push_back(i);
        e[v].push_back(i);
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &t);
        set<int> s;
        for (int i = 0; i < t; i++) {
            scanf("%d", &u);
            for (auto it : e[u]) s.insert(it);
        }
        printf("%s\n", s.size() == m ? "Yes" : "No");
    }
    return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
    int g[N][N] = {0};
int main() {
    int n, m, a, b, k, pos = 1;
    cin >> n >> m;
    vector<int> e[N];
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        g[a][b] = g[b][a] = pos++;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    cin >> k;
    int nv;
    while (k--) {
        scanf("%d", &nv);
        vector<int> v(nv);
        for (int i = 0; i < nv; i++) {
            scanf("%d", &v[i]);
        }
        bool vis[10010] = {false};
        int cnt = 0;
        for (int j = 0; j < nv; j++) {
            for (auto it : e[v[j]]) {
                if (!vis[g[v[j]][it]]) {
                    vis[g[v[j]][it]] = true;
                    cnt++;
                }
            }
        }
        printf("%s\n", cnt == m ? "Yes" : "No");
    }
    return 0;
}*/
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int edge[N][N] = {0};
int main() {
    int n, m, k, t, b, v1, v2, id = 1;
    scanf("%d%d", &n, &m);
    vector<int> g[n];
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &v1, &v2);
        edge[v1][v2] = edge[v2][v1] = id++;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &t);
        bool vis[N] = {false};
        int cnt = 0;
        for (int i = 0; i < t; i++) {
            scanf("%d", &b);
            for (int j = 0; j < g[b].size(); j++) {
                if (!vis[edge[b][g[b][j]]]) {
                    cnt++;
                    vis[edge[b][g[b][j]]] = true;
                }
            }
        }
        if (cnt == m) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}*/