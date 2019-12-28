// https://pintia.cn/problem-sets/14/problems/740
#include <stdio.h>

int Factorial(const int N);

int main() {
    int N, NF;

    scanf("%d", &N);
    NF = Factorial(N);
    if (NF)
        printf("%d! = %d\n", N, NF);
    else
        printf("Invalid input\n");

    return 0;
}

int Factorial(const int N) {
    if (N < 0) return 0;
    if (N == 0) return 1;
    int ans = 1, i = 1;
    for (; i <= N; i++) ans *= i;
    return ans;
}

/**
 * 递归解法
 */
int Factorial(const int N) {
    if (N < 0) return 0;
    if (N == 0) return 1;
    return N * Factorial(N - 1);
}