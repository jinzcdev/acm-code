#include <bits/stdc++.h>
using namespace std;
typedef struct node {
    int data;
    node* next;
} * List;
typedef List LNode;
/**
 * 递归删除不带头结点的单链表中所有值为x的元素
 */
List removeAllX(List head, int x) {
    if (head == NULL) return NULL;
    List p = removeAllX(head->next, x);
    if (head->data == x) {
        free(head);
        return p;
    }
    head->next = p;
    return head;
}
void removeAllX2(List &head, int x) {
    if (head == NULL) return;
    if (head->data == x) {
        LNode p = head;
        head = head->next;
        free(p);
        removeAllX2(head, x);
    } else
        removeAllX2(head->next, x);
}

void printList(List& L) {
    for (LNode p = L->next; p != NULL; p = p->next) printf("%d ", p->data);
    printf("\n");
}

List create(vector<int>& a) {
    List L = new node;
    L->next = NULL;
    LNode r = L, p;
    for (auto it : a) {
        p = new node;
        p->data = it;
        p->next = NULL;
        r->next = p;
        r = p;
    }
    return L;
}

int main() {
    int n;
    // vector<int> a(n);
    // for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    vector<int> a;
    while (cin >> n, n != -1) {
        a.push_back(n);
    }
    List L = create(a);
    // printList(L->next);
    // removeAllX(L->next, 4);
    // printList(L->next);
    clock_t s, e;
    s = clock();
    removeAllX2(L->next, 2);
    e = clock();
    cout << (double)(e - s) / CLOCKS_PER_SEC;
    // printList(L);
    // free(L->next->next);
    // LNode p = L->next->next;
    // free(p);
    // for (int i = 0; i < 1; i++) {
    //     LNode newNode = new node;
    //     newNode->data = i;
    //     newNode->next = NULL;
    // }
    // cout << p->data;
    printList(L);
    return 0;
}