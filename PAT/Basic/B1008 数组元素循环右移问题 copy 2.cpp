#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int n, m, a[110];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    m = m % n;
    for (int i = 0; i < (n - m) / 2; i++) swap(&a[i], &a[n - m - i - 1]);
    for (int i = n - m; i < (2 * n - m)/ 2; i++) swap(&a[i], &a[2 * n - m - i - 1]);
    for (int i = 0; i < n / 2; i++) swap(&a[i], &a[n - i - 1]);
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    return 0;
}
/*
#include <stdio.h>
int main() {
    int n, m, a[110];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    m = m % n == 0 ? n : m % n;
    for (int i = n - m; i < n; i++) {
        printf("%d", a[i]);
        if (i != n - 1) printf(" ");
    }
    for (int i = 0; i < n - m; i++) printf(" %d", a[i]);
    return 0;
}
*/
///////////////////////////////////////////////////
/*
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
typedef struct node* List;
typedef List Node;
List createList(int* arr, int len) {
    if (len == 0) return NULL;
    List head = (List)malloc(sizeof(struct node)), last = head;
    head->data = arr[0];
    last->next = head;
    for (int i = 1; i < len; i++) {
        Node p = (Node)malloc(sizeof(struct node));
        p->data = arr[i];
        p->next = last->next;
        last->next = p;
        last = p;
    }
    return head;
}
int main() {
    int n, m, a[110];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    m = m % n;
    List L = createList(a, n), p = L;
    for (int i = 0; i < n - m; i++, p = p->next);
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", p->data);
        p = p->next;
    }
    return 0;
}
*/
///////////////////////////////////////////////////
/*
#include <stdio.h>
#include <stdlib.h>
typedef struct LNode {
    int data;
    struct LNode *next;
} * LinkList, LNode;
int main() {
    int n, m, i;
    scanf("%d %d", &n, &m);
    if (n == 0) return;
    i = n;
    LinkList L = (LinkList)malloc(sizeof(LNode));
    LNode *p = L, *s;
    while (i--) {
        s = (LNode *)malloc(sizeof(LNode));
        scanf("%d", &s->data);
        p->next = s;
        s->next = L->next;
        p = s;
    }
    m = m % n;
    p = L->next;
    while (n - m++) p = p->next;
    s = p;
    while (n--) {
        printf("%d", p->data);
        p = p->next;
        if (n != 0) printf(" ");
    }
    return 0;
}
*/
///////////////////////////////////////////////////
/* 
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    m = m % n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < (n - m) / 2; i++) swap(a[i], a[n - m - i - 1]);
    for (int i = n - m; i < (2 * n - m)/ 2; i++) swap(a[i], a[2 * n - m - i - 1]);
    for (int i = 0; i < n / 2; i++) swap(a[i], a[n - i - 1]);
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    return 0;
}
*/
///////////////////////////////////////////////////
/*
#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int n, m, a[110];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    m = m % n;
    for (int i = 0; i < (n - m) / 2; i++) swap(&a[i], &a[n - m - i - 1]);
    for (int i = n - m; i < (2 * n - m)/ 2; i++) swap(&a[i], &a[2 * n - m - i - 1]);
    for (int i = 0; i < n / 2; i++) swap(&a[i], &a[n - i - 1]);
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    return 0;
}
*/