// https://pintia.cn/problem-sets/994805342720868352/problems/994805356599820288
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
struct node {
    int id, cnt = 0;
    double estate, area;
};
int father[N], mestate[N] = {0}, area[N] = {0};
int findFather(int x) {
    return x == father[x] ? x : father[x] = findFather(father[x]);
}
void uni(int a, int b) {
    int faA = findFather(a), faB = findFather(b);
    if (faA < faB) father[faB] = faA;
    else if (faA > faB) father[faA] = faB;
}
bool cmp(node &a, node &b) {
    return a.area != b.area ? a.area > b.area : a.id < b.id;
}
int main() {
    for (int i = 0; i < N; i++) father[i] = i;
    int n, id;
    scanf("%d", &n);
    unordered_set<int> s;
    while (n--) {
        int fa, mo, k, child;
        scanf("%d%d%d%d", &id, &fa, &mo, &k);
        s.insert(id);
        if (fa != -1) {
            uni(id, fa);
            s.insert(fa);
        }
        if (mo != -1) {
            uni(id, mo);
            s.insert(mo);
        }
        while (k--) {
            scanf("%d", &child);
            s.insert(child);
            uni(id, child);
        }
        scanf("%d%d", &mestate[id], &area[id]);
    }
    unordered_map<int, node> mp;
    for (auto it : s) {
        int fa = findFather(it);
        mp[fa].cnt++;
        mp[fa].estate += mestate[it];
        mp[fa].area += area[it];
    }
    vector<node> ans;
    for (auto it : mp) {
        node temp = move(it.second);
        ans.push_back({it.first, temp.cnt, temp.estate / temp.cnt, temp.area / temp.cnt});
    }
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", ans.size());
    for (auto it : ans) {
        printf("%04d %d %.3f %.3f\n", it.id, it.cnt, it.estate, it.area);
    }
    return 0;
}