// https://pintia.cn/problem-sets/994805342720868352/problems/994805462535356416
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, space = "";
    cin >> s;
    int num = (s.length() + 2) / 3 - 1;
    for (int i = 0; i < s.length() - num * 2 - 2; i++) space += " ";
    int i = 0;
    for (i = 0; i < num; i++)
        printf("%c%s%c\n", s[i], space.c_str(), s[s.length() - i - 1]);
    printf("%s", s.substr(i, s.length() - num * 2).c_str());
    return 0;
}