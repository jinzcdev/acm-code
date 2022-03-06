#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> dp;
ll f(ll n) {
    if (n == 1) return 1;
    ll tmp = (n % 2 == 0 ? f(n / 2) : f(3 * n + 1)) + 1;
    dp[n] = tmp;
}
int main() {
    ll a, b;
    dp[1] = 1;
    while (scanf("%lld%lld", &a, &b) != EOF) {
        printf("%d %d ", a, b);
        if (a > b) swap(a, b);
        ll MAX = -1;
        for (ll x = a; x <= b; x++) {
            ll tmp = f(x);
            MAX = max(tmp, MAX);
        }
        printf("%d\n", MAX);
    }
    return 0;
}