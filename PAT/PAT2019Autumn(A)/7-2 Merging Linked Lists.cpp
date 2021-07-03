#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct node {
    int adr, data, next;
} Node[maxn];
vector<node> l1, l2, ans;
void generateList(vector<node> &L, int head) {
    int p = head;
    while (p != -1) {
        L.push_back(Node[p]);
        p = Node[p].next;
    }
}

void printList(vector<node> L) {
    if (L.size() == 0) return;
    for (int i = 0; i < L.size() - 1; i++) {
        printf("%05d %d %05d\n", L[i].adr, L[i].data, L[i + 1].adr);
    }
    printf("%05d %d -1\n", L[L.size() - 1].adr, L[L.size() - 1].data);
}

int main() {
    int h1, h2, n, adr;
    cin >> h1 >> h2 >> n;
    for (int i = 0; i < n; i++) {
        cin >> adr;
        cin >> Node[adr].data >> Node[adr].next;
        Node[adr].adr = adr;
    }
    generateList(l1, h1);
    generateList(l2, h2);
    if (l1.size() < l2.size()) {
        swap(l1, l2);
    }
    if (l1.size() >= l2.size() * 2) {
        int cnt = 0, pos = l2.size() - 1;
        for (auto it : l1) {
            ans.push_back(it);
            if (++cnt % 2 == 0 && pos >= 0) {
                ans.push_back(l2[pos--]);
            }
        }
    }
    printList(ans);
    return 0;
}


/*
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;

struct node {
    int data, address, next;
} Node[maxn];

int reverseList(int start) {
    int head = maxn - 1;
    Node[head].next = start;
    int last = Node[head].next, p = Node[last].next;
    while (p != -1) {
        Node[last].next = Node[p].next;
        Node[p].next = Node[head].next;
        Node[head].next = p;
        p = Node[last].next;
    }
    return Node[head].next;
}

void printList(int head) {
    int p = head;
    while (p != -1) {
        printf("%05d %d ", Node[p].address, Node[p].data);
        if (Node[p].next == -1) printf("-1\n");
        else printf("%05d\n", Node[p].next);
        p = Node[p].next;
    }
}

int getLen(int head){
    int p = head, len = 0;
    while (p != -1) {
        p = Node[p].next;
        len++;
    }
    return len;
}

int main() {
    int head1, head2, n, address;
    scanf("%d%d%d", &head1, &head2, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &address);
        scanf("%d%d", &Node[address].data, &Node[address].next);
        Node[address].address = address;
    }
    int len1 = getLen(head1), len2 = getLen(head2);
    if (len1 == 0) printList(head2);
    else if (len2 == 0) printList(head1);
    else {
        int q, p;
        if (len1 >= len2 * 2) {
            p = head1;
            q = reverseList(head2);
        } else if (len2 >= 2 * len1) {
            p = head2;
            q = reverseList(head1);
        }
        int cnt = 0;
        while (p != -1 && q != -1) {
            if (++cnt == 2) {
                int temp = Node[q].next;
                Node[q].next = Node[p].next;
                Node[p].next = q;
                p = Node[p].next;
                q = temp;
                cnt = 0;
            }
            p = Node[p].next;
        }
        printList(head);
    }
    return 0;
}
*/


/*
#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
struct node {
    int adr, data, next;
} L[N];
void reverse(int head) {
    int last = L[head].next;
    while (L[last].next != -1) {
        int p = L[last].next;
        L[last].next = L[p].next;
        L[p].next = L[head].next;
        L[head].next = p;
    }
}
int getlen(int head) {
    int cnt = 0, p = L[head].next;
    while (p != -1) {
        cnt++;
        p = L[p].next;
    }
    return cnt;
}
int main() {
    int a, b, n, adr, data;
    scanf("%d%d%d", &a, &b, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &adr);
        scanf("%d%d", &L[adr].data, &L[adr].next);
        L[adr].adr = adr;
    }
    int h1 = N - 1, h2 = N - 2;
    L[h1].next = a;
    L[h2].next = b;
    if (getlen(h1) < getlen(h2)) swap(h1, h2);
    reverse(h2);
    int q = L[h2].next;
    for (int p = L[h1].next, cnt = 1; p != -1 && q != -1; p = L[p].next, cnt++) {
        if (cnt % 2 == 0) {
            int r = L[q].next;
            L[q].next = L[p].next;
            L[p].next = q;
            p = q;
            q = r;
        }
    }
    int p = L[h1].next;
    while (p != -1 && L[p].next != -1) {
        printf("%05d %d %05d\n", p, L[p].data, L[p].next);
        p = L[p].next;
    }
    printf("%05d %d -1\n", p, L[p].data);
    return 0;
}
*/