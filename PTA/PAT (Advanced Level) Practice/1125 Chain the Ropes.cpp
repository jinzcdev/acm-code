// https://pintia.cn/problem-sets/994805342720868352/problems/994805350316752896
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    double ans = v[0];
    for (int i = 1; i < v.size(); i++) ans = (ans + v[i]) / 2;
    printf("%d", int(ans));
    return 0;
}