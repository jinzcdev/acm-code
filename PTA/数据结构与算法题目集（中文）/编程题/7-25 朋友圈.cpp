// https://pintia.cn/problem-sets/15/problems/840
#include <bits/stdc++.h>
using namespace std;
int father[30010];
int findFather(int x) {
    return x == father[x] ? x : father[x] = findFather(father[x]);
}
void uni(int a, int b) {
    int faA = findFather(a), faB = findFather(b);
    if (faA != faB) father[faA] = faB;
}
int main() {
    int n, m, k, a, b, ans = -1;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) father[i] = i;
    while (m--) {
        scanf("%d%d", &k, &a);
        for (int i = 0; i < k - 1; i++) {
            scanf("%d", &b);
            uni(a, b);
        }
    }
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) ans = max(ans, ++mp[findFather(i)]);
    printf("%d", ans);
    return 0;
}