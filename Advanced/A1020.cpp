#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 30;
int n,in[maxn],post[maxn];

struct node{
	int data;
	node* lchild;
	node* rchild;
};

node* create(int postL,int postR,int inL,int inR){
	if(postL > postR) return NULL;
	node* root = new node;
	root -> data = post[postR];
	int k;
	for (k = inL; k <= inR; ++k){
		if(in[k] == post[postR])
			break;
	}
	int numLeft = k - inL;
	root -> lchild = create(postL,postL + numLeft - 1,inL,k - 1);
	root -> rchild = create(postL + numLeft,postR - 1,k + 1,inR);
	return root;
}

void BFS(node* root){
	queue<node *> q;
	q.push(root);
	int num = 0;
	while(!q.empty()){
		node* node = q.front();
		q.pop();
		printf("%d",node -> data);
		if(num++ < n - 1) printf(" ");
		if(node -> lchild != NULL) q.push(node -> lchild);
		if(node -> rchild != NULL) q.push(node -> rchild);
	}
}
int main(){
	scanf("%d",&n);
	for (int i = 0; i < n; ++i){
		scanf("%d",&post[i]);
	}
	for (int i = 0; i < n; ++i){
		scanf("%d",&in[i]);
	}
	node* root = create(0,n-1,0,n-1);
	BFS(root);
	return 0;
}