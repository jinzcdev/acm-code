#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
    ElementType Element;
    Position Next;
};

List Read(); /* details omitted */
void Print( List L ); /* details omitted */
List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

List Reverse( List L ){
  if(L -> Next == NULL) return L;
  Position t,p = L -> Next -> Next,k = L -> Next;
  while(p != NULL){
    t = p;
    p = p -> Next;
    k -> Next = p;
    t -> Next = L -> Next;
    L -> Next = t;
  }
  return L;
}