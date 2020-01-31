#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100;
const int maxv = 1000;
int main() {
    int n, v;
    scanf("%d%d", &n, &v);
    vector<int> w(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    int dp[maxn][maxv] = {0};
    for (int i = 0; i <= v; i++) dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= w[i]; j--) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + c[i]);
        }
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i][v]);
    }
    cout << ans;
    return 0;
}