#include <cstdio>
#include <algorithm>
const int maxn = 10010;
int n, m;

struct Student
{
    char no[15];
    int score;
} stu[maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", stu[i].no, stu[i].score);
    }

    return 0;
}