// https://pintia.cn/problem-sets/994805342720868352/problems/994805346063728640
#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *lc, *rc;
    node(int x) {
        data = x;
        lc = rc = NULL;
    }
};

void insert(node*& root, int x) {
    if (root == NULL) {
        root = new node(x);
        return;
    } else if (abs(root->data) > abs(x)) {
        insert(root->lc, x);
    } else {
        insert(root->rc, x);
    }
}

bool flag1, flag2;
int cntBN = -1;
void judge(node* root, int cnt) {
    if (root == NULL) {
        if (cntBN == -1) cntBN = cnt;
        else if (cntBN != cnt) flag2 = false;
        return;
    }
    if (root->data < 0) {
        if ((root->lc != NULL && root->lc->data < 0) ||
            (root->rc != NULL && root->rc->data < 0)) {
            flag1 = false;
        }
    }
    judge(root->lc, root->data > 0 ? cnt + 1 : cnt);
    judge(root->rc, root->data > 0 ? cnt + 1 : cnt);
}

int main() {
    int k, n, temp;
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &n);
        node* root = NULL;
        flag1 = flag2 = true;
        cntBN = -1;
        while (n--) {
            scanf("%d", &temp);
            insert(root, temp);
        }
        if (root->data < 0) {
            printf("No\n");
        } else {
            judge(root, 0);
            if (flag1 && flag2) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}

/*
bool judge1(node* root) {
    if (root == NULL) return true;
    if (root->data < 0 && ((root->lc != NULL && root->lc->data < 0) ||
                           (root->rc != NULL && root->rc->data < 0)))
        return false;
    return judge1(root->lc) && judge1(root->rc);
}*/