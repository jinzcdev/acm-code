// https://pintia.cn/problem-sets/1203317812083417088/problems/1203317880077287425
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, ans = -1;
    vector<vector<int> > v(10010);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        v[i].resize(10010);
        int Max = -1;
        for (int j = 0; j < m; j++) {
            scanf("%d", &v[i][j]);
            if (v[i][j] > Max) Max = v[i][j];
        }
        if (Max > ans) ans = Max;
        printf("%d", Max);
        if (i != n - 1) printf(" ");
    }
    printf("\n%d", ans);
    return 0;
}