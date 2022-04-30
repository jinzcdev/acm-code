// // https://pintia.cn/problem-sets/994805342720868352/problems/994805377432928256
// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     vector<int> origin(n), v(n);
//     for (int i = 0; i < n; i++) scanf("%d", &origin[i]);
//     for (int i = 0; i < n; i++) scanf("%d", &v[i]);
//     int pos = 1, len;
//     while (pos < n && v[pos - 1] <= v[pos]) pos++;
//     len = pos;
//     while (pos < n && v[pos] == origin[pos]) pos++;
//     if (pos == n) {
//         cout << "Insertion Sort\n";
//         sort(origin.begin(), origin.begin() + len + 1);
//     } else {
//         printf("Merge Sort\n");
//         for (int step = 1; step <= n;) {
//             bool flag = true;
//             for (int i = 0; i < n; i++) {
//                 if (origin[i] != v[i]) {
//                     flag = false;
//                     break;
//                 }
//             }
//             step *= 2;
//             for (int i = 0; i < n; i += step) {
//                 int end = min(i + step, n);
//                 sort(origin.begin() + i, origin.begin() + end);
//             }
//             if (flag) break;
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         if (i != 0) printf(" ");
//         printf("%d", origin[i]);
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> origin(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &origin[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    int pos = 2, j;
    while (pos <= n && v[pos] >= v[pos - 1]) j = ++pos;
    while (pos <= n && v[pos] == origin[pos]) pos++;
    if (pos == n + 1) {
        printf("Insertion Sort\n");
        sort(origin.begin() + 1, origin.begin() + 1 + j);
    } else {
        printf("Merge Sort\n");
        bool flag = false;
        int step = 1;
        for (; step <= n; step *= 2) {
            for (int i = 1; i <= n; i += step) {
                int end = i + step - 1 > n ? n + 1 : i + step;
                sort(origin.begin() + i, origin.begin() + end);
            }
            if (flag == true) break;
            pos = 1;
            while (pos <= n && origin[pos] == v[pos]) pos++;
            if (pos == n + 1) flag = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) printf(" ");
        printf("%d", origin[i]);
    }
    return 0;
}