// https://pintia.cn/problem-sets/994805342720868352/problems/994805355358306304
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
bool isprime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
int main() {
    int n, m, a, rank[N] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        rank[a] = i;
    }
    bool vis[N] = {false};
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &a);
        printf("%04d: ", a);
        if (vis[a]) printf("Checked\n");
        else if (rank[a] == 0) printf("Are you kidding?\n");
        else {
            if (rank[a] == 1) printf("Mystery Award\n");
            else if (isprime(rank[a])) printf("Minion\n");
            else printf("Chocolate\n");
            vis[a] = true;
        }
    }
    return 0;
}