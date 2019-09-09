// https://pintia.cn/problem-sets/994805342720868352/problems/994805404939173888
#include <cstdio>
#include <algorithm>
using namespace std;
struct node {
    int data, height;
    node *lchild, *rchild;
    node(int _data, int _height){
        data =  _data;
        height = _height;
        lchild = rchild = NULL;
    }
};

int getHeight(node* root){
    if (root == NULL) return 0;
    return root -> height;
}

void updateHeight(node* root){
    root -> height = max(getHeight(root -> lchild), getHeight(root -> rchild)) + 1;
}

int getBalanceFactor(node* root){
    return getHeight(root -> lchild) - getHeight(root -> rchild);
}

void L(node* &root){
    node* temp = root -> rchild;
    root -> rchild = temp -> lchild;
    temp -> lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(node* &root){
    node* temp = root -> lchild;
    root -> lchild = temp -> rchild;
    temp -> rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(node* &root, int x){
    if (root == NULL){
        root = new node(x, 1);
        return;
    }
    if (x < root -> data){
        insert(root -> lchild, x);
        updateHeight(root);
        if (getBalanceFactor(root) == 2){
            if (getBalanceFactor(root -> lchild) == 1){
                R(root);
            } else if (getBalanceFactor(root -> lchild) == -1) {
                L(root -> lchild);
                R(root);
            }
        }
    } else {
        insert(root -> rchild, x);
        updateHeight(root);
        if (getBalanceFactor(root) == -2){
            if (getBalanceFactor(root -> rchild) == -1){
                L(root);
            } else if (getBalanceFactor(root -> rchild) == 1) {
                R(root -> rchild);
                L(root);
            }
        }
    }
}

int main(){
    int n, x;
    node* root = NULL;
    scanf("%d", &n);
    while (n--){
        scanf("%d", &x);
        insert(root, x);
    }
    printf("%d", root -> data);
    return 0;
}