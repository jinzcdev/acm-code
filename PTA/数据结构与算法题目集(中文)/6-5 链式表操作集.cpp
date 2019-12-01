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

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}

Position Find( List L, ElementType X ) {
    int pos = 1;
    List ans = ERROR, p = L;
    while (p != NULL) {
        if (p->Data == X) {
            ans = p;
            break;
        }
        p = p->Next;
    }
    return ans;
}

List Insert( List L, ElementType X, Position P ) {
    if (L->Data == P->Data) {
        PtrToLNode Node = (PtrToLNode)malloc(sizeof(struct LNode));
        Node->Data = X;
        Node->Next = L;
        return Node;
    }
    List pre = (List) malloc(sizeof(struct LNode)), p = L;
    pre->Next = p;
    while (p != NULL && p->Data != P->Data) {
        p = p->Next;
        pre = pre->Next;
    }
    if (p == NULL) {
        printf("Wrong Position for Insertion\n");
        return ERROR;
    }
    PtrToLNode Node = (PtrToLNode)malloc(sizeof(struct LNode));
    Node->Data = X;
    Node->Next = p;
    pre->Next = Node;
    return L;
}

List Delete( List L, Position P ) {
    if (L->Data == P->Data) {
        List p = L->Next;
        free(L);
        return p;
    }
    List pre = (List) malloc(sizeof(struct LNode)), p = L;
    pre->Next = p;
    while (p != NULL && p->Data != P->Data) {
        p = p->Next;
        pre = pre->Next;
    }
    if (p == NULL) {
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }
    pre->Next = p->Next;
    free(p);
    return L;
}