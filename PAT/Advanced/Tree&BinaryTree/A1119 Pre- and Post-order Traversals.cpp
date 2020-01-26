// https://pintia.cn/problem-sets/994805342720868352/problems/994805353470869504
#include <bits/stdc++.h>
using namespace std;
bool isunique = true;
vector<int> pre, post, in;
void solve(int prel, int prer, int postl, int postr) {
    if (prel > prer || pre[prel] != post[postr]) return;
    if (prel == prer) {
        in.push_back(pre[prel]);
        return;
    }
    int k = prel + 1;
    while (pre[k] != post[postr - 1]) k++;
    if (k == prel + 1) isunique = false;
    solve(prel + 1, k - 1, postl, postl + k - prel - 1 - 1);
    in.push_back(pre[prel]);
    solve(k, prer, postl + k - prel - 1, postr - 1);
    // int k = postr - 1;
    // while (post[k] != pre[prel + 1]) k--;
    // if (k == postr - 1) isunique = false;
    // solve(prel + 1, prel + (k - postl + 1), postl, k);
    // in.push_back(pre[prel]);
    // solve(prel + (k - postl + 1) + 1, prer, k + 1, postr - 1);
}
int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n);
    post.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);
    solve(0, n - 1, 0, n - 1);
    printf("%s\n", isunique ? "Yes" : "No");
    for (int i = 0; i < in.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", in[i]);
    }
    printf("\n");
    return 0;
}