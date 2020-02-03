// https://pintia.cn/problem-sets/994805260223102976/problems/994805282389999616
#include <iostream>
using namespace std;
const int N = 100010;
int main() {
    string s;
    cin >> s;
    int dpP[N], dpT[N], len = s.length(), ans = 0;
    dpP[0] = dpT[len - 1] = 0;
    for (int i = 1; i < len; i++) {
        dpP[i] = dpP[i - 1] + (s[i - 1] == 'P');
        dpT[len - i - 1] = dpT[len - i] + (s[len - i] == 'T');
    }
    for (int i = 0; i < len; i++)
        if (s[i] == 'A') ans = (ans + (dpP[i] * dpT[i]) % 1000000007) % 1000000007;
    cout << ans;
    return 0;
}