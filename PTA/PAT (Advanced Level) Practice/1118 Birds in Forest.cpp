// https://pintia.cn/problem-sets/994805342720868352/problems/994805354108403712
#include <bits/stdc++.h>
using namespace std;
int father[10010];
int findFather(int x) {
    return x == father[x] ? x : father[x] = findFather(father[x]);
}
void uni(int a, int b) {
    int faA = findFather(a), faB = findFather(b);
    if (faA != faB) father[faA] = faB;
}
int main() {
    for (int i = 0; i < 10010; i++) father[i] = i;
    int n, m, k, a, b, cntBird = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &k, &a);
        cntBird = max(cntBird, a);
        for (int j = 0; j < k - 1; j++) {
            scanf("%d", &b);
            uni(a, b);
            cntBird = max(cntBird, b);
        }
    }
    unordered_map<int, int> mp;
    for (int i = 1; i <= cntBird; i++) mp[findFather(i)]++;
    printf("%d %d\n", mp.size(), cntBird);
    scanf("%d", &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        printf("%s\n", findFather(a) == findFather(b) ? "Yes" : "No");
    }
    return 0;
}