// https://pintia.cn/problem-sets/994805342720868352/problems/1038430013544464384
#include <bits/stdc++.h>
using namespace std;
const int N = 210, INF = 0x3f3f3f3f;
int main() {
    int e[N][N], n, m, k, a, b, temp;
    scanf("%d%d", &n, &m);
    fill(e[0], e[0] + N * N, INF);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &temp);
        e[a][b] = e[b][a] = temp;
    }
    scanf("%d", &k);
    int ans, mindist = INF;
    for (int i = 1; i <= k; i++) {
        printf("Path %d: ", i);
        scanf("%d", &m);
        vector<int> v(m);
        for (int j = 0; j < m; j++) scanf("%d", &v[j]);
        unordered_set<int> s;
        int totalDist = 0, flag = 1;
        for (int j = 0; j < m - 1; j++) {
            if (e[v[j]][v[j + 1]] == INF) {
                flag = 0;
                break;
            }
            s.insert(v[j]);
            totalDist += e[v[j]][v[j + 1]];
        }
        if (!flag) printf("NA (Not a TS cycle)\n");
        else {
            printf("%d ", totalDist);
            if (v[0] != v[m - 1] || s.size() < n) printf("(Not a TS cycle)\n");
            else {
                printf("(%s)\n", m - 1 == n ? "TS simple cycle" : "TS cycle");
                if (totalDist < mindist) {
                    mindist = totalDist;
                    ans = i;
                }
            }
        }
    }
    printf("Shortest Dist(%d) = %d", ans, mindist);
    return 0;
}