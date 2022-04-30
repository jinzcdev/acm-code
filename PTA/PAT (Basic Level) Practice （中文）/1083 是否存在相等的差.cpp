// https://pintia.cn/problem-sets/994805260223102976/problems/994805260780945408
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, temp, d[10010] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        d[abs(temp - i)]++;
    }
    for (int i = n; i >= 0; i--)
        if (d[i] > 1) printf("%d %d\n", i, d[i]);
    return 0;
}