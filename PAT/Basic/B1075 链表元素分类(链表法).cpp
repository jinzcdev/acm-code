// https://pintia.cn/problem-sets/994805260223102976/problems/994805262953594880
#include <cstdio>
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
    int p = h1, r = h2, s = h3; // p遍历原链表用, r和s分别为l2, l3的尾结点, 用于实现尾插法
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