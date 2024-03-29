// https://pintia.cn/problem-sets/14/problems/740
/*int Factorial(const int N) {
    if (N < 0) return 0;
    if (N == 0) return 1;
    int ans = 1, i = 1;
    for (; i <= N; i++) ans *= i;
    return ans;
}*/

/**
 * 递归解法
 */
int Factorial(const int N) {
    if (N < 0) return 0;
    if (N == 0) return 1;
    return N * Factorial(N - 1);
}