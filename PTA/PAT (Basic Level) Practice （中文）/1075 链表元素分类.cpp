// https://pintia.cn/problem-sets/994805260223102976/problems/994805262953594880
#include <stdio.h>
const int N = 100010;
struct {
    int adr, data, next;
} L[N];
int main() {
    int head, n, k, adr;
    scanf("%d%d%d", &head, &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &adr);
        scanf("%d%d", &L[adr].data, &L[adr].next);
        L[adr].adr = adr;
    }
    int h1 = N - 1, h2 = N - 2, h3 = N - 3;  // h2存负数, h1存[0, k], h3存大于k (添加头指针, 便于操作)
    L[h1].next = head;
    L[h2].next = L[h3].next = -1;
    int p = h1, r = h2, s = h3, cnt = 0;
    while (L[p].next != -1) {
        int q = L[p].next;
        if (L[q].data >= 0 && L[q].data <= k) {
            p = q;
            continue;
        }
        if (L[q].data < 0) {
            L[r].next = q;
            r = q;
        } else if (L[q].data > k) {
            L[s].next = q;
            s = q;
        }
        L[p].next = L[q].next;
    }
    L[s].next = -1;  // 最末尾的链表最后一个元素后继置为NULL
    L[p].next = L[h3].next;  // 链表1后接上链表3
    L[r].next = L[h1].next;  // 链表2后接上链表1
    for (p = L[h2].next; L[p].next != -1; p = L[p].next)
        printf("%05d %d %05d\n", p, L[p].data, L[p].next);
    printf("%05d %d -1\n", p, L[p].data);
    return 0;
}

/*
// https://pintia.cn/problem-sets/994805260223102976/problems/994805262953594880
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100010, sortNum = 3;
struct node {
    int address, data, next;
} L[maxn];
int main() {
    vector<int> v[sortNum];  // 分别存放负数, [0,k]之间的数, 大于k的数
    int begin, n, k;
    scanf("%d%d%d", &begin, &n, &k);
    for (int i = 0; i < n; i++) {
        int address;
        scanf("%d", &address);
        scanf("%d%d", &L[address].data, &L[address].next);
        L[address].address = address;
    }
    int p = begin;
    while (p != -1) {  // 遍历链表将3类结点地址分别存入对应的vector
        if (L[p].data < 0) v[0].push_back(p);
        else if (L[p].data <= k) v[1].push_back(p);
        else v[2].push_back(p);
        p = L[p].next;
    }

    bool flag = false;
    for (int i = 0; i < sortNum; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (!flag) {
                printf("%05d %d ", v[i][j], L[v[i][j]].data);
                flag = true;
            } else {
                printf("%05d\n%05d %d ", v[i][j], v[i][j], L[v[i][j]].data);
            }
        }
    }
    printf("-1");
    return 0;
}
*/
/*
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
*/