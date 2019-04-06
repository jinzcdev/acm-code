#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
const int maxm = 1010,maxn = 10010;
int M,N,a[maxn];

vector<int> path_u,path_v;

struct node{
	int data;
	node *lchild,*rchild;	
};

node* newNode(int data){
	node* Node = new node;
	Node -> data = data;
	Node -> lchild = Node -> rchild = NULL;
	return Node;
}

void insert(node* &root,int data){
	if(root == NULL){
		root = newNode(data);
		return;
	}
	if(data < root -> data)
		insert(root -> lchild,data);
	else
		insert(root -> rchild,data);
}

node* Create(int data[],int n){
	node* root = NULL;
	for(int i = 0;i < n;i++)
		insert(root,data[i]);
	return root;
}

int findLCA(){
	int i_u = 0,i_v = 0;
	while(path_u[i_u++] == path_v[i_v++]);
	return path_u[i_u - 2];
}

//record the path from root to x.
bool search(node* root,int x,vector<int> &path){
	if(root == NULL) return false;
	path.push_back(root -> data);
	if(x < root -> data ){
		return search(root -> lchild,x,path);
	}else if(x > root -> data){
		return search(root -> rchild,x,path);
	}else{
		return true;
	}
}

int main(){
	scanf("%d%d",&M,&N);
	for (int i = 0; i < N; i++)
		scanf("%d",a + i);
	node* root = Create(a,N);
	int u,v,ancestor;
	bool rs_u,rs_v;
	for (int i = 0; i < M; i++){
		scanf("%d%d",&u,&v);
		rs_u = search(root,u,path_u);
		rs_v = search(root,v,path_v);
		if(rs_u && !rs_v) printf("ERROR: %d is not found.\n",v);
		else if(!rs_u && rs_v) printf("ERROR: %d is not found.\n",u);
		else if(!rs_u && !rs_v) printf("%d and %d are not found.\n",u,v);
		else{
			ancestor = findLCA();
			if(ancestor == u && ancestor != v)
				printf("%d is an ancestor of %d.\n",u,v);
			else if(ancestor != u && ancestor == v)
				printf("%d is an ancestor of %d.\n",v,u);
			else
				printf("LCA of %d and %d is %d\n",u,v,ancestor);
		}
		path_u.clear();
		path_v.clear();

	}
	return 0;
}