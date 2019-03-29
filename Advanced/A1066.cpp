#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
	int data;
	int height;
	node *lchild,*rchild;
};
const int maxn = 30;
int a[maxn];

int getHeight(node *root){
	if(root == NULL) return 0;
	return root -> height;
}

void updateHeight(node* root){
	root -> height = max(getHeight(root -> lchild),getHeight(root -> rchild)) + 1;
}

int getBalanceFactor(node* root){
	return getHeight(root -> lchild) - getHeight(root -> rchild);
}

node* newNode(int data){
	node* Node = new node;
	Node -> data = data;
	Node -> height = 1;
	Node -> lchild = Node -> rchild = NULL;
	return Node;
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

void insert(node* &root,int data){
	if(root == NULL){
		root = newNode(data);
		return;
	}
	if(root -> data < data){
		insert(root -> lchild,data);
		updateHeight(root);
		if(getBalanceFactor(root) == 2){
			if(getBalanceFactor(root -> lchild) == 1){
				R(root);
			}else if(getBalanceFactor(root -> lchild) == -1){
				L(root -> lchild);
				R(root);
			}
		}
	}else{
		insert(root -> rchild,data);
		updateHeight(root);
		if(getBalanceFactor(root) == -2){
			if(getBalanceFactor(root -> rchild) == -1){
				L(root);
			}else{
				R(root -> rchild);
				L(root);
			}
		}
	}
}

node* Create(int data[],int n){
	node* root = NULL;
	for(int i = 0;i < n;i++){
		insert(root,data[i]);
	}
	return root;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%d",a + i);
	}
	node* root = Create(a,n);
	printf("%d",root -> data);
	return 0;
}