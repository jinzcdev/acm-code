// https://pintia.cn/problem-sets/994805342720868352/problems/1038430013544464384
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
int n, m, k;
int e[210][210];
int main() {
    fill(e[0], e[0] + 210 * 210, INF);
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        scanf("%d", &e[u][v]);
        e[v][u] = e[u][v];
    }
    scanf("%d", &k);
    int pnum, minDist = 0x3fffffff;
    for (int i = 1; i <= k; i++) {
        printf("Path %d: ", i);
        scanf("%d", &m);
        vector<int> path(m);
        set<int> s;     // 用集合记录不重复的顶点数
        for (int j = 0; j < m; j++) {
            scanf("%d", &path[j]);
            s.insert(path[j]);
        }
        int sumdist = 0;
        bool flag = true;
        for (int j = 0; j < m - 1; j++) {
            if (e[path[j]][path[j + 1]] == INF) {
                printf("NA (Not a TS cycle)\n");
                flag = false;
                break;
            }
            sumdist += e[path[j]][path[j + 1]];
        }
        if (!flag) continue;
        if (path[0] != path[m - 1] || s.size() < n) {
            printf("%d (Not a TS cycle)\n", sumdist);
        } else {
            if (sumdist < minDist) {
                minDist = sumdist;
                pnum = i;
            }
            if (m - 1 == n && s.size() == n) printf("%d (TS simple cycle)\n", sumdist);
            else printf("%d (TS cycle)\n", sumdist);
        }
    }
    printf("Shortest Dist(%d) = %d\n", pnum, minDist);
    return 0;
}

/*
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
const int maxn = 210;
const int INF = 0x7777777F;
int G[maxn][maxn], d[maxn];

int main() {
    int n, m, k;
    scanf("%d%d", &n, &m);
    fill(G[0], G[0] + maxn * maxn, INF);
    int city1, city2;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &city1, &city2);
        scanf("%d", &G[city1][city2]);
        G[city2][city1] = G[city1][city2];
    }
    scanf("%d", &k);
    int path[maxn], ansPath, ansDist = INF;
    for (int i = 1; i <= k; i++) {
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", path + i);
        }
        int start = path[0], ans = 0, numCycle = 0;
        bool isNotCycle = false;
        set<int> visCity;
        G[start][start] = 0;
        for (int j = 0; j < m; j++) {
            if (j != 0 && path[j] == path[0]) {
                numCycle++;
            }
            if (G[start][path[j]] != INF) {
                ans += G[start][path[j]];
                start = path[j];
            } else {
                isNotCycle = true;
            }
            visCity.insert(path[j]);
        }
        if (visCity.size() != n) {
            printf("Path %d: %d (Not a TS cycle)\n", i, ans);
        } else if (isNotCycle) {
            printf("Path %d: NA (Not a TS cycle)\n", i);
        } else {
            if (numCycle == 0) {
                printf("Path %d: %d (Not a TS cycle)\n", i, ans);
            } else {
                if (numCycle == 1) {
                    printf("Path %d: %d (TS simple cycle)\n", i, ans);
                } else {
                    printf("Path %d: %d (TS cycle)\n", i, ans);
                }
                if (ans < ansDist) {
                    ansPath = i;
                    ansDist = ans;
                }
            }
        }
    }
    printf("Shortest Dist(%d) = %d\n", ansPath, ansDist);
    return 0;
}
*/