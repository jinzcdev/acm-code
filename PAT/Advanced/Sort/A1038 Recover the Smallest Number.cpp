// https://pintia.cn/problem-sets/994805342720868352/problems/994805449625288704
#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b) { return a + b < b + a; }
int main() {
    int n;
    cin >> n;
    string ans = "";
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++) ans += v[i];
    while (ans.size() != 0 && ans[0] == '0') ans.erase(0, 1);
    if (ans.size() == 0) cout << 0;
    else cout << ans;
    return 0;
}