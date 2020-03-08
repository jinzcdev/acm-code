// https://pintia.cn/problem-sets/994805342720868352/problems/994805375457411072
#include <bits/stdc++.h>
using namespace std;
struct node {
    int x, y, z;
};
int n, m, l, t, e[65][1300][130];
int X[] = {0, 0, 1, -1, 0, 0}, Y[] = {0, 0, 0, 0, 1, -1},
    Z[] = {1, -1, 0, 0, 0, 0};
bool inq[65][1300][130] = {false};
bool isVisitable(int x, int y, int z) {
    return !(x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l) &&
           e[z][x][y] != 0 && !inq[z][x][y];
}
int bfs(node a) {
    queue<node> q;
    q.push(a);
    inq[a.z][a.x][a.y] = true;
    int sum = 0;
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        int x = now.x, y = now.y, z = now.z;
        sum += e[z][x][y];
        for (int i = 0; i < 6; i++) {
            x = now.x + X[i];
            y = now.y + Y[i];
            z = now.z + Z[i];
            if (isVisitable(x, y, z)) {
                inq[z][x][y] = true;
                q.push({x, y, z});
            }
        }
    }
    return sum >= t ? sum : 0;
}
int main() {
    scanf("%d%d%d%d", &m, &n, &l, &t);
    for (int k = 0; k < l; k++)
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) scanf("%d", &e[k][i][j]);
    int ans = 0;
    for (int k = 0; k < l; k++)
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (isVisitable(i, j, k)) ans += bfs({i, j, k});
    printf("%d", ans);
    return 0;
}