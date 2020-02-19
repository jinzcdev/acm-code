// https://pintia.cn/problem-sets/434/problems/966235055998885888
#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

ElementType Find(List L, int m);

int main() {
    List L;
    int m;
    L = Read();
    scanf("%d", &m);
    printf("%d\n", Find(L, m));
    Print(L);
    return 0;
}

/* 你的代码将被嵌在这里 */
ElementType Find(List L, int m) {
    if (!L || m <= 0) return ERROR;
    int len = 0, cnt = 0;
    for (PtrToNode p = L->Next; p != NULL; p = p->Next) len++;
    if (m > len) return ERROR;
    int pos = len - m + 1;
    PtrToNode p = L;
    while (L->Next != NULL && cnt++ != pos) p = p->Next;
    return p->Data;
}