#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
const int maxv = 1000;
int main() {
    int n, v, w[maxn], c[maxn];
    cin >> n >> v;
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    int dp[maxv];
    for (int i = 0; i <= v; i++) dp[i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= v; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}