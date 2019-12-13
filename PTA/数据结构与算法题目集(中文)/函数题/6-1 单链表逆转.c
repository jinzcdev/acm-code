// https://pintia.cn/problem-sets/15/problems/724
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

List Reverse(List L);

int main() {
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

List Read() {
    int n, temp;
    scanf("%d", &n);
    List head = (List)malloc(sizeof(struct Node));
    head->Next = NULL;
    PtrToNode p = head;
    while (n--) {
        scanf("%d", &temp);
        PtrToNode q = (PtrToNode)malloc(sizeof(struct Node));
        q->Data = temp;
        q->Next = NULL;
        p->Next = q;
        p = p->Next;
    }
    List L = head->Next;
    free(head);
    return L;
}

void Print(List L) {
    PtrToNode p = L;
    int i = 0;
    while (p != NULL && i++ < 10) {
        printf("%d ", p->Data);
        p = p->Next;
    }
    printf("\n");
}

List Reverse(List L) {
    if (!L || L->Next == NULL) return L;
    List nextNode = L->Next;
    List head = Reverse(nextNode);
    L->Next = NULL;
    nextNode->Next = L;
    return head;
}

/*
List Reverse(List L) {
    if (L == NULL || L->Next == NULL) return L;
    List head = Reverse(L->Next);
    head->Next->Next = head;
    head->Next = NULL;
    return head;
}

List Reverse(List L) {
    if (L == NULL || L->Next == NULL) return L;
    List head = (List)malloc(sizeof(struct Node));
    head->Next = L;
    List last = L, p = last->Next;
    while (p != NULL) {
        last->Next = p->Next;
        p->Next = head->Next;
        head->Next = p;
        p = last->Next;
    }
    return head->Next;
}
*/