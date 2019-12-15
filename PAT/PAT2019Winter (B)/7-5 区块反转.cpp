#include <iostream>
#include <vector>
using namespace std;
struct node {
    int address, data, next;
};

int main() {
    int head, n, k, adr;
    scanf("%d%d%d", &head, &n, &k);
    vector<node> v(100000), l, ans;
    for (int i = 0; i < n; i++) {
        scanf("%d", &adr);
        scanf("%d%d", &v[adr].data, &v[adr].next);
        v[adr].address = adr;
    }
    int p = head;
    while (p != -1) {
        l.push_back(v[p]);
        p = v[p].next;
    }
    if (l.size() <= k)
        ans = l;
    else {
        int pos = l.size() - l.size() % k, left = pos - k, right = left + k - 1;
        for (int i = pos; i < l.size(); i++) ans.push_back(l[i]);
        while (left >= 0) {
            for (int i = left; i <= left + k - 1; i++) {
                ans.push_back(l[i]);
            }
            left -= k;
        }
    }
    for (int i = 0; i < ans.size() - 1; i++) {
        printf("%05d %d %05d\n", ans[i].address, ans[i].data, ans[i + 1].address);
    }
    printf("%05d %d -1\n", ans[ans.size() - 1].address, ans[ans.size() - 1].data);
    return 0;
}