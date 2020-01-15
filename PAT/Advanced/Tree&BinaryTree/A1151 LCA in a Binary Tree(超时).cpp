// https://pintia.cn/problem-sets/994805342720868352/problems/1038430130011897856
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
struct node {
    int data;
    node *lchild, *rchild;
};
int pre[maxn], in[maxn], u, v, ans = -1;
int solve(int preL, int preR, int inL, int inR) {
    if (preL > preR) return false;
    int k = inL;
    while (in[k] != pre[preL]) k++;
    int numLeft = k - inL;
    int left = solve(preL + 1, preL + numLeft, inL, k - 1) ? 1 : 0;
    int right = solve(preL + numLeft + 1, preR, k + 1, inR) ? 1 : 0;
    int mid = (pre[preL] == u || pre[preL] == v) ? 1 : 0;
    if (mid + left + right >= 2) ans = pre[preL];
    return mid + left + right;
}
int main() {
    int n, m;
    unordered_map<int, int> mp;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
        mp[in[i]] = 1;
    }
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    while (m--) {
        ans = -1;
        scanf("%d%d", &u, &v);
        solve(0, n - 1, 0, n - 1);
        if (mp[u] == 0 && mp[v] == 0)
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if (mp[u] == 0)
            printf("ERROR: %d is not found.\n", u);
        else if (mp[v] == 0)
            printf("ERROR: %d is not found.\n", v);
        else if (ans == u)
            printf("%d is an ancestor of %d.\n", u, v);
        else if (ans == v)
            printf("%d is an ancestor of %d.\n", v, u);
        else
            printf("LCA of %d and %d is %d.\n", u, v, ans);
    }
    return 0;
}