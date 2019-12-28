// https://pintia.cn/problem-sets/14/problems/739
#include <math.h>
#include <stdio.h>

int IsTheNumber(const int N);

int main() {
    int n1, n2, i, cnt;

    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for (i = n1; i <= n2; i++) {
        if (IsTheNumber(i)) cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

int IsTheNumber(const int N) {
    int hash[10] = {0}, temp = N, i;
    while (temp != 0) {
        hash[temp % 10]++;
        temp /= 10;
    }
    int flag = 0;
    for (i = 0; i <= 9; i++) {
        if (hash[i] >= 2) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) return 0;
    int sqr = (int)sqrt(N);
    if (pow(sqr, 2) == N) return 1;
    else return 0;
}