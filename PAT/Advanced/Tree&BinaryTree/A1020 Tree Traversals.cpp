// https://pintia.cn/problem-sets/9948053427208 68352/problems/994805485033603072
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 40;
struct node {
    int data;
    node* lchild;
    node* rchild;
};
int n, post[maxn], in[maxn];

void levelorder(node* root){
    queue<node*> q;
    q.push(root);
    int cnt = 0;
    while (!q.empty()){
        node* now = q.front();
        q.pop();
        printf("%d", now -> data);
        if (++cnt < n) printf(" ");
        if (now -> lchild != NULL) q.push(now -> lchild);
        if (now -> rchild != NULL) q.push(now -> rchild);
    }
}

node* create(int postL, int postR, int inL, int inR){
    if (postL > postR)
        return NULL;
    node* root = new node;
    root -> data = post[postR];
    int k = inL;
    while (in[k] != post[postR]){
        k++;
    }
    int numLeft = k - inL;
    root -> lchild = create(postL, postL + numLeft - 1, inL, k - 1);
    root -> rchild = create(postL + numLeft, postR - 1, k + 1, inR);
    return root;
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n; i++){
        scanf("%d", &in[i]);
    }
    node* root = create(0, n - 1, 0, n - 1);
    levelorder(root);
    return 0;
}