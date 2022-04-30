// https://pintia.cn/problem-sets/14/problems/733
#include <stdio.h>

void PrintN(int N);

int main() {
    int N;

    scanf("%d", &N);
    PrintN(N);

    return 0;
}

void PrintN(int N) {
    int i = 1;
    while (i <= N) {
        printf("%d\n", i++);
    }
}