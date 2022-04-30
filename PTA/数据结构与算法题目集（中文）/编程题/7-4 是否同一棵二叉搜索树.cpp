// https://pintia.cn/problem-sets/15/problems/712
#include <iostream>
// #include <cstdlib>
using namespace std;
struct node {
    int data;
    node *lchild, *rchild;
    node(int _data) {
        data = _data;
        lchild = rchild = NULL;
    };
};

void insert(node*& root, int data) {
    if (root == NULL) {
        root = new node(data);
        return;
    }
    if (root->data > data)
        insert(root->lchild, data);
    else
        insert(root->rchild, data);
}

bool judge(node* p, node* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->data != q->data) return false;
    return judge(p->lchild, q->lchild) && judge(p->rchild, q->rchild);
}

int main() {
    int n, l, temp;
    while (scanf("%d", &n), n != 0) {
        scanf("%d", &l);
        node* root = NULL;
        for (int i = 0; i < n; i++) {
            scanf("%d", &temp);
            insert(root, temp);
        }
        while (l--) {
            node* tempR = NULL;
            for (int i = 0; i < n; i++) {
                scanf("%d", &temp);
                insert(tempR, temp);
            }
            if (judge(root, tempR)) printf("Yes\n");
            else printf("No\n");
            free(tempR);
        }
        free(root);
    }
    return 0;
}