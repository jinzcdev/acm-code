// https://pintia.cn/problem-sets/17/problems/263
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int ans[25], len = 0, carry = 0, cnt[10] = {0};
    for (int i = s.length() - 1; i >= 0; i--) {
        cnt[s[i] - '0']++;
        int temp = (s[i] - '0') * 2 + carry;
        ans[len++] = temp % 10;
        carry = temp / 10;
    }
    if (carry != 0) ans[len++] = carry;
    bool flag = true;
    for (int i = 0; i < len; i++) {
        if (--cnt[ans[i]] < 0) {
            flag = false;
            break;
        }
    }
    printf("%s\n", flag ? "Yes" : "No");
    for (int i = len - 1; i >= 0; i--) printf("%d", ans[i]);
    return 0;
}