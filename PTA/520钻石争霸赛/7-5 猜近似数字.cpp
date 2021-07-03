// https://pintia.cn/problem-sets/1259839299727368192/problems/1259850789826048002
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b;
    cin >> a;
    while (cin >> b, b[0] != '-') {
        if (a.length() != b.length())
            printf("No\n");
        else {
            int cnt = 0, ans = 0;
            for (int i = 0; i < a.length(); i++) {
                if (a[i] != b[i]) {
                    cnt++;
                    ans = a[i] - b[i];
                }
            }
            if (cnt > 1 || (cnt == 1 && abs(ans) > 1)) printf("No\n");
            else printf("Yes\n");
        }
    }
    return 0;
}