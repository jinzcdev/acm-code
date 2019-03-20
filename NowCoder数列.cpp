// write your code here cpp
#include<cstdio>
#include<cstdlib>
int a[100000];
int fn(int n) {
	int result;
	if (n >= 2) {
		result = fn(n - 1) + fn(n - 2);
	}
	if (n == 0) {
		result = 7;
	}
	if (n == 1) {
		result = 11;
	}
	return result;
}

int main_sl() {
	int num = 0, rs;
	//scanf("%d", &a);
	while (scanf("%d", &a[num]) != EOF) {
		rs = fn(a[num]);
		if (rs % 3 == 0) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
		num++;
	}
	
	return 0;
}
