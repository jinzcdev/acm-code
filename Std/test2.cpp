#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<int> data,pre,pre_mirror;

struct node{
	int data;
	node* lchild;
	node* rchild;
};

void PreOrderTraverse(node* root){
	if(root != NULL){
		pre.push_back(root -> data);
		PreOrderTraverse(root -> lchild);
		PreOrderTraverse(root -> rchild);
	}
}

void PreOrderTraverseMirror(node* root){
	if(root != NULL){
		pre_mirror.push_back(root -> data);
		PreOrderTraverseMirror(root -> rchild);
		PreOrderTraverseMirror(root -> lchild);
	}
}

bool judge(vector<int> v1,vector<int> v2){
	int rs = true;
	for (int i = 0; i < N; i++){
		if(v1[i] != v2[i]){
			rs = false;
			break;
		}
	}
	return rs;
}

node* newNode(int x){
	node* Node = new node;
	Node -> data = x;
	Node -> lchild = Node -> rchild = NULL;
	return Node;
}

void insert(node* &root,int x){
	if(root == NULL){
		root = newNode(x);
		return;
	}
	if(x < root -> data){
		insert(root -> lchild,x);
	}else{
		insert(root -> rchild,x);
	}
}

node* createBFS(vector<int> v,int n){
	node* root = NULL;
	for (int i = 0; i < n; i++)
		insert(root,v[i]);
	return root;
}

int i = 0;
void PostOrderTraverse(node* root){
	if(root != NULL){
		PostOrderTraverse(root -> lchild);
		PostOrderTraverse(root -> rchild);
		printf("%d", root -> data);
		if(++i < N) printf(" ");
	}
}
void PostOrderTraverseMirror(node* root){
	if(root != NULL){
		PostOrderTraverse(root -> rchild);
		PostOrderTraverse(root -> lchild);
		printf("%d", root -> data);
		if(++i < N) printf(" ");
	}
}

void tra(vector<int> v){
	for(vector<int>::iterator it = v.begin();it < v.end();it++){
		printf("%d ",*it);
	}
}

int main(){
	scanf("%d",&N);
	int temp;
	for (int i = 0; i < N; i++){
		scanf("%d",&temp);
		data.push_back(temp);
	}
	node* root = createBFS(data,N);
	PreOrderTraverse(root);
	PreOrderTraverseMirror(root);

	if(judge(data,pre)){
		printf("YES\n");
		PostOrderTraverse(root);
	}else if(judge(data,pre_mirror)){
		printf("YES\n");
		PostOrderTraverseMirror(root);
	}else{
		printf("NO");
	}
	return 0;
}