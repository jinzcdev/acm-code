#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int main() {
    int n, num = 1, a[N][N] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x = i, y = 0;
        for (int j = 0; j < i + 1; j++) {
            a[x][y] = num++;
            x -= 1;
            y += 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (j != 0) printf(" ");
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}