// https://pintia.cn/problem-sets/994805342720868352/problems/994805446102073344
#include <bits/stdc++.h>
using namespace std;
string str;
int solve(int left, int right) {
    while (left >= 0 && right < str.length() && str[left] == str[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}
int main() {
    getline(cin, str);
    int maxLen = 1;
    for (int i = 0; i < str.length() - 1; i++)
        maxLen = max(max(solve(i - 1, i + 1), solve(i, i + 1)), maxLen);
    printf("%d", maxLen);
    return 0;
}