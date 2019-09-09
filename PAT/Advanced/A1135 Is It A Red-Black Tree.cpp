#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int k,n;
vector<int> pre,in;

struct node{
	int data;
	bool isVisit;
	node *lchild,*rchild;	
};

node* create(int preL,int preR,int inL,int inR){
	if(inL > inR) return NULL;
	node* root = new node;
	root -> data = pre[preL];
	root -> isVisit = false;
	root -> lchild = root -> rchild = NULL;
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

// determine if the root is red.if true,return false,or not,return true.
bool judgeRoot(node* root){
	if(root -> data < 0) return false;
	return true;
}

//determine if the children of the red node are black.
bool judgeRedNode(node* p){
	if(p -> lchild != NULL && p -> lchild -> data < 0) return false;
	if(p -> rchild != NULL && p -> rchild -> data < 0) return false;
	return true;
}

bool judgeTreePreOrder(node* root){
	bool is = true;
	stack<node*> s;
	s.push(root);
	node* p;
	while(!s.empty()){
		p = s.top();s.pop();
		if(p -> data < 0 && !judgeRedNode(p)){
			is = false;
			break;
		}
		if(p -> rchild != NULL) s.push(p -> rchild);
		if(p -> lchild != NULL) s.push(p -> lchild);
	}
	free(p);
	return is;
}

bool judge(node* root){
	if(root == NULL || root -> data < 0) return false;
	bool is = true,isFirst = true;
	stack<node*> s;
	node* p = root;
	int count = 0,bns;	//the sum of black node.
	while(p != NULL || !s.empty()){
		if(p != NULL){
			// visit(p)
			// printf("%d ",p -> data);
			if(p -> data < 0 && !judgeRedNode(p)) {printf(" -- ");return false;}
			if(p -> data > 0) count++;
			s.push(p);
			p = p -> lchild;
		}else{	// have visited the leaf node.
			// count++;
			if(isFirst){
				bns = count;
				isFirst = false;
			}else if(bns != count){printf("%d -- ",s.top() -> data); return false;}
			p = s.top();
			if(p -> isVisit){
				if(p -> data > 0) count--;
				s.pop();
				p = s.top() -> rchild;
				printf("%d ------\n", p -> data);
			}else{
				p -> isVisit = true;
				p = p -> rchild;
			}
		}
	}
	return is;
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
		// if(!judgeRoot(root)) printf("NO\n");
		// else if(!judgeTreePreOrder(root)) printf("NO\n");
		// else printf("TRUE\n");
		if(judge(root)) printf("YES\n");
		else printf("NO\n");
		free(root);
		pre.clear();
		in.clear();
	}
	return 0;
}
