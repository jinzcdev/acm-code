#include <cstdio>
#include <cstring>
using namespace std;

char *pre,*in;

struct node{
	char data;
	node* lchild;
	node* rchild;
};

void postOrder(node* root){
	if(root == NULL) return;
	postOrder(root -> lchild);
	postOrder(root -> rchild);
	printf("%c",root -> data);
}

node* create(int preL,int preR,int inL,int inR){
	if(preL > preR) return NULL;
	node* root = new node;
	root -> data = pre[preL];
	int k,numLeft;
	for(int i = inL;i <= inR;i++){
		if(in[i] == pre[preL]){
			k = i;
			break;
		}
	}
	numLeft = k - inL;
	root -> lchild = create(preL + 1,preL + numLeft,inL,k - 1);
	root -> rchild = create(preL + numLeft + 1,preR,k + 1,inR);
	return root;
}

int main(){
	pre = new char;
	in = new char;
	while(scanf("%s %s",pre,in) != EOF){
		int len = strlen(pre);
		node* root = create(0,len - 1,0,len - 1);
		postOrder(root);
		printf("\n");
	}
	return 0;
}