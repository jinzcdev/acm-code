#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 110;
int N;

struct node{
    int data;
    int lchild,rchild = -1;
}BST[maxn];

void LevelOrderTravers(int root){
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        
    }
}

void push(queue<int> &q,int a,int b){
    if(a != -1) q.push(a);
    if(b != -1) q.push(b);
}

int main(){
    scanf("%d",&N);
    queue<int> q;
    int lchild,rchild,father;
    scanf("%d %d",&lchild,&rchild);
    BST[0].lchild = lchild;BST[0].rchild = rchild;
    push(q, lchild, rchild);
    for (int i = 0; i < N - 1; i++){
        scanf("%d %d",&lchild,&rchild);
        father = q.front();
        q.pop();
        BST[father].lchild = lchild;
        BST[father].rchild = rchild;
        push(q, lchild, rchild);
    }
    
    for (int i = 0; i < N; i++) {
        printf("%d %d\n",BST[i].lchild,BST[i].rchild);
    }
    return 0;
}
