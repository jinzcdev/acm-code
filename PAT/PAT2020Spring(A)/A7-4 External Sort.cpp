#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> v(n);
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    while (v.size() > 0) {
        int pre = INT_MIN, cntNext = 0;
        vector<int> tmp, ans;
        for (auto it : v) {
            if (cntNext == m) {
                tmp.push_back(it);
                continue;
            }
            if (it > pre) {
                q.push(it);
                if (q.size() + cntNext == m) {
                    ans.push_back(q.top());
                    pre = q.top();
                    q.pop();
                }
            } else {
                cntNext++;
                tmp.push_back(it);
            }
        }
        while (!q.empty()) {
            ans.push_back(q.top());
            q.pop();
        }
        v = tmp;
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}