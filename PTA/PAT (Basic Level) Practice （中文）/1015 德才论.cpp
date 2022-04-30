// https://pintia.cn/problem-sets/994805260223102976/problems/994805307551629312
// https://pintia.cn/problem-sets/994805342720868352/problems/994805410555346944
#include <bits/stdc++.h>
using namespace std;
struct node {
    int id, virtue, talent, sum, type;
};
bool cmp(node a, node b) {
    if (a.type != b.type) return a.type < b.type;
    else if (a.sum != b.sum) return a.sum > b.sum;
    else if (a.virtue != b.virtue) return a.virtue > b.virtue;
    else return a.id < b.id;
}
int main() {
    int n, l, h, id, virtue, talent, type = 0;
    cin >> n >> l >> h;
    vector<node> v;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &id, &virtue, &talent);
        if (virtue < l || talent < l) continue;
        if (virtue >= h && talent >= h) type = 1;
        else if (virtue >= h && talent < h) type = 2;
        else if (virtue >= talent) type = 3;
        else type = 4;
        v.push_back({id, virtue, talent, virtue + talent, type});
    }
    cout << v.size() << endl;
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) printf("%d %d %d\n", v[i].id, v[i].virtue, v[i].talent);
    return 0;
}