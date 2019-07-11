#include <cstdio>
#include <cstring>
const int maxn = 1010;

char n[maxn];
int ans[10] = {0};

int main()
{
    scanf("%s", n);
    int len = strlen(n);
    for (int i = 0; i < len; i++)
        ans[n[i] - '0']++;

    for (int i = 0; i < 10; i++)
        if (ans[i] != 0)
            printf("%d:%d\n", i, ans[i]);

    return 0;
}