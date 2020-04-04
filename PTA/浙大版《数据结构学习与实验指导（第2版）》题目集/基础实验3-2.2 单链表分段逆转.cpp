// https://pintia.cn/problem-sets/988034414048743424/problems/988038293285015552
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode Next;   /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

List ReadInput();       /* 裁判实现，细节不表 */
void PrintList(List L); /* 裁判实现，细节不表 */
void K_Reverse(List L, int K);

int main() {
    List L;
    int K;

    L = ReadInput();
    scanf("%d", &K);
    K_Reverse(L, K);
    PrintList(L);

    return 0;
}
void PrintList(List L) {
    for (PtrToNode p = L->Next; p != NULL; p = p->Next) {
        printf("%d ", p->Data);
    }
}
List ReadInput() {
    List L = (List)malloc(sizeof(struct Node));
    PtrToNode r = L;
    int n;
    scanf("%d", &n);
    while (n--) {
        PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next = NULL;
        r->Next = p;
        r = p;
    }
    return L;
}
int getLen(List L) {
    PtrToNode p = L->Next;
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->Next;
    }
    return len;
}
void K_Reverse(List L, int K) {
    PtrToNode p = L, q = p->Next;
    int len = getLen(L);
    while (len >= K) {
        for (int i = 0; i < K - 1; i++) {
            PtrToNode r = q->Next;
            q->Next = r->Next;
            r->Next = p->Next;
            p->Next = r;
        }
        p = q;
        q = p->Next;
        len -= K;
    }
}