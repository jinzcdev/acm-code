// https://pintia.cn/problem-sets/1284828941281595392/problems/1285384032661405697
#include <bits/stdc++.h>
using namespace std;
const int N = 20, M = 1010;
int n, m, a, b, game[M][N] = {0};
unordered_map<int, bool> is_out, exist;
unordered_set<int> s;

bool isdiff(int x) {
    for (auto it : s)
        if (exist[it + x]) return true;
    return false;
}
int main() {
    scanf("%d%d%d%d", &a, &b, &n, &m);
    s.insert(a);
    s.insert(b);
    exist[a] = exist[b] = true;
    for (int j = 0; j < n; j++)
        for (int i = 0; i < m; i++) scanf("%d", &game[i][j]);
    for (int i = 0; i < m; i++) {
        vector<int> out;
        for (int j = 0; j < n; j++) {
            if (is_out[j]) continue;
            int x = game[i][j];
            if (exist[x] || !isdiff(x)) {
                out.push_back(j);
                is_out[j] = true;
            } else {
                s.insert(x);
                exist[x] = true;
            }
        }
        if (out.size() != 0) {
            for (int k = 0; k < out.size(); k++)
                printf("Round #%d: %d is out.\n", i + 1, out[k] + 1);
        }
    }
    vector<int> winner;
    for (int i = 0; i < n; i++)
        if (!is_out[i]) winner.push_back(i + 1);

    printf("%s", winner.size() == 0 ? "No winner." : "Winner(s):");
    for (int i = 0; i < winner.size(); i++) printf(" %d", winner[i]);
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
bool solve(vector<int> &v, int k) {
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (abs(v[i] - v[j]) == k) return true;
        }
    }
    return false;
}
int main() {
    int x, y, n, m, a;
    scanf("%d%d%d%d", &x, &y, &n, &m);
    vector<vector<int> > turn(m + 1, vector<int>(n + 1));
    vector<int> pre;
    pre.push_back(x);
    pre.push_back(y);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &turn[j][i]);
        }
    }
    bool isout[N] = {false}, vis[100010] = {false};
    vis[x] = vis[y] = true;
    for (int i = 1; i <= m; i++) {
        vector<int> ans;
        for (int j = 1; j <= n; j++) {
            if (isout[j]) continue;
            int k = turn[i][j];
            if (!vis[k] && solve(pre, k)) {
                pre.push_back(k);
            } else {
                isout[j] = true;
                ans.push_back(j);
            }
                vis[k] = true;
        }
        if (ans.size() == 0) continue;
        printf("Round #%d:", i);
        sort(ans.begin(), ans.end());
        for (int k = 0; k < ans.size(); k++) {
            printf(" %d", ans[k]);
        }
        printf(" is out.\n");
    }
    vector<int> winner;
    for (int i = 1; i <= n; i++) {
        if (!isout[i]) winner.push_back(i);
    }
    if (winner.size() == 0)
        printf("No winner.\n");
    else {
        printf("Winner(s):");
        for (int i = 0; i < winner.size(); i++) {
            printf(" %d", winner[i]);
        }
    }
    return 0;
}
*/