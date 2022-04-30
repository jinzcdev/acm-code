// https://pintia.cn/problem-sets/994805342720868352/problems/994805396953219072
#include <bits/stdc++.h>
using namespace std;
const int N = 1030, INF = 0x3f3f3f3f;
int e[N][N], d[N], n, m, k, range;
vector<int> ans;
double minAvg = INF, minDist = -1;
int minIndex = N;
void dijkstra(int u) {
    fill(d, d + N, INF);
    d[u] = 0;
    bool vis[N] = {false};
    for (int i = 0; i < n + m; i++) {
        int u = -1, MIN = INF;
        for (int j = 1; j <= n + m; j++) {
            if (!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1 || (u <= n && d[u] > range)) return;
        vis[u] = true;
        for (int v = 1; v <= n + m; v++) {
            if (!vis[v] && e[u][v] != INF && d[u] + e[u][v] < d[v]) {
                d[v] = d[u] + e[u][v];
            }
        }
    }
    double sum = 0.0, tempMinDist = INF;
    for (int i = 1; i <= n; i++) {
        if (d[i] < tempMinDist) tempMinDist = d[i];
        sum += d[i];
    }
    double tempAvg = (int)(10.0 * (sum / n) + 0.5) / 10.0;
    if (tempMinDist > minDist) {
        minIndex = u;
        minAvg = tempAvg;
        minDist = tempMinDist;
    } else if (tempMinDist == minDist && tempAvg < minAvg) {
        minIndex = u;
        minAvg = tempAvg;
    }
}
int getId(string s) { return s[0] != 'G' ? stoi(s) : n + stoi(s.substr(1)); }
int main() {
    int a, b, dist;
    string s1, s2;
    fill(e[0], e[0] + N * N, INF);
    scanf("%d%d%d%d", &n, &m, &k, &range);
    for (int i = 0; i < k; i++) {
        cin >> s1 >> s2 >> dist;
        a = getId(s1);
        b = getId(s2);
        e[a][b] = e[b][a] = dist;
    }
    for (int i = n + 1; i <= n + m; i++) dijkstra(i);
    if (minIndex == N) printf("No Solution\n");
    else printf("G%d\n%.1f %.1f", minIndex - n, minDist, minAvg);
    return 0;
}

/*
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1020;
const int INF = 0x7FFFFFFF;

int n, m, k, DS;
int G[maxn][maxn];
int d[maxn];
bool vis[maxn] = {false};

int getID(char *str){
    int i = 0, id = 0, len = strlen(str);
    while (i < len) {
        if (str[i] != 'G') {
            id = id * 10 + (str[i] - '0');
        }
        i++;
    }
    if (str[0] != 'G') return id;
    else return id + n;
}

void Dijkstra(int s) {
    fill(d, d + maxn, INF);
    memset(vis, false, sizeof(vis));
    d[s] = 0;
    for (int i = 0; i < n + m; i++){
        int u = -1, MIN = INF;
        for (int j = 1; j <= n + m; j++){
            if (!vis[j] && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 1; v <= n + m; v++){
            if (!vis[v] && G[u][v] < INF && d[u] + G[u][v] < d[v]) {
                d[v] = d[u] + G[u][v];
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d", &n, &m, &k, &DS);
    char city1[5], city2[5];
    fill(G[0], G[0] + maxn * maxn, INF);
    int u, v, w;
    for (int i = 0; i < k; i++){
        scanf("%s %s %d", city1, city2, &w);
        u = getID(city1);
        v = getID(city2);
        G[v][u] = G[u][v] = w;
    }

    int ansID = -1;
    double ansDis = -1, ansAvg = INF;
    for (int i = n + 1; i <= n + m; i++) {
        double minDis = INF, avg = 0;
        Dijkstra(i);
        for (int city = 1; city <= n; city++){
            if (d[city] > DS) {
                minDis = -1;
                break;
            } else {
                if (d[city] < minDis) minDis = d[city];
                avg += 1.0 * d[city] / n;
            }
        }
        if (minDis == -1) continue;
        if (minDis > ansDis) {
            ansID = i - n;
            ansDis = minDis;
            ansAvg = avg;
        } else if (minDis == ansDis && avg < ansAvg) {
            ansID = i - n;
            ansAvg = avg;
        }
    }
    if (ansID == -1) printf("No Solution\n");
    else printf("G%d\n%.1f %.1f", ansID, ansDis, ansAvg);
    return 0;
}
*/