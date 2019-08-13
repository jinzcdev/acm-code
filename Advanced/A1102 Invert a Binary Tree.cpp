// https://pintia.cn/problem-sets/994805342720868352/problems/994805365537882112
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 15;
struct {
    int data;
    int lchild, rchild;
} node[maxn];

int n, cnt = 0;
bool isChild[maxn] = {false};           // 标记所有孩子结点, 未出现过即为根节点

void levelorder(int root){
    queue<int> q;
    q.push(root);
    while (!q.empty()){
        int now = q.front();
        q.pop();
        printf("%d", node[now].data);
        if (++cnt < n) printf(" ");
        if (node[now].rchild != -1) q.push(node[now].rchild);
        if (node[now].lchild != -1) q.push(node[now].lchild);
    }
    printf("\n");
}

void inorder(int root){
    if (root == -1)
        return;
    inorder(node[root].rchild);
    printf("%d", node[root].data);
    if (++cnt < n) printf(" ");
    inorder(node[root].lchild);
}

int main(){
    for (int i = 0; i < maxn; i++){
        node[i].data = i;                       // 初始化结点数据
        node[i].lchild = node[i].rchild = -1;   // 默认结点左右孩子为空 (= -1)
    }
    scanf("%d", &n);
    char lchild, rchild;
    for (int i = 0; i < n; i++){
        getchar();                              // 接收回车
        scanf("%c %c", &lchild, &rchild);
        if (lchild != '-'){
            node[i].lchild = lchild - '0';
            isChild[lchild - '0'] = true;
        }
        if (rchild != '-'){
            node[i].rchild = rchild - '0';
            isChild[rchild - '0'] = true;
        }
    }
    int root = 0;
    while (isChild[root]){  // 未标记过的结点即为根节点
        root++;
    }
    levelorder(root);
    cnt = 0;    // 计数变量重置为0
    inorder(root);
    return 0;    
}