// https://pintia.cn/problem-sets/14/problems/808
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int main() {
    int n, cnt_out = 0, num = 0, ans = 0;
    bool is_out[N] = {false};
    scanf("%d", &n);
    for (int i = 0; cnt_out != n - 1; i = (i + 1) % n) {
        if (!is_out[i] && ++num % 3 == 0) {
            is_out[i] = true;
            cnt_out++;
        }
    }
    while (ans < n && is_out[ans]) ans++;
    printf("%d", ans + 1);
    return 0;
}
/* python
n = int(input())
a = list(range(n))
i, cnt = 0, 0
while len(a) > 1:
    cnt += 1
    if cnt % 3 == 0:
        a.remove(a[i])
    else:
        i = (i + 1) % len(a)
print(a[0] + 1)
*/