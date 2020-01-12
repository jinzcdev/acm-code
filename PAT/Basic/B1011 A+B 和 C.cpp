// https://pintia.cn/problem-sets/994805260223102976/problems/994805312417021952
#include <stdio.h>
int main() {
    int tcase = 1, n;
    scanf("%d", &n);
    while (n--) {
        double a, b, c;
        scanf("%lf%lf%lf", &a, &b, &c);
        if (a + b > c) printf("Case #%d: true\n", tcase++);
        else printf("Case #%d: false\n", tcase++);
    }
    return 0;
}