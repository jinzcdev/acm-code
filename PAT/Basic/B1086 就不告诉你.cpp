// https://pintia.cn/problem-sets/994805260223102976/problems/1038429065476579328
#include <cstdio>
const int maxn = 1000000;
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int rs = a * b;
    if (rs == 0) {
        printf("0");
        return 0;
    }
    int ans[maxn], len = 0;
    while (rs != 0) {
        ans[len++] = rs % 10;
        rs = rs / 10;
    }
    int pos = 0;
    while (ans[pos] == 0) pos++;
    while (pos < len) printf("%d", ans[pos++]);
    return 0;
}

/*
注意:
100 100
1
应该去掉前面的 0
*/