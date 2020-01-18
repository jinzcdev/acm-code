// https://pintia.cn/problem-sets/16/problems/701
#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10 /* maximum number of nodes in a tree */
typedef int ElementType;

typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree Left;
    Tree Right;
};

Tree BuildTree(); /* details omitted */
void PrintNode(Tree NodePtr) { printf(" %d", NodePtr->Element); }

void Level_order(Tree T, void (*visit)(Tree ThisNode));

int main() {
    Tree T = BuildTree();
    printf("Level-order:");
    Level_order(T, PrintNode);
    return 0;
}

/* Your function will be put here */
void Level_order(Tree T, void (*visit)(Tree ThisNode)) {
    if (T == NULL) return;
    Tree q[1000];
    int left = 0, right = 1;
    q[left] = T;
    while (left < right) {
        Tree now = q[left++];
        visit(now);
        if (now->Left != NULL) q[right++] = now->Left;
        if (now->Right != NULL) q[right++] = now->Right;
    }
}