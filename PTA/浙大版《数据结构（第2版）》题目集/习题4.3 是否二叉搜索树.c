// https://pintia.cn/problem-sets/434/problems/6178
#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree BuildTree(); /* 由裁判实现，细节不表 */
bool IsBST(BinTree T);

int main() {
    BinTree T;

    T = BuildTree();
    if (IsBST(T))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
/* 你的代码将被嵌在这里 */
bool isValidBST(BinTree T, int low, int high) {
    if (T == NULL) return true;
    if (T->Data <= low || T->Data >= high) return false;
    return isValidBST(T->Left, low, T->Data) &&
           isValidBST(T->Right, T->Data, high);
}
bool IsBST(BinTree T) { return isValidBST(T, -1, 0x7FFFFFFF); }

bool isValidBST2(BinTree root) {
    if (root == NULL) return true;
    if (!isValidBST2(root->Left)) return false;
    BinTree p = root->Left;
    if (p) {
        while (p->Right) p = p->Right;
        if (root->Data <= p->Data) return false;
    }
    p = root->Right;
    if (p != NULL) {
        while (p->Left != NULL) p = p->Left;
        if (root->Data >= p->Data) return false;
    }
    if (!isValidBST2(root->Right)) return false;
    else return true;
}