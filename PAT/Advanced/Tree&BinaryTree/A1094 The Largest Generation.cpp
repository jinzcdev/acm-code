// https://pintia.cn/problem-sets/994805342720868352/problems/994805372601090048
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
vector<int> e[N];
int cnt[N] = {0}, maxCnt = -1, ans;
void dfs(int root, int depth) {
    if (++cnt[depth] > maxCnt) {
        maxCnt = cnt[depth];
        ans = depth;
    }
    for (auto it : e[root]) dfs(it, depth + 1);
}
int main() {
    int n, m, k, a, b;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &a, &k);
        while (k--) {
            scanf("%d", &b);
            e[a].push_back(b);
        }
    }
    dfs(1, 1);
    printf("%d %d\n", cnt[ans], ans);
    return 0;
}