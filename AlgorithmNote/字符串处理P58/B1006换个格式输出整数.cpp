#include <cstdio>
const int maxn = 3;
int ans[maxn] = {0};

int main()
{
    int n, num = 0;
    scanf("%d", &n);
    while (n != 0)
    {
        ans[num++] = n % 10;
        n = n / 10;
    }

    for (int i = maxn - 1; i >= 0; i--)
    {
        int count = ans[i];
        if (i == 2)
            while (count--)
                printf("B");
        if (i == 1)
            while (count--)
                printf("S");
        else if (i == 0)
        {
            for (int j = 1; j <= count; j++)
                printf("%d", j);
        } 
    }

    return 0;
}