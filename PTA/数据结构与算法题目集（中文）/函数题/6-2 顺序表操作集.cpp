// https://pintia.cn/api/problem-sets/15/problems/725
List MakeEmpty() {
    List L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}

Position Find(List L, ElementType X) {
    for (int i = 0; i <= L->Last; i++)
        if (L->Data[i] == X) return i;
    return ERROR;
}

bool Insert(List L, ElementType X, Position P) {
    if (L->Last == MAXSIZE - 1) {
        printf("FULL");
        return false;
    } else if (P < 0 || P > L->Last + 1) {
        printf("ILLEGAL POSITION");
        return false;
    }
    int i;
    for (i = L->Last; i >= P; i--) {
        L->Data[i + 1] = L->Data[i];
    }
    L->Data[P] = X;
    L->Last++;
    return true;
}

bool Delete(List L, Position P) {
    if (P < 0 || P > L->Last) {
        printf("POSITION %d EMPTY", P);
        return false;
    }
    int temp = L->Data[P], i;
    for (i = P + 1; i <= L->Last; i++)
        L->Data[i - 1] = L->Data[i];
    L->Last--;
    return true;
}