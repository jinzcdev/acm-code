#include <bits/stdc++.h>
#define MAXN 100
using namespace std;
int n;
bool vis[MAXN];
vector<int> v;

void dfs(int x) {
    v.push_back(x);
    if (v.size() == n) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
        v.pop_back();
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(i);
            vis[i] = false;
        }
    }
    v.pop_back();
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        vis[i] = true;
        dfs(i);
        vis[i] = false;
    }
    return 0;
}