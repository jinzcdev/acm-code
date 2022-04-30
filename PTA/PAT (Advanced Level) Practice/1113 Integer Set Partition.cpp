// https://pintia.cn/problem-sets/994805342720868352/problems/994805357258326016
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, sum = 0;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n / 2; i++) sum -= v[i] * 2;
    printf("%d %d", n % 2, sum);
    return 0;
}