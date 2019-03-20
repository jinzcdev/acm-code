#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 110;
int number[maxn],N;

struct node{
    int data;
    int lchild,rchild = -1;
}BST[maxn];

int index = 0;
void InOrderTraverse(int root){
    if(root == -1 || root > N) return;
    InOrderTraverse(BST[root].lchild);
    BST[root].data = number[index++];
    printf("index: %d  %d\n",root,BST[root].data);
    InOrderTraverse(BST[root].rchild);
}

void LevelOrderTravers(int root){
    queue<int> q;
    q.push(root);
    int i = 0;
    while (!q.empty()) {
        int now = q.front();
        printf("%d",BST[now].data);
        if(++i < N) printf(" ");
        q.pop();
        if(BST[now].lchild != -1) q.push(BST[now].lchild);
        if(BST[now].rchild != -1) q.push(BST[now].rchild);
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
    for(int i = 0; i < N; i++){
        scanf("%d",&number[i]);
    }
    sort(number,number + N);
    InOrderTraverse(0);
    LevelOrderTravers(0);

    // for (int i = 0; i < N; i++) {
    //     printf("%d %d\n",BST[i].lchild,BST[i].rchild);
    // }
    return 0;
}
