#include <cstdio>
#include <map>
using namespace std;

const int maxn = 10010;
int n,k;
map<int,bool> flag;

struct node{
	int data,next;
}L[maxn];

void Reverse(int header,int len){
	int p = L[L[header.next]].next,i = 0;
	while(flag[p] && i < len - 1){
		

