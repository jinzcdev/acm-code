// https://pintia.cn/problem-sets/15/problems/728
#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find(List L, ElementType X);
List Insert(List L, ElementType X, Position P);
List Delete(List L, Position P);

int main() {
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if (L == ERROR) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &X);
        P = Find(L, X);
        if (P == ERROR)
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if (L == ERROR) printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if (L == ERROR)
        printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if (tmp != ERROR) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if (tmp != ERROR) printf("Wrong Answer\n");
    for (P = L; P; P = P->Next) printf("%d ", P->Data);
    return 0;
}
// int main() {
//     List L = NULL;
//     int n, temp;
//     scanf("%d", &n);
//     while (n--) {
//         scanf("%d", &temp);
//         L = Insert(L, temp, L);
//     }
//     Position p = L;
//     while (p!=NULL)
//     {
//         printf("%d ", p->Data);
//         p = p->Next;
//     }
//     return 0;
// }

Position Find(List L, ElementType X) {
    if (!L) return ERROR;
    else if (L->Data == X) return L;
    else return Find(L->Next, X);
}

List Insert(List L, ElementType X, Position P) {
    List p = (List)malloc(sizeof(struct LNode)), q = p;
    p->Next = L;
    while (p != NULL && p->Next != P) p = p->Next;
    if (p == NULL) {
        printf("Wrong Position for Insertion\n");
        return ERROR;
    } else {
        Position Node = (Position)malloc(sizeof(struct LNode));
        Node->Data = X;
        Node->Next = P;
        p->Next = Node;
    }
    Position head = q->Next;
    free(q);
    return head;
}

List Delete(List L, Position P) {
    if (L == P) {
        L = L->Next;
        free(P);
        return L;
    }
    List p = L;
    while (p != NULL && p->Next != P) p = p->Next;
    if (!p) {
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }
    Position temp = p->Next;
    p->Next = temp->Next;
    free(temp);
    return L;
}