// https://pintia.cn/problem-sets/994805260223102976/problems/994805282389999616
#include <iostream>
using namespace std;
int main() {
    string str;
    cin >> str;
    int p = 0, a = 0, t = 0, ans = 0;
    for (int i = 0; i < str.length(); i++) if (str[i] == 'T') t++;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'P') p++;
        if (str[i] == 'A') ans = (ans + (p * t) % 1000000007) % 1000000007;
        if (str[i] == 'T') t--;
    }
    printf("%d", ans);
    return 0;
}