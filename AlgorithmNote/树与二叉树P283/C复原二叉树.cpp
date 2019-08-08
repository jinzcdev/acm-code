// http://codeup.cn/problem.php?cid=100000611&pid=0
#include <cstdio>
#include <cstring>
const int maxn = 1010;
struct node {
    char data;
    node* lchild;
    node* rchild;
};

char pre[maxn], in[maxn];
node* create(int preL, int preR, int inL, int inR){
    if (preL > preR){
        return NULL;
    }
    node* root = new node;
    root -> data = pre[preL];
    int k = inL;
    while(in[k] != pre[preL])
    	k++;
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
    int len;
    while (scanf("%s %s", pre, in) != EOF){
        len = strlen(pre); 
        postOrder(create(0, len - 1, 0, len - 1));
        printf("\n");
    }
    return 0;
}

/*
DBACEGF ABCDEFG
BCAD CBAD
*/