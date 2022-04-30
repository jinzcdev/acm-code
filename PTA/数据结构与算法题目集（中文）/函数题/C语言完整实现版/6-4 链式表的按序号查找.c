// https://pintia.cn/problem-sets/15/problems/727
#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

ElementType FindKth(List L, int K);

int main() {
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if (X != ERROR)
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}

ElementType FindKth(List L, int K) {
    if (K < 1) return ERROR;
    int cnt = 0;
    List p = L;
    while (p != NULL && ++cnt < K) p = p->Next;
    if (cnt != K) return ERROR;
    return p->Data;
}