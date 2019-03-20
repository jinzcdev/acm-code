#include<cstdio>
#include<cstdlib>

typedef int ElementType;

typedef struct LNode {
	ElementType data;
	struct LNode *next;
}*List;

typedef struct LNode* Node;


List InitList() {
	List L = (List)malloc(sizeof(struct LNode));
	L->data = 0;
	L->next = NULL;
	// L -> e 头指针的元素值可以用来存放当前链表的长度
	return L;
}

// 此处的pos表示元素在链表中的下标 并不是
Node Find(List L, int pos) {
	if (pos < 1 || pos > L->data + 1) {
		printf("位置不合法!");
		return NULL;
	}
	List p = L;
	while (p && pos-- > 0) {
		p = p->next;
	}
	return p;
}

bool Insert(List L, ElementType e, int pos) {
	if (pos < 1 || pos > L->data + 1) {
		printf("位置不合法!");
		return false;
	}
	List p, s;
	if (pos == 1) {
		s = (List)malloc(sizeof(struct LNode));
		s->data = e;
		s->next = L->next;
		L->next = s;
		L->data++;
		return true;
	}
	p = Find(L, pos - 1);
	s = (List)malloc(sizeof(struct LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	L->data++;
	return true;
}

bool Delete(List L, int pos) {
	if (pos < 1 || pos > L->data) {
		printf("位置不合法!");
		return false;
	}

	pos--; // 只需要找到需要删除的元素的前一个元素即可, 故使寻找的长度减1
	List p = L, s;
	while (pos--) {
		p = p->next;
	}
	s = p->next;
	p->next = s->next;
	free(s);
	L->data--;
	return true;
}

void Traverse(List L) {
	List p = L->next;
	printf("This length of list is %d\n", L->data);
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}


int main() {
	List L = InitList();
	for (int i = 1; i <= 3; i++) {
		Insert(L, i, i);
	}
	Insert(L, 4, 2);
	Delete(L, 2);
	Delete(L, 1);
	Traverse(L);

	getchar();

	return 0;
}