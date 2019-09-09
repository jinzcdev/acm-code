#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 110;
struct node {
    int data;
    int lchild, rchild;
} Node[maxn];

int in[maxn], n, index = 0;

bool cmp(int a, int b){
    return a < b;
}

void inOrder(int root){
    if (root == -1) return;
    inOrder(Node[root].lchild);
    Node[root].data = in[index++];      // 遍历过程中进行赋值以构建二叉搜索树
    inOrder(Node[root].rchild);
}

void levelTraverse(int root){
    queue<int> q;
    q.push(root);
    int cnt = 0;
    while (!q.empty()){
        int now = q.front();
        q.pop();
        printf("%d", Node[now].data);
        if (++cnt < n) printf(" ");
        if (Node[now].lchild != -1) q.push(Node[now].lchild);
        if (Node[now].rchild != -1) q.push(Node[now].rchild);
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d%d", &Node[i].lchild, &Node[i].rchild);
    }
    for (int i = 0; i < n; i++){
        scanf("%d", &in[i]);
    }
    sort(in, in + n, cmp);          // 升序该数组以获得中序序列
    inOrder(0);                     // 从根结点开始做中序遍历
    levelTraverse(0);               // 层序遍历该二叉树
    return 0;
}

/*
Sample Input:
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42

Sample Output:
58 25 82 11 38 67 45 73 42
*/