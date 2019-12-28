// https://pintia.cn/problem-sets/14/problems/741
#include <stdio.h>

int Count_Digit(const int N, const int D);

int main() {
    int N, D;

    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

int Count_Digit(const int N, const int D) {
    if (N == 0 && D == 0) return 1;
    int temp = N > 0 ? N : -N, cnt = 0;
    while (temp != 0) {
        if (temp % 10 == D) cnt++;
        temp /= 10;
    }
    return cnt;
}