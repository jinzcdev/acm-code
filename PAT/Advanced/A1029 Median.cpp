// https://pintia.cn/problem-sets/994805342720868352/problems/994805466364755968
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    int pos = (a.size() + b.size() + 1) / 2, i = 0, j = 0, cnt = 0, ans;
    while (i < a.size() && j < b.size()) {
        ans = a[i] <= b[j] ? a[i++] : b[j++];
        if (++cnt == pos) break;
    }
    for (; i < a.size() && cnt != pos; i++, cnt++) ans = a[i];
    for (; j < b.size() && cnt != pos; j++, cnt++) ans = b[j];
    printf("%d", ans);
    return 0;
}