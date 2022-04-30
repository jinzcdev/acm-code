// https://pintia.cn/problem-sets/994805342720868352/problems/994805460652113920
#include <bits/stdc++.h>
using namespace std;
struct node {
    int adr, next;
    char data;
    bool flag;
} L[100010];
int main() {
    int head1, head2, n, adr;
    scanf("%d%d%d", &head1, &head2, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d ", &adr);
        scanf("%c%d", &L[adr].data, &L[adr].next);
        L[adr].adr = adr;
    }
    for (int p = head1; p != -1; p = L[p].next) L[p].flag = true;
    for (int p = head2; p != -1; p = L[p].next) {
        if (L[p].flag == true) {
            printf("%05d", p);
            return 0;
        }
    }
    printf("-1");
    return 0;
}



/*#include <bits/stdc++.h>
using namespace std;
struct node {
    int adr, next;
    char data;
} L[100000];
int main() {
    int h1, h2, n, adr;
    scanf("%d%d%d", &h1, &h2, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d ", &adr);
        scanf("%c%d", &L[adr].data, &L[adr].next);
        L[adr].adr = adr;
    }
    vector<node> l1, l2;
    for (int p = h1; p != -1; p = L[p].next) l1.push_back(L[p]);
    for (int p = h2; p != -1; p = L[p].next) l2.push_back(L[p]);
    reverse(l1.begin(), l1.end());
    reverse(l2.begin(), l2.end());
    int i = 0, flag = 0;
    while (i < l1.size() && i < l2.size() && l1[i].adr == l2[i].adr) {
        i++;
        flag = 1;
    }
    if (flag) printf("%05d", l1[i - 1].adr);
    else printf("-1");
    return 0;
}
*/