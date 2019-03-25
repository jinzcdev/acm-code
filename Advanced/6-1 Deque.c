#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR 1e5
typedef enum { push, pop, inject, eject, end } Operation;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Element;
    PtrToNode Next, Last;
};
typedef struct DequeRecord *Deque;
struct DequeRecord {
    PtrToNode Front, Rear;
};
Deque CreateDeque();
int Push( ElementType X, Deque D );
ElementType Pop( Deque D ); 
int Inject( ElementType X, Deque D );
ElementType Eject( Deque D );

Operation GetOp();          /* details omitted */
void PrintDeque( Deque D ); /* details omitted */

int main()
{
    ElementType X;
    Deque D;
    int done = 0;

    D = CreateDeque();
    while (!done) {
        switch(GetOp()) {
        case push: 
            scanf("%d", &X);
            if (!Push(X, D)) printf("Memory is Full!\n");
            break;
        case pop:
            X = Pop(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case inject: 
            scanf("%d", &X);
            if (!Inject(X, D)) printf("Memory is Full!\n");
            break;
        case eject:
            X = Eject(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case end:
            PrintDeque(D);
            done = 1;
            break;
        }
    }
    return 0;
}

Deque CreateDeque(){
    PtrToNode header = (PtrToNode)malloc(sizeof(struct Node));
    header -> Next = header -> Last = NULL;
    Deque deque = (Deque)malloc(sizeof(struct DequeRecord));
    deque -> Front = deque -> Rear = header;
    return deque;
}

int Push( ElementType X, Deque D ){
    PtrToNode newNode = (PtrToNode)malloc(sizeof(struct Node));
    newNode -> Element = X;
    if(D -> Front == D -> Rear){
        D -> Front -> Next = newNode;
        newNode -> Last = D -> Front;
        newNode -> Next = NULL;
        D -> Rear = newNode;
    }else{
        newNode -> Next = D -> Front -> Next;
        D -> Front -> Next -> Last = newNode;
        newNode -> Last = D -> Front;
        D -> Front -> Next = newNode;
    }
    return 1;
}

ElementType Pop( Deque D ){
    if(D -> Front == D -> Rear) return ERROR;
    PtrToNode first = D -> Front -> Next;
    int v;
    if(D -> Front -> Next == D -> Rear){
        D -> Front -> Next = NULL;
        D -> Rear = D -> Front;
    }else{
        D -> Front -> Next = first -> Next;
        first -> Next -> Last = D -> Front;
    }
    v = first -> Element;
    free(first);
    return v;
}

int Inject( ElementType X, Deque D );
ElementType Eject( Deque D );