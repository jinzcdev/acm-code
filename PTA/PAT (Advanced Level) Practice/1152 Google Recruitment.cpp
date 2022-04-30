// https://pintia.cn/problem-sets/994805342720868352/problems/1071785055080476672
#include <bits/stdc++.h>
using namespace std;
bool isprime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
int main() {
    int n, k;
    string s;
    scanf("%d%d", &n, &k);
    cin >> s;
    for (int i = 0; i < s.length() - k + 1; i++) {
        string temp = s.substr(i, k);
        if (isprime(stoi(temp))) {
            cout << temp;
            return 0;
        }
    }
    printf("404");
    return 0;
}