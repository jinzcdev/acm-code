// https://pintia.cn/problem-sets/994805342720868352/problems/994805354762715136
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    sort(v.begin() + 1, v.begin() + 1 + n, [](int a, int b) { return a > b; });
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (i < v[i]) ans = i;
    printf("%d", ans);
    return 0;
}
