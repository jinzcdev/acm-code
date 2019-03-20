#include <cstdio>
#include <cstdlib>

#define MAXSIZE 10
#define ERROR -1

typedef int ElementType;
typedef int Position;
typedef struct LNode
{
	ElementType Data[MAXSIZE];
	Position Last;
}*List;

List InitList() {
	List L;
	L = (List)malloc(sizeof(struct LNode));
	L->Last = -1;
	return L;
}


// 这里的pos表示元素在顺序表中的下标 并非位序.
bool Insert(List L, ElementType e, Position pos) {
	if (L->Last == MAXSIZE - 1) {
		printf("表满\n");
		return false;
	}
	if (pos < 0 || pos > L->Last + 1) {
		printf("位置错误\n");
		return false;
	}
	// 既然是下标 那么从该位置下标都最后一个元素的下标都要做移动,故开始位置为pos
	for (int i = L->Last; i >= pos; i--) {
		L->Data[i + 1] = L->Data[i];
	}
	L->Data[pos] = e;
	L->Last++;
}

bool Delete(List L, Position pos) {
	if (pos < 0 || pos > L->Last) {
		printf("位置不合法!\n");
		return false;
	}
	// 选择循环范围只需考虑位置变动的元素范围即可.
	for (int i = pos + 1; i <= L->Last; i++) {
		L->Data[i - 1] = L->Data[i];
	}
	L->Last--;
	return true;
}

Position find(List L, ElementType e) {
	Position i = 0;
	while (i <= L->Last && L->Data[i] != e)
		i++;
	if (i > L->Last)
		return ERROR;
	else
		return i;

}

void Traverse(List L) {
	for (int i = 0; i <= L->Last; ++i)
	{
		printf("%d ", L->Data[i]);
	}
	printf("\n");
}


int main() {
	List L = InitList();
	for (int i = 0; i < 5; ++i)
		Insert(L, i, i);

	Traverse(L);
	Insert(L, 99, 2);
	Traverse(L);
	printf("%d\n",find(L, 3));
	Delete(L, 2);
	Traverse(L);
	getchar();
	return 0;
}