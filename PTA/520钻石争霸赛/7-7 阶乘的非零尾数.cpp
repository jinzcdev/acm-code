// https://pintia.cn/problem-sets/1259839299727368192/problems/1259850789826048004
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, carry = 0, cnt = 0;
    scanf("%d%d", &n, &k);
    string ans = "1";
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < ans.size(); j++) {
            int temp = (ans[j] - '0') * i + carry;
            ans[j] = temp % 10 + '0';
            carry = temp / 10;
        }
        if (carry != 0) {
            string s = to_string(carry);
            reverse(s.begin(), s.end());
            ans += s;
            carry = 0;
        }
    }
    while (ans[0] == '0') {
        ans.erase(ans.begin());
        cnt++;
    }
    string s = ans.substr(0, k);
    reverse(s.begin(), s.end());
    cout << s << " " << cnt;
    return 0;
}