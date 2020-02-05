// https://pintia.cn/problem-sets/994805342720868352/problems/994805381845336064
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, p;
    scanf("%d%d", &n, &p);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = i + ans;
        for (; j < n; j++) {
            if (a[j] > a[i] * p) break;
            ans = max(ans, j - i + 1);
        }
    }
    printf("%d", ans);
    return 0;
}