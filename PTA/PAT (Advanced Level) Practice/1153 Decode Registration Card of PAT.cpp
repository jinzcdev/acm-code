// https://pintia.cn/problem-sets/994805342720868352/problems/1071785190929788928
#include <bits/stdc++.h>
using namespace std;
struct node {
    string card;
    int score;
};
bool cmp(node &a, node &b) {
    return a.score != b.score ? a.score > b.score : a.card < b.card;
}
int main() {
    int n, m, type;
    scanf("%d%d", &n, &m);
    vector<node> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].card >> v[i].score;
    string query;
    for (int i = 1; i <= m; i++) {
        cin >> type >> query;
        printf("Case %d: %d %s\n", i, type, query.c_str());
        vector<node> ans;
        if (type == 1) {
            for (int j = 0; j < n; j++)
                if (v[j].card[0] == query[0]) ans.push_back(v[j]);
        } else if (type == 2) {
            int sum = 0, cnt = 0;
            for (int j = 0; j < n; j++)
                if (v[j].card.substr(1, 3) == query) {
                    cnt++;
                    sum += v[j].score;
                }
            if (cnt != 0) printf("%d %d\n", cnt, sum);
            else printf("NA\n");
            continue;
        } else {
            unordered_map<string, int> mp;
            for (int j = 0; j < n; j++)
                if (v[j].card.substr(4, 6) == query)
                    mp[v[j].card.substr(1, 3)]++;
            for (auto it : mp) ans.push_back({it.first, it.second});
        }
        sort(ans.begin(), ans.end(), cmp);
        if (ans.size() == 0) printf("NA\n");
        else {
            for (int i = 0; i < ans.size(); i++) 
                printf("%s %d\n", ans[i].card.c_str(), ans[i].score);
        }
    }
    return 0;
}