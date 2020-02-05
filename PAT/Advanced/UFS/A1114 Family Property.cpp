// https://pintia.cn/problem-sets/994805342720868352/problems/994805356599820288
// 错误点: 寻找father应该使用findFather, 不是father[idx]数组
#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
struct node {
    int id = 99999, cntMember = 0;
    double estate = 0, area = 0;
};
int father[N];
bool cmp(node a, node b) {
    return a.area != b.area ? a.area > b.area : a.id < b.id;
}
int findFather(int x) {
    if (x == father[x]) return x;
    int fa = findFather(father[x]);
    father[x] = fa;
    return fa;
}
void uni(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) father[faA] = faB;
}
int main() {
    for (int i = 0; i < N; i++) father[i] = i;
    int n, estate[N] = {0}, area[N] = {0}, id, fa, mo, child, k;
    scanf("%d", &n);
    unordered_set<int> v;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &id, &fa, &mo, &k);
        v.insert(id);
        if (fa != -1) {
            uni(id, fa);
            v.insert(fa);
        }
        if (mo != -1) {
            uni(id, mo);
            v.insert(mo);
        }
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            uni(id, child);
            v.insert(child);
        }
        scanf("%d%d", &estate[id], &area[id]);
    }
    map<int, node> family;
    for (auto it : v) {
        int fa = findFather(it);  // int fa = father[i]; (x)
        family[fa].id = min(family[fa].id, it);
        family[fa].cntMember++;
        family[fa].estate += estate[it];
        family[fa].area += area[it];
    }
    vector<node> ans;
    for (auto it : family) {
        it.second.estate /= it.second.cntMember;
        it.second.area /= it.second.cntMember;
        ans.push_back(it.second);
    }
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", ans.size());
    for (auto it : ans)
        printf("%04d %d %.3f %.3f\n", it.id, it.cntMember, it.estate, it.area);
    return 0;
}