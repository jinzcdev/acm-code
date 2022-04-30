// https://pintia.cn/problem-sets/994805342720868352/problems/994805495863296000
#include <bits/stdc++.h>
using namespace std;
bool isprime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
int convert(int a, int d) {
    vector<int> v;
    while (a != 0) {
        v.push_back(a % d);
        a /= d;
    }
    int sum = 0;
    for (auto it : v) sum = sum * d + it;
    return sum;
}
int main() {
    int a, d;
    while (scanf("%d", &a), a > 0) {
        scanf("%d", &d);
        printf("%s\n", isprime(a) && isprime(convert(a, d)) ? "Yes" : "No");
    }
    return 0;
}