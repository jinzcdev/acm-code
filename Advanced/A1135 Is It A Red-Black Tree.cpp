#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;


int k,n;
vector<int> pre,in;

struct node{
	int data,color;
	node *lchild,*rchild;	
};

node* create(int preL,int preR,int inL,int inR){
	if(inL > inR) return NULL;
	node* root = new node;
	root -> data = pre[preL];
	if(root -> data > 0) root -> color = 0; //black
	else root -> color = -1;		//red
	int k;
	for(int i = inL;i <= inR;i++){
		if(pre[preL] == in[i]){
			k = i;
			break;
		}
	}
	int leftNum = k - inL;
	root -> lchild = create(preL + 1,preL + leftNum,inL,k - 1);
	root -> rchild = create(preL + leftNum + 1,preR,k + 1,inR);
	return root;
}

bool cmp(int a,int b){
	return abs(a) < abs(b);
}

void post(node* root){
	if(root != NULL){
		post(root->lchild);
		post(root->rchild);
		printf("%d  ", root ->data);
	}
}

void isRedBlackTree(node* root){
	if(root -> color == -1 ){
		printf("NO\n");
		return;
	}

}


bool judge1(node* root){
	if(root != NULL){

	}
}

int main(){
	int t;
	scanf("%d",&k);
	for(int i = 0;i < k;i++){
		scanf("%d",&n);
		for(int j = 0;j < n;j++){
			scanf("%d",&t);
			pre.push_back(t);
			in.push_back(t);
		}
		sort(in.begin(),in.end(),cmp);
		node* root = create(0,n - 1,0,n - 1);
		isRedBlackTree(root);
		free(root);
		pre.clear();
		in.clear();
	}
	return 0;
}