// https://pintia.cn/problem-sets/994805342720868352/problems/994805343463260160
#include <cstdio>
const int maxn = 100010;
int main(){
	int n;
	bool ans[maxn] = {false};
	scanf("%d", &n);
	int temp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		if (temp > 0 && temp <= 100000){
			ans[temp] = true;
		}
	}
	int i = 0;
	while (ans[++i]);
	printf("%d", i);
	return 0;
}