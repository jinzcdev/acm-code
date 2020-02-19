#include <cstdio>
int step;
void hanoi(int n, char a, char b, char c) {
    if (n == 1) {
        printf("第%d步: 从 %c 移到 %c\r\n", step++, a, c);
        return;
    }
    hanoi(n - 1, a, c, b);
    printf("第%d步: 从 %c 移到 %c\r\n", step++, a, c);
    hanoi(n - 1, b, a, c);
}
int main() {
    int n;
    scanf("%d", &n);
    while (scanf("%d", &n) != EOF) {
        step = 1;
        printf("请输出盘子的数量: %d\r\n", n);
        scanf("%d", &n);
        hanoi(n, 'A', 'B', 'C');
    }
    return 0;
}