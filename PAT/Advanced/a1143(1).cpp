#include <cstdio>
#include <vector>
#include <map>
using namespace std;

map<int,bool> mp;

int main(){
	int m,n,u,v,t;
	scanf("%d%d",&m,&n);
	vector<int> pre(n);
	for (int i = 0; i < n; i++){
		scanf("%d",&pre[i]);
		mp[pre[i]] = true;
	}
	for (int i = 0; i < m; i++){
		scanf("%d%d",&u,&v);
		for (int j = 0; j < n; j++){
			t = pre[j];
			if((u <= t && t <= v) || (v <= t && t <= u)) break;
		}
		if(!mp[u] && !mp[v]) printf("ERROR: %d and %d are not found.\n",u,v);
		else if(!mp[u] && mp[v]) printf("ERROR: %d is not found.\n",u);
		else if(mp[u] && !mp[v]) printf("ERROR: %d is not found.\n",v);
		else if(u == t || v == t) printf("%d is an ancestor of %d.\n",t,u == t ? v : u);
		else printf("LCA of %d and %d is %d.\n",u,v,t);
	}
	return 0;
}