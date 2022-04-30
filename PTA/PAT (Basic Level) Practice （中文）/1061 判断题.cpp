// https://pintia.cn/problem-sets/994805260223102976/problems/994805268817231872
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> answer(m), score(m);
    for (int i = 0; i < m; i++) scanf("%d", &score[i]);
    for (int i = 0; i < m; i++) scanf("%d", &answer[i]);
    while (n--) {
        int ans = 0, temp;
        for (int i = 0; i < m; i++) {
            scanf("%d", &temp);
            if (answer[i] == temp) ans += score[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}