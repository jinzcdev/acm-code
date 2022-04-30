// https://pintia.cn/problem-sets/994805342720868352/problems/994805347145859072
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string z;
    cin >> n;
    while (n--) {
        cin >> z;
        int iz = stoi(z), a = stoi(z.substr(0, z.length() / 2)), b = stoi(z.substr(z.length() / 2));
        printf("%s\n", a != 0 && b != 0 && iz % (a * b) == 0 ? "Yes" : "No");
    }
    return 0;
}