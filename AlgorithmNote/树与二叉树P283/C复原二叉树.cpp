// http://codeup.cn/problem.php?cid=100000611&pid=0
#include <cstdio>
const int maxn = 1010;
struct node {
    char data;
    node* lchild;
    node* rchild;
};

node* newNode(int data){
    node* Node = new node;
    Node -> data = data;
    Node -> lchild = Node -> rchild = NULL;
    return Node;
}

void insert(node* &root, int x){
    if (root == NULL){
        root = newNode(x);
        return;
    }
    if (x < root -> data){
        insert(root -> lchild, x);
    } else {
        insert(root -> rchild, x);
    }
}

char pre[maxn], in[maxn];
node* create(int preL, int preR, int inL, int inR){
    if (preL > preR){
        return NULL;
    }
    node* root = new node;
    root -> data = pre[preL];
    int k;
    for (int i = inL; i <= inR; i++){
        if (in[k] == pre[preL]){
            break;
        }
    }
    int numLeft = k - inL;
    root -> lchild = create(preL + 1, preL + numLeft, inL, k - 1);
    root -> rchild = create(preL + numLeft + 1, preR, k + 1, inR);
    return root;
}

void postOrder(node* root){
    if(root == NULL){
        return;
    }
    postOrder(root -> lchild);
    postOrder(root -> rchild);
    printf("%c", root -> data);
}

int main(){
    node* root;
    while (scanf("%s %s", pre, in) != EOF){
        root = create(0, 0, 0, 0);
        postOrder(root);
        printf("\n");
    }
    return 0;
}