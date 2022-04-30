// https://pintia.cn/problem-sets/994805342720868352/problems/994805362341822464
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
vector<int> e[N], ans;
int n, k, cntMin = 0;
double r, p, minPrice = 0x3f3f3f3f;
void dfs(int u, double price) {
    if (e[u].size() == 0) {
        if (price < minPrice) {
            minPrice = price;
            cntMin = 1;
        } else if (price == minPrice) {
            cntMin++;
        }
        return;
    }
    for (auto it : e[u]) {
        double tempP = price * (1 + r / 100);
        if (tempP <= minPrice) dfs(it, tempP);
    }
}
int main() {
    scanf("%d%lf%lf", &n, &p, &r);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        int temp;
        while (k--) {
            scanf("%d", &temp);
            e[i].push_back(temp);
        }
    }
    dfs(0, p);
    printf("%.4f %d", minPrice, cntMin);
    return 0;
}