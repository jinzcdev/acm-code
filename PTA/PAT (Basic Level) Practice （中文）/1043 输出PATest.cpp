
// https://pintia.cn/problem-sets/994805260223102976/problems/994805280074743808
#include <bits/stdc++.h>
using namespace std;
int main() {
    int cnt[6] = {0};
    string str, pat = "PATest";
    cin >> str;
    map<char, int> m;
    for (int i = 0; i < pat.length(); i++) m[pat[i]] = i;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'P' || str[i] == 'A' || str[i] == 'T' || str[i] == 'e' ||
            str[i] == 's' || str[i] == 't')
            cnt[m[str[i]]]++;
    }
    int Max = -1;
    for (int i = 0; i < 6; i++) Max = max(cnt[i], Max);
    while (Max--) {
        for (int i = 0; i < 6; i++) {
            if (cnt[i] > 0) {
                cnt[i]--;
                printf("%c", pat[i]);
            }
        }
    }
    return 0;
}