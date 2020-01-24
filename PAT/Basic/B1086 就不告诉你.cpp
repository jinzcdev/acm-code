// https://pintia.cn/problem-sets/994805260223102976/problems/1038429065476579328
#include <bits/stdc++.h>
using namespace std;
void solve(int x) {
    if (x == 0) return;
    printf("%d", x % 10);
    return solve(x / 10);
}
int main() {
    int a, b;
    cin >> a >> b;
    int ans = a * b;
    if (ans == 0) {
        cout << "0";
        return 0;
    }
    while (ans % 10 == 0) ans /= 10;
    solve(ans);
    return 0;
}
/*
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
*/
/*
注意:
100 100
1
应该去掉前面的 0
*/