#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, ans = 0;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    for (int i = 0; i < n / 2; i++) ans += v[n - i - 1] - v[i];
    if (n % 2 == 1) ans += v[n / 2];
    printf("%d %d\n", n % 2 == 0 ? 0 : 1, ans);
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, sum = 0, halfsum = 0;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n / 2; i++) halfsum += v[i];
    printf("%d %d", n % 2, sum - 2 * halfsum);
    return 0;
}
*/