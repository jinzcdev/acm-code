#include <iostream>
#include <vector>
using namespace std;
const int N = 110;
int n, a[N], dp[N], maxlen = -1, ansIndex = 0;
vector<int> pre[N], path, ans;
void dfs(int u) {
    path.push_back(u);
    if (pre[u].size() == 0) {
        for (int i = path.size() - 1; i >= 0; i--) {
            printf("%d", a[path[i]]);
            if (i != 0) printf(" ");
        }
        printf("\n");
        path.pop_back();    // 1
        return;             // 2 这两句不加也可, 为了体现其已走到尽头, 则做return
    }
    for (auto it : pre[u]) dfs(it);
    path.pop_back();  // u的所有孩子都访问完了, 把u从路径数组中移除
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] >= a[j]) {
                if (dp[j] + 1 > dp[i]) {  // 比原来的LIS更长, 则i的前驱清空, 将j添加进去
                    dp[i] = dp[j] + 1;
                    pre[i].clear();
                    pre[i].push_back(j);
                } else if (dp[j] + 1 == dp[i]) {  // 一样长,则j也可作为一种选择, 把j添加进去
                    pre[i].push_back(j);
                }
            }
        }
        if (dp[i] > maxlen) {
            maxlen = dp[i];
            ans.clear();
            ans.push_back(i);
        } else if (dp[i] == maxlen) {
            ans.push_back(i);
        }
    }
    for (auto it : ans) dfs(it);
    return 0;
}