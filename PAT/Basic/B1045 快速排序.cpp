// https://pintia.cn/problem-sets/994805260223102976/problems/994805278589960192
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n), dp(n), ans;
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    dp[0] = v[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1], v[i]);
    }
    for (int i = 0; i < v.size(); i++) {
        bool flag = true;
        if (dp[i] != v[i]) flag = false;
        for (int j = i; flag && j < v.size(); j++) {
            if (v[j] < v[i]) {
                flag = false;
                break;
            }
        }
        if (flag) ans.push_back(v[i]);
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    if (ans.size() == 0) printf("\n");
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}