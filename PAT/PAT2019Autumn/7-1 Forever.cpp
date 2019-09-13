#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n, k, m;
int maxValue;

bool isPrime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int getDivisor(int a, int b) {
    if (b < a) swap(a, b);
    int c = b % a;
    while (c != 0) {
        b = a;
        a = c;
        c = b % a;
    }
    return a;
}


int getSum(int x) {
    int sum = 0;
    while (x != 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Case %d\n", i);
        scanf("%d%d", &k, &m);
        int minValue = pow(10, k - 1 - 2);
        int maxValue = pow(10, k - 2) - 1;
        bool flag = false;
        for (int j = minValue; j <= maxValue; j++) {
            int dm = getSum(j) + 18, dn = getSum(j * 100 + 99 + 1);
            if (dm == m) {
                int div = getDivisor(dm, dn);
                if (isPrime(div) && div > 2) {
                    flag = true;
                    printf("%d %d\n", dn, j * 100 + 99);
                }
            }
        }
        if (!flag) {
            printf("No Solution\n");
        }
    }
    return 0;
}
