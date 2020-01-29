// https://pintia.cn/problem-sets/994805342720868352/problems/994805398257647616
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    map<string, int> mcnt;
    string word;
    for (int i = 0; i < s.length(); i++) {
        if (isalnum(s[i])) {
            s[i] = tolower(s[i]);
            word += s[i];
        }
        if (!isalnum(s[i]) || i == s.length() - 1) {
            if (word != "") mcnt[word]++;
            word = "";
        }
    }
    string ans;
    int maxCnt = -1;
    for (auto it : mcnt) {
        if (it.second > maxCnt) {
            ans = it.first;
            maxCnt = it.second;
        }
    }
    printf("%s %d", ans.c_str(), maxCnt);
    return 0;
}