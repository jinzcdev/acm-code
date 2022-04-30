// https://pintia.cn/problem-sets/994805342720868352/problems/994805514284679168
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, flag = 1;
    cin >> n;
    vector<int> a(n), dp(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] >= 0) flag = 0;
    }
    if (flag) {
        printf("0 %d %d", a[0], a[n - 1]);
        return 0;
    }
    dp[0] = a[0];
    s[0] = 0;
    for (int i = 1; i < n; i++) {
        if (dp[i - 1] + a[i] >= a[i]) {
            dp[i] = dp[i - 1] + a[i];
            s[i] = s[i - 1];
        } else {
            dp[i] = a[i];
            s[i] = i;
        }
    }
    int k = 0;
    for (int i = 1; i < n; i++) {
        if (dp[i] > dp[k]) k = i;
    }
    printf("%d %d %d", dp[k], a[s[k]], a[k]);
    return 0;
}