// https://pintia.cn/problem-sets/994805342720868352/problems/994805429018673152
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    bool hash[128] = {false};
    for (int i = 0; i < b.length(); i++) hash[b[i]] = true;
    for (int i = 0; i < a.length(); i++)
        if (!hash[a[i]]) printf("%c", a[i]);
    return 0;
}