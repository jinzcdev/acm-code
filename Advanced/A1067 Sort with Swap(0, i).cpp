#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int n;
vector<int> data;
int pos[maxn];

int findError(int ie){
	int i = ie + 1;
	while(i < n && data[i] == i) i++;
	if(i == n) return -1;	//the array is ordered
	return i;
}

int main(){
	int t;
	scanf("%d",&n);
	for(int i = 0 ; i < n ;i++){
		scanf("%d",&t);
		data.push_back(t);
		pos[t] = i;
	}

	int i_z = pos[0],step = 0,i_e = 0;
	do{
		if(i_z == 0){
			i_e = findError(i_e);
			if(i_e == -1) break;
			else {
				swap(data[i_z],data[i_e]);
				pos[data[i_z]] = 0;
				i_z = i_e;
				step++;
			}
		}else{
			swap(data[i_z],data[pos[i_z]]);
			i_z = pos[i_z];
			step++;
		}
	}while(true);
	printf("%d\n",step);

	return 0;
}