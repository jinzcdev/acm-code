// https://pintia.cn/problem-sets/994805342720868352/problems/994805357933608960
#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    char str[1010];
    scanf("%d%s", &k, str);
    bool isgood[128] = {false}, vis[128] = {false};
    int cnt = 1, len = strlen(str);
    for (int i = 1; i < len; i++) {
        if (str[i] == str[i - 1]) cnt++;
        else {
            if (cnt % k != 0) isgood[str[i - 1]] = true;
            cnt = 1;
        }
    }
    if (cnt % k != 0) isgood[str[len - 1]] = true;
    for (int i = 0; i < len; i++) {
        if (!isgood[str[i]] && !vis[str[i]]) {
            printf("%c", str[i]);
            vis[str[i]] = true;
        }
    }
    printf("\n");
    for (int i = 0; i < len;) {
        printf("%c", str[i]);
        if (!isgood[str[i]]) i += k;
        else i++;
    }
    return 0;
}