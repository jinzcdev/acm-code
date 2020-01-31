#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
const int maxv = 110;
bool cmp(int a, int b) { return a > b; }
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    sort(w.begin() + 1, w.end(), cmp);
    int dp[maxn] = {0};
    bool choice[maxn][maxv] = {false};
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= w[i]; j--) {
            if (dp[j - w[i]] + w[i] >= dp[j]) {
                dp[j] = dp[j - w[i]] + w[i];
                choice[i][j] = true;
            }
        }
    }
    if (dp[m] != m)
        printf("No Solution\n");
    else {
        vector<int> ans;
        int v = m, pos = n;
        while (v > 0) {
            if (choice[pos][v]) {
                v -= w[pos];
                ans.push_back(w[pos]);
            }
            pos--;
        }
        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) printf(" ");
            printf("%d", ans[i]);
        }
    }
    return 0;
}