// https://pintia.cn/problem-sets/994805342720868352/problems/1071785055080476672
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1010;
bool isPrime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int main() {
    int l, k;
    scanf("%d%d", &l, &k);
    string number;
    cin >> number;
    for (int i = 0; i + k - 1 < number.length(); i++) {
        int d = stoi(number.substr(i, k));
        if (isPrime(d)) {
            cout << number.substr(i, k);
            return 0;
        }
    }
    printf("404");
    return 0;
}