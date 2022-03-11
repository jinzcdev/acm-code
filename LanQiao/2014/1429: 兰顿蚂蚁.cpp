// https://www.dotcpp.com/oj/problem1429.html
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int X[] = {-1, 0, 1, 0}, Y[] = {0, 1, 0, -1};
int main() {
    int m, n, x, y, k, d = 0, a[N][N] = {0};
    char ch, str[] = "URDL";
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
    scanf("%d%d %c %d", &x, &y, &ch, &k);
    while (str[d] != ch) d++;
    while (k--) {
        if (!a[x][y]) d = (d - 1 + 4) % 4;
        else d = (d + 1 + 4) % 4;
        a[x][y] = !a[x][y];
        x += X[d];
        y += Y[d];
    }
    printf("%d %d", x, y);
    return 0;
}