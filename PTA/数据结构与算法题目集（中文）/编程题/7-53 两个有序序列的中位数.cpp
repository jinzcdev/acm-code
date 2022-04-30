// https://pintia.cn/api/problem-sets/15/problems/3001
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> v(n * 2);
	for (int i = 0; i < n * 2; i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	printf("%d", v[(n * 2 - 1) / 2]);
	return 0;
}