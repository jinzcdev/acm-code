// https://pintia.cn/problem-sets/994805342720868352/problems/994805487143337984
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, b;
    scanf("%d%d", &n, &b);
    vector<int> ans;
    while (n != 0) {
        ans.push_back(n % b);
        n /= b;
    }
    int i = 0, len = ans.size();
    while (i < len / 2 && ans[i] == ans[len - i - 1]) i++;
    printf("%s\n", i == len / 2 ? "Yes" : "No");
    for (int i = len - 1; i >= 0; i--) {
        printf("%d", ans[i]);
        if (i > 0) printf(" ");
    }
    return 0;
}