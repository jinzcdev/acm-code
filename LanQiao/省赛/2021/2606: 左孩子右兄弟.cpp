// https://www.dotcpp.com/oj/problem2606.html
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
vector<int> e[N];
int f(int u) {
    if (u == 0 || e[u].size() == 0) return 0;
    int tmp = -1;
    for (auto it : e[u]) tmp = max(tmp, f(it));
    return e[u].size() + tmp;
}
int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &x);
        e[x].push_back(i);
    }
    printf("%d", f(1));
    return 0;
}