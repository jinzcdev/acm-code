// https://pintia.cn/problem-sets/15/problems/718
#include <bits/stdc++.h>
using namespace std;
const int N = 1010, INF = 0x3f3f3f3f;
struct edge {
    int u, v, cost;
} e[N * 3];
int n, m, father[N];
bool cmp(edge a, edge b) { return a.cost < b.cost; }
int findFather(int x) {
    return x == father[x] ? x : father[x] = findFather(father[x]);
}
int kruskal() {
    for (int i = 1; i <= n; i++) father[i] = i;
    sort(e, e + m, cmp);
    int ans = 0, cntEdge = 0;
    for (int i = 0; i < m; i++) {
        int faA = findFather(e[i].u), faB = findFather(e[i].v);
        if (faA != faB) {
            father[faA] = faB;
            ans += e[i].cost;
            if (++cntEdge == n - 1) break;
        }
    }
    return cntEdge != n - 1 ? -1 : ans;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].cost);
    printf("%d\n", kruskal());
    return 0;
}