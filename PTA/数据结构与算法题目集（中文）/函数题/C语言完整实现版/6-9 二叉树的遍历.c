// https://pintia.cn/problem-sets/15/problems/732
#include <stdio.h>
#include <stdlib.h>
typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
    TNode(ElementType X) : Data(X), Left(NULL), Right(NULL){};
};

BinTree CreatBinTree() {
    BinTree root = new TNode('r');
    BinTree a = new TNode('a');
    BinTree b = new TNode('b');
    BinTree c = new TNode('c');
    root->Left = a;
    root->Right = b;
    a->Left = c;
    return root;
} /* 实现细节忽略 */
void InorderTraversal(BinTree BT);
void PreorderTraversal(BinTree BT);
void PostorderTraversal(BinTree BT);
void LevelorderTraversal(BinTree BT);

int main() {
    BinTree BT = CreatBinTree();
    printf("root: %c\n", BT->Data);
    printf("Inorder:");
    InorderTraversal(BT);
    printf("\n");
    printf("Preorder:");
    PreorderTraversal(BT);
    printf("\n");
    printf("Postorder:");
    PostorderTraversal(BT);
    printf("\n");
    printf("Levelorder:");
    LevelorderTraversal(BT);
    printf("\n");
    return 0;
}

void InorderTraversal(BinTree BT) {
    if (BT == NULL) return;
    InorderTraversal(BT->Left);
    printf(" %c", BT->Data);
    InorderTraversal(BT->Right);
}

void PreorderTraversal(BinTree BT) {
    if (BT == NULL) return;
    printf(" %c", BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
}

void PostorderTraversal(BinTree BT) {
    if (BT == NULL) return;
    PostorderTraversal(BT->Left);
    PostorderTraversal(BT->Right);
    printf(" %c", BT->Data);
}

void LevelorderTraversal(BinTree BT) {
    if (BT == NULL) return;
    BinTree q[100];
    int front = 0, rear = 0;
    q[rear++] = BT;
    while (front < rear) {
        BinTree now = q[front++];
        printf(" %c", now->Data);
        if (now->Left) q[rear++] = now->Left;
        if (now->Right) q[rear++] = now->Right;
    }
}