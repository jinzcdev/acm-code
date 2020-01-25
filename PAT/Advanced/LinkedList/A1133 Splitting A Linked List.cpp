// https://pintia.cn/problem-sets/994805342720868352/problems/994805346776760320
#include <bits/stdc++.h>
using namespace std;
struct node {
    int adr, data, next;
} L[100000];
int main() {
    int head, n, k, adr;
    scanf("%d%d%d", &head, &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &adr);
        scanf("%d%d", &L[adr].data, &L[adr].next);
        L[adr].adr = adr;
    }
    vector<node> l, l1, l2;
    for (int p = head; p != -1; p = L[p].next) {
        if (L[p].data < 0) l.push_back(L[p]);
        else if (L[p].data <= k) l1.push_back(L[p]);
        else l2.push_back(L[p]);
    }
    for (auto it : l1) l.push_back(it);
    for (auto it : l2) l.push_back(it);
    for (int i = 0; i < l.size() - 1; i++)
        printf("%05d %d %05d\n", l[i].adr, l[i].data, l[i + 1].adr);
    printf("%05d %d -1\n", l[l.size() - 1].adr, l[l.size() - 1].data);
    return 0;
}