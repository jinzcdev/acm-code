// https://pintia.cn/problem-sets/1146683407522816000/problems/1192048652149108736
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, count;
    cin >> n >> m;
    vector<int> v(n + 1), ans;
    while (m--) {
        for (int i = 1; i <= n; i++) {
            cin >> count;
            v[i] += count;
        }
    }
    int Max = -1;
    for (int i = 1; i <= n; i++) {
        if (v[i] > Max) Max = v[i];
    }
    for (int i = 1; i <= n; i++) {
        if (v[i] == Max) ans.push_back(i);
    }
    printf("%d\n", Max);
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}