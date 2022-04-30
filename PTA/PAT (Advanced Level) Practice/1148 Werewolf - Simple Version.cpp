// https://pintia.cn/problem-sets/994805342720868352/problems/1038429808099098624
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            vector<int> liar, iswolf(n + 1, 1);
            iswolf[i] = iswolf[j] = -1;
            for (int k = 1; k <= n; k++)
                if (v[k] * iswolf[abs(v[k])] < 0)
                    liar.push_back(k);
            if (liar.size() == 2 && (iswolf[liar[0]] + iswolf[liar[1]] == 0)) {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }
    printf("No Solution");
    return 0;
}