// https://pintia.cn/problem-sets/994805342720868352/problems/994805407749357568
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, in[N], CBT[N], pos = 0;
void inOrder(int i) {
    if (i > n) return;
    inOrder(i * 2);
    CBT[i] = in[pos++];
    inOrder(i * 2 + 1);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    sort(in, in + n);
    inOrder(1);
    for (int i = 1; i <= n; i++) {
        if (i != 1) printf(" ");
        printf("%d", CBT[i]);
    }
    return 0;
}