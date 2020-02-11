// https://pintia.cn/problem-sets/994805342720868352/problems/994805437411475456
#include <bits/stdc++.h>
using namespace std;
int n, m, l, temp, dp[10010], number[210];
vector<int> pre[10010];
vector<int> a, ans, path;
void printAns(int x) {
    path.push_back(x);
    if (pre[x].size() == 0) {
        for (int i = path.size() - 1; i >= 0; i--) {
            printf("%d", a[path[i]]);
            if (i != 0) printf(" ");
        }
        printf("\n");
        path.pop_back();
        return;
    }
    for (int i = 0; i < pre[x].size(); i++) {
        printAns(pre[x][i]);
    }
    path.pop_back();
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &temp);
        number[temp] = i;
    }
    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
        scanf("%d", &temp);
        if (number[temp] != 0) a.push_back(temp);
    }
    int maxlen = -1;
    for (int i = 0; i < a.size(); i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (number[a[i]] >= number[a[j]]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    pre[i].clear();
                    pre[i].push_back(j);
                } else if (dp[j] + 1 == dp[i]) {
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
    cout << maxlen << endl;
    for (auto it : ans) {
        printAns(it);
        printf("\n");
    }
    return 0;
}