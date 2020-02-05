// https://pintia.cn/problem-sets/994805342720868352/problems/994805390896644096
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    getchar();
    vector<string> v(n);
    string s;
    int minlen = 999;
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        reverse(s.begin(), s.end());
        v[i] = move(s);
        if (v[i].length() < minlen) minlen = v[i].length();
    }
    string ans = "";
    for (int i = 0; i < minlen; i++) {
        bool flag = true;
        for (int j = 0; j < v.size() - 1; j++) {
            if (v[j][i] != v[j + 1][i]) {
                flag = false;
                break;
            }
        }
        if (!flag) break;
        ans += v[0][i];
    }
    reverse(ans.begin(), ans.end());
    while (ans[0] == ' ') ans.erase(ans.begin());
    printf("%s\n", ans.size() == 0 ? "nai" : ans.c_str());
    return 0;
}