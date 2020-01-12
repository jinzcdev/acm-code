// https://pintia.cn/problem-sets/994805342720868352/problems/994805446102073344
#include <bits/stdc++.h>
#define N 1010
using namespace std;
bool dp[N][N] = {false};
int main() {
    string s;
    getline(cin, s);
    int maxLen = 1;
    for (int i = 0; i < s.length(); i++) {
        dp[i][i] = true;
        if (i < s.length() - 1 && s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            maxLen = 2;
        }
    }
    for (int len = 3; len <= s.length(); len++) {
        for (int i = 0; i < s.length() - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
            if (dp[i][j]) maxLen = max(maxLen, j - i + 1);
        }
    }
    cout << maxLen;
    return 0;
}