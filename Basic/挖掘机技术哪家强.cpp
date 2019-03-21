#include<cstdio>
int a[100000];
int main_b1032() {
	int T, n;
	scanf("%d", &T);
	n = T;
	while (T--) {
		int index, value;
		scanf("%d %d", &index, &value);
		a[index] += value;
	}

	int n_max, max = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > max) {
			max = a[i];
			n_max = i;
		}
	}

	printf("%d %d", n_max, max);
	return 0;
}