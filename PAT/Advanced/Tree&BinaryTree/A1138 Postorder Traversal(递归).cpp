// https://pintia.cn/problem-sets/994805342720868352/problems/994805345078067200
#include <bits/stdc++.h>
using namespace std;
vector<int> pre, in;
int solve(int preL, int preR, int inL, int inR) {
    if (preL > preR) return -1;
    if (preL == preR) return pre[preL];
    int k = inL;
    while (in[k] != pre[preL]) k++;
    int numLeft = k - inL;
    if (numLeft > 0) return solve(preL + 1, preL + numLeft, inL, k - 1);
    else return solve(preL + numLeft + 1, preR, k + 1, inR);
}
int main() {
    int n;
    cin >> n;
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    printf("%d", solve(0, n - 1, 0, n - 1));
    return 0;
}