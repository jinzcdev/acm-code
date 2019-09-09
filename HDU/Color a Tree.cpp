// http://acm.hdu.edu.cn/showproblem.php?pid=1055
#include <iostream>
#include <vector>
#include <algorithm>
const int maxn = 1010;
using namespace std;
vector<int> tree[maxn];
int c[maxn], n, R, ans = 0x7FFFFFFF;

bool cmp(int a, int b) {
    return c[a] < c[b];
}

void dfs(int index, int k, int t){
    if (k == n) {
        if (t < ans) ans = t;
        return;
    }
    for (int v = 0; v < tree[index].size(); v++) {
        dfs(tree[index][v], k + 1, t + 1);
    }
}

int main() {
    int pra, child;
    cin >> n >> R;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> pra >> child;
        if (pra == 0 && child == 0) break;
        tree[pra].push_back(child);
    }
    // for (int pra = 1; pra < n; pra++) {
    //     if (tree[pra].size() != 0) sort(tree[pra].begin(), tree[pra].end(), cmp);
    // }
    dfs(R, 1, 1);
    cout << ans;
    return 0;
}