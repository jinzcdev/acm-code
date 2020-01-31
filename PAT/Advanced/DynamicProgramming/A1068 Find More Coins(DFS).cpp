// https://pintia.cn/problem-sets/994805342720868352/problems/994805402305150976
#include <bits/stdc++.h>
using namespace std;
int n, m, len = 0;
vector<int> v, ans, temp;
bool flag = false;
void dfs(int pos, int amount) {
    if (flag == true || pos == len || amount > m) return;
    if (amount == m) {
        if (!flag) {
            ans = temp;
            flag = true;
        }
        return;
    }
    temp.push_back(v[pos]);
    dfs(pos + 1, amount + v[pos]);
    temp.pop_back();
    dfs(pos + 1, amount);
}

int main() {
    scanf("%d%d", &n, &m);
    v.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    while (len < n && v[len] <= m) len++;
    dfs(0, 0);
    if (!flag) printf("No Solution\n");
    else {
        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) printf(" ");
            printf("%d", ans[i]);
        }
    }
    return 0;
}