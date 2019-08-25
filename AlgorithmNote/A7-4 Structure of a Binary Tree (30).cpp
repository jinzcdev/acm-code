#include <iostream>
#include <string>
using namespace std;
const int maxn = 35;
struct node {
    int parent, data;
    node *lchild, *rchild;
    node (int _data) {
        data = _data;
        lchild = rchild = NULL;
    }
};
int n, m;
int post[maxn], in[maxn];
node* create(int postL, int postR, int inL, int inR){
    if (postL > postR) return;
    node* root = new node(post[postR]);
    int k = inL;
    while (in[k] != post[postR])
        k++;
    int numLeft = k - inL;
    root->lchild = create(postL, postL + numLeft - 1, postL, k - 1);
    root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
    root->lchild->parent = root->rchild->parent = post[postR];
    return root;
}

bool isRoot(int data) {
    return data == post[n - 1];
}

bool isBro(int a, int b) {
    
}


