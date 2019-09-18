// https://pintia.cn/problem-sets/994805260223102976/problems/994805266942377984
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 500010;
int main() {
    int n, m, a, b, id;
    vector<int> couple(100000, -1);
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        couple[a] = b;
        couple[b] = a;
    }
    scanf("%d", &m);
    vector<int> guest;
    int isExited[maxn] = {false};
    while (m--) {
        cin >> id;
        guest.push_back(id);
        isExited[id] = true;
    }
    vector<int> ans;
    for (auto it : guest) {
        if (couple[it] == -1) ans.push_back(it);
        else if (!isExited[couple[it]]) ans.push_back(it);
    }
    printf("%d\n", ans.size());
    sort(ans.begin(), ans.end());
    int cnt = 0;
    for (auto it : ans) {
        printf("%05d", it);
        if (++cnt < ans.size()) printf(" ");
    }
    return 0;
}