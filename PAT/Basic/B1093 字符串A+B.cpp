// https://pintia.cn/problem-sets/994805260223102976/problems/1071785884776722432
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b;
    bool vis[128] = {false};
    getline(cin, a);
    getline(cin, b);
    a += b;
    for (int i = 0; i < a.size(); i++) {
        if (!vis[a[i]]) {
            cout << a[i];
            vis[a[i]] = true;
        }
    }
    return 0;
}