// https://pintia.cn/problem-sets/994805342720868352/problems/994805348471259136
#include <bits/stdc++.h>
using namespace std;
struct node {
    int id, cnt;
};
bool cmp(node &a, node &b) {
    return a.cnt != b.cnt ? a.cnt > b.cnt : a.id < b.id;
}
int main() {
    int n, k, id;
    scanf("%d%d", &n, &k);
    vector<node> v;
    for (int i = 0; i < n; i++) {
        scanf("%d", &id);
        if (i == 0) {
            v.push_back({id, 1});
            continue;
        }
        printf("%d:", id);
        sort(v.begin(), v.end(), cmp);
        for (int i = 0, cnt = 0; cnt < k && i < v.size(); i++, cnt++) {
            printf(" %d", v[i]);
        }
        printf("\n");
        bool isfound = false;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].id == id) {
                v[i].cnt++;
                isfound = true;
                break;
            }
        }
        if (!isfound) v.push_back({id, 1});
    }
    return 0;
}