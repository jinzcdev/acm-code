// https://pintia.cn/problem-sets/994805342720868352/problems/994805380754817024
#include <bits/stdc++.h>
using namespace std;
vector<int> pre, in;
int n, cnt = 0;
void postOrder(int prel, int prer, int inl, int inr) {
    if (prel > prer) return;
    int k = inl;
    while (pre[prel] != in[k]) k++;
    int numleft = k - inl;
    postOrder(prel + 1, prel + numleft, inl, k - 1);
    postOrder(prel + numleft + 1, prer, k + 1, inr);
    printf("%d", pre[prel]);
    if (++cnt < n) printf(" ");
}
int main() {
    char op[5];
    int x;
    stack<int> s;
    scanf("%d", &n);
    for (int i = 0; i < n * 2; i++) {
        scanf("%s", op);
        if (op[1] == 'u') {
            scanf("%d", &x);
            s.push(x);
            pre.push_back(x);
        } else {
            in.push_back(s.top());
            s.pop();
        }
    }
    postOrder(0, n - 1, 0, n - 1);
    return 0;
}


/*
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int maxn = 40;
struct node {
    int data;
    node* lchild, rchild;
};
int n, pre[maxn], in[maxn];

node* create(int preL, int preR, int inL, int inR) {
    if (preL > preR) return NULL;
    node* root = new node;
    root->data = pre[preL];
    int k = inL;
    while (in[k] != pre[preL]) k++;
    int numLeft = k - inL;
    root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
    root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
    return root;
}

int cnt = 0;
void postOrder(node* root) {
    if (root == NULL) return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%d", root->data);
    if (++cnt < n) printf(" ");
}

int main() {
    scanf("%d", &n);
    stack<int> s;
    char str[5];
    int x, preIndex = 0, postIndex = 0;
    for (int i = 0; i < n * 2; i++) {
        scanf("%s", str);
        if (strcmp(str, "Push") == 0) {  // 进栈顺序即为先序序列
            scanf("%d", &x);
            pre[preIndex++] = x;
            s.push(x);
        } else {
            in[postIndex++] = s.top();  // 出栈顺序即为中序序列
            s.pop();
        }
    }
    node* root = create(0, n - 1, 0, n - 1);
    postOrder(root);
    return 0;
}
*/