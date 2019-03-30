// 02-线性结构1 两个有序链表序列的合并 （15 分)
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read(){
	int n,data;
	scanf("%d",&n);
	List L = (List)malloc(sizeof(struct Node));
	L -> Next = NULL;
	PtrToNode p = L,t;
	while(n--){
		scanf("%d",&data);
		t = (PtrToNode)malloc(sizeof(struct Node));
		t -> Data = data;
		t -> Next = p -> Next;
		p -> Next = t;
		p = t;
	}
	return L;
}

void Print( List L ){
	if(L -> Next == NULL){
		printf("NULL\n");
		return;
	}
	PtrToNode p = L -> Next;
	while(p != NULL){
		printf("%d",p -> Data);
		p = p -> Next;
		if(p != NULL) printf(" ");
	}
	printf("\n");
}

List Merge( List L1, List L2 ){
	List L = (List)malloc(sizeof(struct Node));
	PtrToNode p1 = L1 -> Next,p2 = L2 -> Next,p = L;
	while(p1 != NULL && p2 != NULL){
		if(p1 -> Data <= p2 -> Data){
			p -> Next = p1;
			p1 = p1 -> Next;
			L1 -> Next = p1;
		}else{
			p -> Next = p2;
			p2 = p2 -> Next;
			L2 -> Next = p2;
		}
		p = p -> Next;
	}
	if(p1 != NULL){
		p -> Next = p1;
		L1 -> Next = NULL;
	}else{
		p -> Next = p2;
		L2 -> Next = NULL;
	}
	return L;
}

int main()
{
	List L1, L2 ,L;
	L1 = Read();
	L2 = Read();
	L = Merge(L1, L2);
	Print(L);
	Print(L1);
	Print(L2);
	return 0;
}
