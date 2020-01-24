// https://pintia.cn/problem-sets/994805342720868352/problems/1038430130011897856
#include <bits/stdc++.h>
using namespace std;
vector<int> pre, in;
int n, m;
map<int, int> pos;
void lca(int inl, int inr, int root, int u, int v) {
    if (inl > inr) return;
    int posr = pos[pre[root]], posu = pos[u], posv = pos[v];
    if (posu < posr && posv < posr) {
        lca(inl, posr - 1, root + 1, u, v);
    } else if (posu > posr && posv > posr) {
        lca(posr + 1, inr, posr - inl + root + 1, u, v);
    } else if ((posu < posr && posv > posr) || (posu > posr && posv < posr)) {
        printf("LCA of %d and %d is %d.\n", u, v, pre[root]);
    } else if (posu == posr) {
        printf("%d is an ancestor of %d.\n", u, v);
    } else {
        printf("%d is an ancestor of %d.\n", v, u);
    }
}
int main() {
    cin >> m >> n;
    pre.resize(n + 1);
    in.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &in[i]);
        pos[in[i]] = i;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &pre[i]);
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        if (pos[u] == 0 && pos[v] == 0) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        } else if (pos[u] == 0 || pos[v] == 0) {
            printf("ERROR: %d is not found.\n", pos[u] == 0 ? u : v);
        } else {
            lca(1, n, 1, u, v);
        }
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
map<int, int> pos;
vector<int> in, pre;
int n, m, u, v;
void lca(int prel, int inl, int inr) {
    if (inl > inr) return;
    int pr = pos[pre[prel]], pu = pos[u], pv = pos[v];
    if (pu < pr && pv < pr) lca(prel + 1, inl, pr - 2);
    else if (pu > pr && pv > pr) lca(prel + pr - inl, pr, inr);
    else if ((pu < pr && pv > pr) || (pu > pr && pv < pr)) printf("LCA of %d and
%d is %d.\n", u, v, pre[prel]); else if (pu == pr) printf("%d is an ancestor of
%d.\n", u, v); else if (pv == pr) printf("%d is an ancestor of %d.\n", v, u);
}
int main() {
    scanf("%d%d", &m, &n);
    in.resize(n);
    pre.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
        pos[in[i]] = i + 1;
    }
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    while (m--) {
        scanf("%d%d", &u, &v);
        if (pos[u] == 0 && pos[v] == 0) printf("ERROR: %d and %d are not
found.\n", u, v); else if (pos[u] == 0 || pos[v] == 0) printf("ERROR: %d is not
found.\n", pos[u] == 0 ? u : v); else lca(0, 0, n - 1);
    }
    return 0;
}*/