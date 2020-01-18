// https://pintia.cn/problem-sets/994805342720868352/problems/994805357933608960
#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    string s;
    cin >> k >> s;
    int cnt = 0;
    char pre = s[0];
    bool isvalid[128] = {false}, vis[128] = {false};
    vector<char> ans;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == pre) {
            cnt++;
        } else {
            if (cnt % k != 0) isvalid[pre] = true;
            pre = s[i];
            cnt = 1;
        }
    }
    if (pre == s[s.length() - 1] && cnt % k != 0) isvalid[pre] = true;
    int i = 0;
    while (i < s.length()) {
        if (!isvalid[s[i]]) {
            if (!vis[s[i]]) {
                ans.push_back(s[i]);
                vis[s[i]] = true;
            }
            int j = i + 1;
            while (j < s.length() && s[j] == s[i]) j++;
            i = j;
        } else {
            i++;
        }
    }
    for (auto it : ans) printf("%c", it);
    printf("\n");
    for (int i = 0; i < s.length();) {
        printf("%c", s[i]);
        if (!isvalid[s[i]]) i += k;
        else i++;
    }
    return 0;
}