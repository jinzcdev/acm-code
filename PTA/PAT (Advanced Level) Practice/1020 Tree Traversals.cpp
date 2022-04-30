// https://pintia.cn/problem-sets/994805342720868352/problems/994805485033603072
#include <bits/stdc++.h>
using namespace std;
const int N = 35;
struct node {
    int data, pos, depth;
};
int post[N], in[N], n, pos = 0;
vector<node> ans;
bool cmp(node &a, node &b) {
    return a.depth != b.depth ? a.depth < b.depth : a.pos < b.pos;
}
void solve(int postl, int postr, int inl, int inr, int depth) {
    if (postl > postr) return;
    ans.push_back({post[postr], pos++, depth + 1});
    int k = inl;
    while (k <= inr && in[k] != post[postr]) k++;
    int numleft = k - inl;
    solve(postl, postl + numleft - 1, inl, k - 1, depth + 1);
    solve(postl + numleft, postr - 1, k + 1, inr, depth + 1);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    solve(0, n - 1, 0, n - 1, 1);
    sort(ans.begin(), ans.end(), cmp);
    printf("%d", ans[0]);
    for (int i = 1; i < ans.size(); i++) printf(" %d", ans[i]);
    return 0;
}