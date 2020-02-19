/**
 * 小米之家是成人糖果店。里面有很多便宜，好用，好玩的产品。中秋节快到了，小米之家想给米粉们准备
 * 一些固定金额大礼包。对于给定的一个金额，需要判断能不能用不同种产品（一种产品在礼包最多出现一次）
 * 组合出来这个金额。聪明的你来帮帮米家的小伙伴吧。
 */
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) { return a > b; }
int main() {
    int n, m, w[210];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    sort(w + 1, w + 1 + n, cmp);
    scanf("%d", &m);
    vector<int> dp(m + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
    printf("%d", dp[m]);
    return 0;
}