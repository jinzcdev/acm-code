// https://pintia.cn/problem-sets/994805342720868352/problems/994805345078067200
#include <bits/stdc++.h>
using namespace std;
const int N = 50010;
int pre[N], in[N], n;
int solve(int prel, int prer, int inl, int inr) {
    if (prel == prer) return pre[prel];
    int k = inl;
    while (in[k] != pre[prel]) k++;
    int numleft = k - inl;
    if (numleft != 0) return solve(prel + 1, prel + numleft, inl, k - 1);
    return solve(prel + numleft + 1, prer, k + 1, inr);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    printf("%d", solve(0, n - 1, 0, n - 1));
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
vector<int> pre, in, post;
int n;
void solve(int prel, int prer, int inl, int inr) {
    if (prel > prer) return;
    int k = inl;
    while (in[k] != pre[prel]) k++;
    int numLeft = k - inl;
    solve(prel + 1, prel + numLeft, inl, k - 1);
    solve(prel + numLeft + 1, prer, k + 1, inr);
    post.push_back(pre[prel]);
}
int main() {
    cin >> n;
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    solve(0, n - 1, 0, n - 1);
    cout << post[0];
    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *lchild, *rchild;
};
int n;
vector<int> pre, in;
int solve(node* root) {
    if (root == NULL) return -1;
    if (root->lchild == NULL && root->rchild == NULL) return root->data;
    if (root->lchild != NULL) return solve(root->lchild);
    return solve(root->rchild);
}
node* create(int preL, int preR, int inL, int inR) {
    if (inL > inR) return NULL;
    node* root = new node;
    root->data = pre[preL];
    int k = inL;
    while (in[k] != pre[preL]) k++;
    int leftNum = k - inL;
    root->lchild = create(preL + 1, preL + leftNum, inL, k - 1);
    root->rchild = create(preL + leftNum + 1, preR, k + 1, inR);
    return root;
}
int main() {
    scanf("%d", &n);
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    node* root = create(0, n - 1, 0, n - 1);
    printf("%d", solve(root));
    return 0;
}
*/