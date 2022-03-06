#include <bits/stdc++.h>
using namespace std;
bool isprime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int x = 0; x <= n; x++)
        if (isprime(x)) printf("%d\n", x);
    return 0;
}