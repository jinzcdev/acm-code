// https://pintia.cn/problem-sets/15/problems/826
#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node* next;
    node(int x) : data(x) { next = NULL; }
};
void insert(node* L, int data) {
    node* newNode = new node(data);
    newNode->next = L->next;
    L->next = newNode;
}
int main() {
    int k, a;
    scanf("%d", &k);
    node* L = new node(0);
    while (scanf("%d", &a), a >= 0) {
        insert(L, a);
        L->data++;
    }
    if (k <= 0 || k > L->data) printf("NULL");
    else {
        int cnt = 0;
        node* p = L;
        while (cnt++ < k) p = p->next;
        printf("%d", p->data);
    }
    return 0;
}