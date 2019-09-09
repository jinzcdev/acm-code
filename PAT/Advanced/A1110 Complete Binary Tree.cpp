#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int maxn = 30;
struct node{
	int lchild,rchild;
}CBT[maxn];

int N,root,last = 2;
bool flag[maxn] = {false},isCBT = true;

void BFS(int _root){
	queue<int> q;
	q.push(_root);
	int count = 0,k = -1,now;
	while(!q.empty() && count++ < N){
		now = q.front();
		q.pop();
		if(now == -1) isCBT = false;
		q.push(CBT[now].lchild);
		q.push(CBT[now].rchild);
	}
	last = now;
}

int convertInteger(string s){
	if(s == "-") return -1;
	if(s.length() == 1){
		return s[0] - '0';
	}else{
		return (s[0] - '0') * 10 + (s[1] - '0');
	}
}

int getRoot(){
	int i = 0;
	while(flag[i] && i < N)
		i++;
	return i;
}

int main(){
	scanf("%d",&N);
	string ls,rs;
	int lchild,rchild,temp,root;
	for (int i = 0; i < N; i++){
		cin >> ls;cin >> rs;
		lchild = convertInteger(ls);
		rchild = convertInteger(rs);
		CBT[i].lchild = lchild;
		CBT[i].rchild = rchild;
		if(lchild != -1) flag[lchild] = true;
		if(rchild != -1) flag[rchild] = true;
	}
	root = getRoot();
	BFS(root);
	if(!isCBT)
		cout << "NO " << root;
	else{
		cout << "YES " << last;
	}
	return 0;
}