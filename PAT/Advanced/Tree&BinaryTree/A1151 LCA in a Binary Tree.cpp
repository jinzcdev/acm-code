// https://pintia.cn/problem-sets/994805342720868352/problems/1038430130011897856
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
    else if ((pu < pr && pv > pr) || (pu > pr && pv < pr)) printf("LCA of %d and %d is %d.\n", u, v, pre[prel]);
    else if (pu == pr) printf("%d is an ancestor of %d.\n", u, v);
    else if (pv == pr) printf("%d is an ancestor of %d.\n", v, u);
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
        if (pos[u] == 0 && pos[v] == 0) printf("ERROR: %d and %d are not found.\n", u, v);
        else if (pos[u] == 0 || pos[v] == 0) printf("ERROR: %d is not found.\n", pos[u] == 0 ? u : v);
        else lca(0, 0, n - 1);
    }
    return 0;
}