// https://pintia.cn/problem-sets/14/problems/734
#include <stdio.h>

#define MAXN 10

double f( int n, double a[], double x, int Max );

int main()
{
    int n, i;
    double a[MAXN], x;
	
    scanf("%d %lf", &n, &x);
    for ( i=0; i<=n; i++ )
        scanf("%lf", &a[i]);
    printf("%.1f\n", f(n, a, x, n + 1));
    return 0;
}

double f( int n, double a[], double x, int Max) {
    double k = a[Max - n - 1];
    double l = f (n - 1, a, x, Max);
    return k + x * l;
}

/*
double f( int n, double a[], double x ) {
    double ans = 0;
    int i = 0;
    for ( ; i <= n; i++) {
        double temp = 1.0;
        int j = 0;
        for ( ; j < i; j++) {
            temp *= x;
        }
        ans += a[i] * temp;
    }
    return ans;
}
double f( int n, double a[], double x ) {
    double ans = a[n];
    for (int i = n - 1; i >= 0; i--) {
        ans = ans * x + a[i];
    }
    return ans;
}*/