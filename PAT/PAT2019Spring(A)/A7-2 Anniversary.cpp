#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    scanf("%d", &n);
    map<string, int> mp;
    string id, ans;
    for (int i = 0; i < n; i++) {
        cin >> id;
        mp[id] = stoi(id.substr(6, 8));
    }
    scanf("%d", &m);
    int Min = 0x3f3f3f3f, ansMin = 0x3f3f3f3f, cnt = 0;
    for (int i = 0; i < m; i++) {
        cin >> id;
        if (cnt == 0 && stoi(id.substr(6, 8)) < Min) {
            ans = id;
            Min = stoi(id.substr(6, 8));
        }
        if (mp[id] != 0) {
            cnt++;
            if (stoi(id.substr(6, 8)) < ansMin) {
                ansMin = stoi(id.substr(6, 8));
                ans = id;
            }
        }
    }
    printf("%d\n%s", cnt, ans.c_str());
    return 0;
}