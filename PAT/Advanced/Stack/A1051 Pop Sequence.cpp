// https://pintia.cn/problem-sets/994805342720868352/problems/994805427332562944
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
const int maxn = 1010;

int main() {
    int m, n, k;
    stack<int> s;
    int a[maxn];
    scanf("%d%d%d", &m, &n, &k);
    while (k--) {
        while (!s.empty()) s.pop();
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        int now = 1;
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            s.push(i);
            if (s.size() > m) {
                flag = false;
                break;
            }
            while (!s.empty() && s.top() == a[now]) {
                s.pop();
                now++;
            }
        }
        if (s.empty() && flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}