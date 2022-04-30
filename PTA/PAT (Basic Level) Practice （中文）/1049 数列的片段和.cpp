// https://pintia.cn/problem-sets/994805260223102976/problems/994805275792359424
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    double ans = 0;
    vector<double> v(n);
    for (int i = 0; i < n; i++) scanf("%lf", &v[i]);
    for (int i = 0; i < n; i++) ans += v[i] * (i + 1) * (n - i);
    printf("%.2f", ans);
    return 0;
}

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     double ans = 0.0, temp;
//     for (int i = 1; i <= n; i++) {
//         cin >> temp;
//         ans += temp * i * (n - i + 1);
//     }
//     printf("%.2f", ans);
//     return 0;
// }