// https://pintia.cn/problem-sets/15/problems/730
#include <stdio.h>
#include <stdlib.h>

#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;
typedef enum { false, true } bool;
typedef int Position;
struct SNode {
    ElementType *Data;
    Position Top1, Top2;
    int MaxSize;
};
typedef struct SNode *Stack;

Stack CreateStack(int MaxSize);
bool Push(Stack S, ElementType X, int Tag);
ElementType Pop(Stack S, int Tag);

Operation GetOp();                 /* details omitted */
void PrintStack(Stack S, int Tag); /* details omitted */

int main() {
    int N, Tag, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while (!done) {
        switch (GetOp()) {
            case push:
                scanf("%d %d", &Tag, &X);
                if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);
                break;
            case pop:
                scanf("%d", &Tag);
                X = Pop(S, Tag);
                if (X == ERROR) printf("Stack %d is Empty!\n", Tag);
                break;
            case end:
                PrintStack(S, 1);
                PrintStack(S, 2);
                done = 1;
                break;
        }
    }
    return 0;
}

Stack CreateStack(int MaxSize) {
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(sizeof(ElementType) * MaxSize);
    S->MaxSize = MaxSize;
    S->Top1 = -1;
    S->Top2 = MaxSize;
    return S;
}
bool Push(Stack S, ElementType X, int Tag) {
    if (S->Top1 + 1 == S->Top2) {
        printf("Stack Full\n");
        return false;
    }
    if (Tag == 1)
        S->Data[++S->Top1] = X;
    else
        S->Data[--S->Top2] = X;
    return true;
}
ElementType Pop(Stack S, int Tag) {
    if ((Tag == 1 && S->Top1 == -1) || (Tag == 2 && S->Top2 == S->MaxSize)) {
        printf("Stack %d Empty\n", Tag);
        return ERROR;
    }
    int temp = (Tag == 1 ? S->Data[S->Top1--] : S->Data[S->Top2++]);
    return temp;
}

/*
Stack CreateStack(int MaxSize) {
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(sizeof(ElementType) * MaxSize);
    S->MaxSize = MaxSize;
    S->Top1 = 0;
    S->Top2 = MaxSize - 1;
    return S;
}

bool Push(Stack S, ElementType X, int Tag) {
    if (S->Top1 == S->Top2) {
        printf("Stack Full\n");
        return false;
    }
    if (Tag == 1)
        S->Data[S->Top1++] = X;
    else
        S->Data[S->Top2--] = X;
    return true;
}

ElementType Pop(Stack S, int Tag) {
    if ((Tag == 1 && S->Top1 == 0) || (Tag == 2 && S->Top2 == S->MaxSize - 1)) {
        printf("Stack %d Empty\n", Tag);
        return ERROR;
    }
    int temp = (Tag == 1 ? S->Data[--S->Top1] : S->Data[++S->Top2]);
    return temp;
}
*/