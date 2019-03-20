#include<cstdio>
const int maxn = 210;
int arr[maxn];
int main_codeup1934() {
	int n, x;
	// 多点测试 使用EOF 读至文件末尾
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++)
		{
			scanf("%d", arr + i);
		}
		scanf("%d", &x);
		int k;
		for (k = 0; k < n; k++)
		{
			if (arr[k] == x) {
				printf("%d", k);
				break;
			}
		}
		if (k == n)
		{
			printf("-1");
		}
	}
	return 0;
}