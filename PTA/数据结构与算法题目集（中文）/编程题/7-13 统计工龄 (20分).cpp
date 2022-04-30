// https://pintia.cn/problem-sets/15/problems/721
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a;
    cin >> n;
    map<int, int> mp;
    while (n--) {
        scanf("%d", &a);
        mp[a]++;
    }
    for (auto it : mp) printf("%d:%d\n", it.first, it.second);
    return 0;
}