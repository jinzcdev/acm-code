// https://pintia.cn/api/problem-sets/15/problems/731
int GetHeight(BinTree BT) {
    if (BT == NULL) return 0;
    int hl = GetHeight(BT->Left), hr = GetHeight(BT->Right);
    return (hl > hr ? hl : hr) + 1;
}