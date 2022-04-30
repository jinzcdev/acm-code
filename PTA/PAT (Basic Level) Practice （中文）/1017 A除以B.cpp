// https://pintia.cn/problem-sets/994805260223102976/problems/994805305181847552
#include <bits/stdc++.h>
using namespace std;
int main() {
    char a[1010];
    int n, len = 0, carry = 0, ans[1010];
    scanf("%s%d", a, &n);
    for (int i = 0; i < strlen(a); i++) {
        int temp = carry * 10 + a[i] - '0';
        ans[len++] = temp / n;
        carry = temp % n;
    }
    int i = 0;
    while (len > 1 && ans[i] == 0) i++;
    for (; i < len; i++) printf("%d", ans[i]);
    printf(" %d", carry);
    return 0;
}