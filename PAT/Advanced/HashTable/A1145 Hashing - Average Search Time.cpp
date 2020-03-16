#include <bits/stdc++.h>
using namespace std;
bool isprime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
int main() {
    int msize, n, m, key, pos;
    scanf("%d%d%d", &msize, &n, &m);
    while (!isprime(msize)) msize++;
    vector<int> hash(msize, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        for (int j = 0; j < msize; j++) {
            pos = (key + j * j) % msize;
            if (hash[pos] == 0) {
                hash[pos] = key;
                break;
            }
        }
        if (hash[pos] != key) printf("%d cannot be inserted.\n", key);
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &key);
        bool flag = false;
        for (int j = 0; j < msize; j++) {
            cnt++;
            pos = (key + j * j) % msize;
            if (hash[pos] == key || hash[pos] == 0) {
                flag = true;
                break;
            }
        }
        if (!flag) cnt++;
    }
    printf("%.1f", cnt * 1.0 / m);
    return 0;
}