// https://pintia.cn/problem-sets/994805046380707840/problems/994805059731177472
#include <bits/stdc++.h>
using namespace std;
struct node {
    string name;
    int cnt;
};
int main() {
    int n, m, a, sum = 0;
    double avg = 0;
    string s;
    unordered_map<string, int> hash;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> s;
        hash[s] = 1;
    }
    scanf("%d", &m);
    vector<node> v;
    for (int i = 0; i < m; i++) {
        cin >> s >> a;
        v.push_back({s, a});
        sum += a;
    }
    avg = sum * 1.0 / m;
    vector<string> ans;
    for (int i = 0; i < m; i++) {
        if (hash[v[i].name]) continue;
        if (v[i].cnt > avg) ans.push_back(v[i].name);
    }
    if (ans.size() == 0) printf("Bing Mei You\n");
    else {
        sort(ans.begin(), ans.end());
        for (auto it : ans) cout << it << endl;
    }
    return 0;
}