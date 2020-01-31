#include <bits/stdc++.h>
using namespace std;
bool isprime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
int issexy(int n) {
    if (isprime(n) && isprime(n - 6)) return n - 6;
    else if (isprime(n) && isprime(n + 6)) return n + 6;
    else return 0;
}
int main() {
    int n, ans;
    scanf("%d", &n);
    if (ans = issexy(n)) {
        printf("Yes\n%d", ans);
    } else {
        while (!(ans = issexy(n))) n++;
        printf("No\n%d", n);
    }
    return 0;
}