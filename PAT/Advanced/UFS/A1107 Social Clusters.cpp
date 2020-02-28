// https://pintia.cn/problem-sets/994805342720868352/problems/994805361586847744
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int father[N];
int findFather(int x) {
    return x == father[x] ? x : father[x] = findFather(father[x]);
}
void uni(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) father[faA] = faB;
}
int main() {
    for (int i = 0; i < N; i++) father[i] = i;
    int n, k, h, hobby[N] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d: ", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &h);
            if (hobby[h] != 0) uni(i, findFather(hobby[h]));
            else hobby[h] = i;
        }
    }
    unordered_map<int, int> mp;
    vector<int> ans;
    for (int i = 1; i <= n; i++) mp[findFather(i)]++;
    for (auto it : mp) ans.push_back(it.second);
    printf("%d\n", ans.size());
    sort(ans.begin(), ans.end());
    for (int i = ans.size() - 1; i >= 0; i--) {
        printf("%d", ans[i]);
        if (i != 0) printf(" ");
    }
    return 0;
}