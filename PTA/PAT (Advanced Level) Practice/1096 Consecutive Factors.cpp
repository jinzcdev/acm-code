// https://pintia.cn/problem-sets/994805342720868352/problems/994805370650738688
#include <bits/stdc++.h>
int main() {
    int n, begin, len = 0;
    scanf("%d", &n);
    int sqr = (int)sqrt(n);
    for (int i = 2; i <= sqr; i++) {
        int j = i, temp = n;
        for (; j <= sqr; j++) {
            if (temp % j != 0) break;
            temp /= j;
        }
        if (j - i > len) {
            len = j - i;
            begin = i;
        }
    }
    if (len == 0) {
        printf("1\n%d", n);
        return 0;
    }
    printf("%d\n", len);
    for (int i = 0; i < len; i++) {
        if (i != 0) printf("*");
        printf("%d", begin + i);
    }
    return 0;
}