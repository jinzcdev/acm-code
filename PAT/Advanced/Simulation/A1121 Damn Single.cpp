// https://pintia.cn/problem-sets/994805342720868352/problems/994805352359378944
#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int main() {
    int n, m, a, b;
    vector<int> couple(N);
    bool hasMate[N] = {false}, inq[N] = {false};
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        couple[a] = b;
        couple[b] = a;
        hasMate[a] = hasMate[b] = true;
    }
    scanf("%d", &m);
    vector<int> v(m), ans;
    for (int i = 0; i < m; i++) {
        scanf("%d", &v[i]);
        inq[v[i]] = true;
    }
    for (int i = 0; i < m; i++)
        if (!hasMate[v[i]] || !inq[couple[v[i]]]) ans.push_back(v[i]);
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf(" ");
        printf("%05d", ans[i]);
    }
    return 0;
}