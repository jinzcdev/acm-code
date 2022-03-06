/**
 * dp[i][j]: 前i个砝码能否称出重量j
 * dp问题关键在于: 1.初始化 2.状态转移函数
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 110, MAX_W = 100010;
int main() {
    int n, sum = 0, ans = 0, dp[N][MAX_W] = {0}, w[N] = {0};
    dp[0][0] = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
        dp[1][w[i]] = 1;
        sum += w[i];
    }

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= sum; j++)
            dp[i][j] = max(dp[i - 1][j], 
                            max(dp[i - 1][j + w[i]], dp[i - 1][abs(j - w[i])]));

    for (int j = 1; j <= sum; j++) ans += dp[n][j];
    printf("%d", ans);
    return 0;
}