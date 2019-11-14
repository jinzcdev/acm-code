#include <iostream>
using namespace std;
int main() {
    int t, k, b, cost, n1, n2;
    scanf("%d%d", &t, &k);
    if (t <= 0) {
        printf("Game Over.\n");
        return 0;
    }
    while (k--) {
        scanf("%d%d%d%d", &n1, &b, &cost, &n2);
        if (t < cost) {
            printf("Not enough tokens.  Total = %d.\n", t);
            continue;
        }
        if (n1 > n2) {
            if (b == 0) {
                t += cost;
                printf("Win %d!  Total = %d.\n", cost, t);
            } else {
                t -= cost;
                printf("Lose %d!  Total = %d.\n", cost, t < 0 ? 0 : t);
            }
        } else if (n1 < n2) {
            if (b == 1) {
                t += cost;
                printf("Win %d!  Total = %d.\n", cost, t);
            } else {
                t -= cost;
                printf("Lose %d!  Total = %d.\n", cost, t < 0 ? 0 : t);
            }
        }
        if (t <= 0) {
            printf("Game Over.\n");
            continue;
        }
    }
    return 0;
}