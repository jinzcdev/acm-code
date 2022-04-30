// https://pintia.cn/problem-sets/14/problems/734
#include <stdio.h>

#define MAXN 10

double f( int n, double a[], double x ) {
    double ans = a[n];
    for (int i = n - 1; i >= 0; i--) {
        ans = ans * x + a[i];
    }
    return ans;
}

int main()
{
    int n = 2, i;
    double a[MAXN] = {1, 2.5, -38.7}, x = 1.1;
    printf("%.1f\n", f(n, a, x));
    return 0;
}