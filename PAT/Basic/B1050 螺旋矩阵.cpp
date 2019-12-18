// https://pintia.cn/problem-sets/994805260223102976/problems/994805275146436608
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
bool cmp(int a, int b) { return a > b; }
int main() {
    int N, m, n, matrix[10000][100];
    scanf("%d", &N);
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
    for (n = sqrt(N); n >= 1; n--) {
        if (N % n == 0) {
            m = N / n;
            break;
        }
    }
    sort(v.begin(), v.end(), cmp);
    int border[4] = {n - 1, m - 1, 0, 1};  // 分别表示右下左上4个方向的边界
    int x = 0, y = -1, d = 0;  // 初始方向向右, 需把y置为-1, d表示方向
    for (int i = 0; i < N; i++) {
        if (d == 0 && ++y == border[0]) {   // 方向向右, 且当前已走至右侧边界则方向改为向下, 右边界减1, 下同
            d = 1;
            border[0]--;
        } else if (d == 1 && ++x == border[1]) {
            d = 2;
            border[1]--;
        } else if (d == 2 && --y == border[2]) {
            d = 3;
            border[2]++;
        } else if (d == 3 && --x == border[3]) {
            d = 0;
            border[3]++;
        }
        matrix[x][y] = v[i];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j != 0) printf(" ");
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}