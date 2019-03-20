#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;
const int maxn = 50;

// int in[maxn],level[maxn];
int in[] = {4,2,5,1,7,6,3},level[] = {1,2,3,4,5,6,7};

typedef struct node{
	int data;
	node* lchild;
	node* rchild;
	node(){}
	node(int _data){
		data = _data;
		lchild = NULL;
		rchild = NULL;
	}
	node(int _data,node* _lchild,node* _rchild) : 
	data(_data),lchild(_lchild),rchild(_rchild){};
}*Node;

Node create(int levelL,int levelR,int inL,int inR){
	if(inL > inR)
		return NULL;
	Node root = new node;
	int k,flag = 0;
	for(int i = levelL;i <= levelR;i++){
		for(int j = inL;j <= inR;j++){
			if(level[i] == in[j]){
				k = j;
				flag = 1;
				break;
			}
		}
		if(flag == 1)
			break;
	}
	root -> data = in[k];
	root -> lchild = create(levelL + 1,levelR,inL,k - 1);
	root -> rchild = create(levelL + 1,levelR,k + 1,inR);
	return root;
}

void PreOrderTraverse(Node node){
	if(node != NULL){
		printf("%d\n",node -> data);
		PreOrderTraverse(node -> lchild);
		PreOrderTraverse(node -> rchild);
	}
}

int main(){
	Node node = create(0,6,0,6);
	PreOrderTraverse(node);	//先序遍历以做测试
	return 0;
}
