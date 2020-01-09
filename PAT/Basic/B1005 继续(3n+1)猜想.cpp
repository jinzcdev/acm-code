// https://pintia.cn/problem-sets/994805260223102976/problems/994805320306507776
#include <bits/stdc++.h>
using namespace std;
bool vis[99999] = {false};
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n), ans;
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    for (int i = 0; i < n; i++) {
        int temp = v[i];
        while (temp != 1) {
            if (temp % 2 == 0) temp /= 2;
            else temp = (3 * temp + 1) / 2;
            vis[temp] = true;
        }
    }
    for (int i = 0; i < n; i++)
        if (!vis[v[i]]) ans.push_back(v[i]);
    sort(ans.begin(), ans.end());
    for (int i = ans.size() - 1; i >= 0; i--) {
        printf("%d", ans[i]);
        if (i != 0) printf(" ");
    }
    return 0;
}