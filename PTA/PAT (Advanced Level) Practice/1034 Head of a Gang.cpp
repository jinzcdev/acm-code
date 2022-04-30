// https://pintia.cn/problem-sets/994805342720868352/problems/994805456881434624
#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int n, k, weight[N][N] = {0}, w[N] = {0}, cnt, maxW, totalW, head;
bool vis[N] = {false};
vector<int> e[N];
unordered_map<string, int> strToId;
unordered_map<int, string> idToStr;
void dfs(int u) {
    cnt++;
    vis[u] = true;
    if (w[u] > w[head]) head = u;
    for (auto it : e[u]) {
        totalW += weight[u][it];
        weight[u][it] = weight[it][u] = 0;
        if (!vis[it]) dfs(it);
    }
}
int main() {
    scanf("%d%d", &n, &k);
    string a, b;
    int time, num = 1;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> time;
        int aid = strToId[a], bid = strToId[b];
        if (aid == 0) {
            strToId[a] = num;
            idToStr[num] = a;
            aid = num++;
        }
        if (bid == 0) {
            strToId[b] = num;
            idToStr[num] = b;
            bid = num++;
        }
        w[aid] += time;
        w[bid] += time;
        weight[aid][bid] = weight[bid][aid] += time;
        e[aid].push_back(bid);
        e[bid].push_back(aid);
    }
    map<string, int> ans;
    for (int i = 1; i < num; i++) {
        if (!vis[i]) {
            head = i;
            cnt = totalW = 0;
            dfs(i);
            if (cnt > 2 && totalW > k) ans[idToStr[head]] = cnt;
        }
    }
    printf("%d\n", ans.size());
    for (auto it : ans) {
        printf("%s %d\n", it.first.c_str(), it.second);
    }
    return 0;
}
