// https://pintia.cn/problem-sets/16/problems/674
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int main() {
    int n, m, a, b, cnt = 0, ans = -1, ind[N] = {0}, w[N][N], dp[N] = {0};
    vector<int> e[N];
    queue<int> q;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        scanf("%d", &w[a][b]);
        e[a].push_back(b);
        ind[b]++;
    }
    for (int i = 0; i < n; i++)
        if (ind[i] == 0) q.push(i);
    while (!q.empty()) {
        cnt++;
        int u = q.front();
        q.pop();
        ans = max(ans, dp[u]);
        for (auto v : e[u]) {
            if (--ind[v] == 0) q.push(v);
            dp[v] = max(dp[v], dp[u] + w[u][v]);
        }
    }
    if (cnt != n) printf("Impossible");
    else printf("%d", ans);
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 110;
// vector<int> e[N];
// int n, m, a, b, w, weight[N][N] = {0}, indegree[N] = {0}, outdegree[N] = {0},
//                    ve[N] = {0}, vl[N] = {0};
// stack<int> topOrder;
// bool topsort() {
//     queue<int> q;
//     for (int i = 0; i < n; i++) {
//         if (indegree[i] == 0) e[n].push_back(i);
//         if (outdegree[i] == 0) e[i].push_back(n + 1);
//     }
//     q.push(n);
//     while (!q.empty()) {
//         int u = q.front();
//         q.pop();
//         cout << u << " ";
//         topOrder.push(u);
//         for (auto v : e[u]) {
//             if (--indegree[v] == 0) {
//                 q.push(v);
//             }
//             ve[v] = max(ve[u] + weight[u][v], ve[v]);
//         }
//     }
//     return topOrder.size() == n + 2;
// }
// int criticalPath() {
//     if (topsort() == false) return -1;
//     fill(vl, vl + N, ve[n - 1]);
//     while (!topOrder.empty()) {
//         int u = topOrder.top();
//         topOrder.pop();
//         for (auto v : e[u]) {
//             vl[u] = min(vl[u], vl[v] - weight[u][v]);
//         }
//     }
//     return ve[n - 1];
// }
// int main() {
//     scanf("%d%d", &n, &m);
//     while (m--) {
//         scanf("%d%d%d", &a, &b, &w);
//         e[a].push_back(b);
//         indegree[b]++;
//         outdegree[a]++;
//         weight[a][b] = w;
//     }
//     // int u = n, v = n + 1;
//     int ans = criticalPath();
//     if (ans == -1)
//         printf("Impossible");
//     else
//         printf("%d", ans);
//     return 0;
// }