// https://pintia.cn/problem-sets/994805342720868352/problems/994805440976633856
#include <cstdio>
#include <vector>
using namespace std;
struct node {
    int data;
    node *lchild, *rchild;
};

void insert(node* &root, int x){        // 此处root必须为引用类型
    if (root == NULL){
        root = new node;
        root -> data = x;
        root -> lchild = root -> rchild = NULL;
        return;
    }
    if (x < root -> data) insert(root -> lchild, x);
    else insert(root -> rchild, x);
}

vector<int> origin, pre, preMirror;     // 保存初始序列, 先序序列和镜像先序序列
void preOrder(node* root){
    if (root == NULL)
        return;
    pre.push_back(root -> data);
    preOrder(root -> lchild);
    preOrder(root -> rchild);
}

void preOrderMirror(node* root){
    if (root == NULL)
        return;
    preMirror.push_back(root -> data);
    preOrderMirror(root -> rchild);
    preOrderMirror(root -> lchild);
}

int cnt = 0, isMirror = false;
void postOrder(node* root){
    if (root == NULL)
        return;
    if (!isMirror){                     // isMirror标志位判断是否为镜像二叉树
        postOrder(root -> lchild);
        postOrder(root -> rchild);
    } else {
        postOrder(root -> rchild);
        postOrder(root -> lchild);
    }
    printf("%d", root -> data);
    if (++cnt < origin.size()) printf(" ");
}

int main(){
    int n, x;
    node* root = NULL;          // 构建空二叉树
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        origin.push_back(x);
        insert(root, x);        // 插入结点
    }
    preOrder(root);             // 分别获得先序序列和镜像先序序列
    preOrderMirror(root);
    if (pre == origin){
        printf("YES\n");
        postOrder(root);
    } else if (preMirror == origin) {
        isMirror = true;        // 设置isMirror标志位为true
        printf("YES\n");
        postOrder(root);
    } else {
        printf("NO\n");
    }
    return 0;
}