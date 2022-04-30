// https://pintia.cn/problem-sets/994805342720868352/problems/994805507225665536
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll convert(string s, ll radix) {
    ll sum = 0;
    for (int i = 0; i < s.size(); i++)
        sum = sum * radix + (isdigit(s[i]) ? s[i] - '0' : s[i] - 'a' + 10);
    return sum;
}
int main() {
    string a, b;
    ll tag, radix;
    cin >> a >> b >> tag >> radix;
    if (tag == 2) swap(a, b);
    ll x = convert(a, radix), ans = -1;
    char ch = *max_element(b.begin(), b.end());
    ll low = (isdigit(ch) ? ch - '0' : ch - 'a' + 10) + 1;
    ll high = max(low, x);
    while (low <= high) {
        ll mid = (high - low) / 2 + low;
        ll t = convert(b, mid);
        if (t < 0 || x < t) high = mid - 1;
        else if (x > t) low = mid + 1;
        else {
            ans = mid;
            break;
        }
    }
    if (ans != -1) printf("%d", ans);
    else printf("Impossible");
    return 0;
}