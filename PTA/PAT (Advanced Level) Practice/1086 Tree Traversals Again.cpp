// https://pintia.cn/problem-sets/994805342720868352/problems/994805380754817024
#include <bits/stdc++.h>
using namespace std;
vector<int> pre, in;
int n, cnt = 0;
void postOrder(int prel, int prer, int inl, int inr) {
    if (prel > prer) return;
    int k = inl;
    while (pre[prel] != in[k]) k++;
    int numleft = k - inl;
    postOrder(prel + 1, prel + numleft, inl, k - 1);
    postOrder(prel + numleft + 1, prer, k + 1, inr);
    printf("%d", pre[prel]);
    if (++cnt < n) printf(" ");
}
int main() {
    char op[5];
    int x;
    stack<int> s;
    scanf("%d", &n);
    for (int i = 0; i < n * 2; i++) {
        scanf("%s", op);
        if (op[1] == 'u') {
            scanf("%d", &x);
            s.push(x);
            pre.push_back(x);
        } else {
            in.push_back(s.top());
            s.pop();
        }
    }
    postOrder(0, n - 1, 0, n - 1);
    return 0;
}