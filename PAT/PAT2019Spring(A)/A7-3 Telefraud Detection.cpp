#include <bits/stdc++.h>
using namespace std;
int father[1010];
int findFather(int x) {
    return x == father[x] ? x : father[x] = findFather(father[x]);
}
void uni(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA < faB) father[faB] = faA;
    if (faA > faB) father[faA] = faB;
}
int main() {
    for (int i = 0; i < 1010; i++) father[i] = i;
    int k, n, m, a, b, time;
    scanf("%d%d%d", &k, &n, &m);
    vector<map<int, int> > record(n + 1);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &time);
        record[a][b] += time;
    }
    vector<int> suspect;
    for (int i = 1; i <= n; i++) {
        if (record[i].size() <= k) continue;
        int callto = 0, callback = 0;
        for (auto it : record[i]) {
            if (it.second <= 5) {
                callto++;
                if (record[it.first].find(i) != record[it.first].end()) callback++;
            }
        }
        if (callto > k && callback * 1.0 / callto <= 0.2) suspect.push_back(i);
    }
    if (suspect.size() == 0) {
        printf("None\n");
        return 0;
    }
    for (int i = 0; i < suspect.size() - 1; i++) {
        for (int j = i + 1; j < suspect.size(); j++) {
            a = suspect[i]; b = suspect[j];
            if (record[a][b] > 0 && record[b][a] > 0) uni(a, b);
        }
    }
    map<int, vector<int> > mp;
    for (auto it : suspect) mp[findFather(it)].push_back(it);
    for (auto it : mp) {
        vector<int> gang = move(it.second);
        sort(gang.begin(), gang.end());
        for (int i = 0; i < gang.size(); i++) {
            if (i != 0) printf(" ");
            printf("%d", gang[i]);
        }
        printf("\n");
    }
    return 0;
}