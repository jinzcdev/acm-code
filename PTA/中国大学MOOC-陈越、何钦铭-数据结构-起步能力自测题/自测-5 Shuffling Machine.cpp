// https://pintia.cn/problem-sets/17/problems/264
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, order[55];
    cin >> n;
    vector<int> ans(55);
    string s = "SHCDJ";
    for (int i = 1; i <= 54; i++) cin >> order[i];
    for (int i = 1; i <= 54; i++) ans[i] = i;
    while (n--) {
        vector<int> temp(55);
        for (int i = 1; i <= 54; i++) temp[order[i]] = ans[i];
        ans.swap(temp);
    }
    for (int i = 1; i <= 54; i++) {
        if (i != 1) printf(" ");
        printf("%c%d", s[(ans[i] - 1) / 13], ans[i] % 13 == 0 ? 13 : ans[i] % 13);
    }
    return 0;
}