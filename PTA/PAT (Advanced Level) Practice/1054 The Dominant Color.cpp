// https://pintia.cn/problem-sets/994805342720868352/problems/994805422639136768
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, a, maxCnt = -1, ans;
    unordered_map<int, int> hash;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a);
            if (++hash[a] > maxCnt) {
                maxCnt = hash[a];
                ans = a;
            }
        }
    }
    printf("%d", ans);
    return 0;
}