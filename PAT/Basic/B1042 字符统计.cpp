// https://pintia.cn/problem-sets/994805260223102976/problems/994805280817135616
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int a[26] = {0};
    for (int i = 0; i < s.length(); i++) s[i] = tolower(s[i]);
    for (int i = 0; i < s.length(); i++)
        if (islower(s[i])) a[s[i] - 'a']++;
    int max = a[0], ans = 0;
    for (int i = 1; i < 26; i++) {
        if (a[i] > max) {
            max = a[i];
            ans = i;
        }
    }
    printf("%c %d", ans + 'a', max);
    return 0;
}