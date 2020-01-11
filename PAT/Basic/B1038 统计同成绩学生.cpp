// https://pintia.cn/problem-sets/994805260223102976/problems/994805284092887040
#include <cstdio>
int main() {
    int a[110] = {0}, n, score;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &score);
        a[score]++;
    }
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &score);
        printf("%d", a[score]);
        if (n > 0) printf(" ");
    }
    return 0;
}