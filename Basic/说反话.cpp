#include<cstdio>
#include<cstdlib>
int main() {
	char a[90][90];
	int num = 0;
	while (scanf("%s", a[num]) != EOF) {
		num++;
	}

	for (int i = num - 1; i >= 0; i--)
	{
		printf("%s", a[i]);
		if (i > 0) {
			printf(" ");
		}
	}
	
	getchar();
	return 0;
}