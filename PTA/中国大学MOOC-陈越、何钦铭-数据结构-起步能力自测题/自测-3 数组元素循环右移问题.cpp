// https://pintia.cn/problem-sets/17/problems/262
#include <stdio.h>
int main() {
    int n, m, a[110];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    m = m % n;
    int pos = n - m, cnt = 0;
    while (cnt < n) {
        if (pos == n) pos = 0;
        printf("%d", a[pos++]);
        if (++cnt < n) printf(" ");
    }
    return 0;
}