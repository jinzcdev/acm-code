#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 110;
int number[maxn],N;

struct node{
    int data;
    int lchild,rchild;
}BST[maxn];

int index = 0;
void InOrderTraverse(int root){
    if(root == -1 || root > N) return;
    InOrderTraverse(BST[root].lchild);
    BST[root].data = number[index++];
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

int main(){
    scanf("%d",&N);
    int lchild,rchild;
    for (int i = 0; i < N; i++){
        scanf("%d %d",&lchild,&rchild);
        BST[i].lchild = lchild;
        BST[i].rchild = rchild;
    }
    for(int i = 0; i < N; i++){
        scanf("%d",&number[i]);
    }
    sort(number,number + N);
    InOrderTraverse(0);
    LevelOrderTravers(0);

    return 0;
}
