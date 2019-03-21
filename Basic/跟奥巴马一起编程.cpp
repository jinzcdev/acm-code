#include<cstdio>
int main_b1036() {
	int col;
	char c;
	scanf("%d %c", &col, &c);
	int row;
	if (col % 2 != 0)
		row = col / 2 + 1;
	else
		row = col / 2;
	for (int i = 0; i < col; i++)
		printf("%c", c);
	printf("\n");
	int space = col - 2;
	for (int i = 0; i < row - 2; i++)
	{
		printf("%c", c);
		for (int j = 0; j < space; j++)
		{
			printf(" ");
		}
		printf("%c\n", c);
	}

	for (int i = 0; i < col; i++)
		printf("%c", c);
	return 0;
}