// https://pintia.cn/problem-sets/994805342720868352/problems/994805343236767744
#include <bits/stdc++.h>
using namespace std;
bool isprime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
int main() {
    int size, n, m, key, cnt = 0;
    scanf("%d%d%d", &size, &n, &m);
    while (!isprime(size)) size++;
    vector<int> hash(size), v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        bool flag = false;
        for (int j = 0; j < size; j++) {
            int pos = (key + j * j) % size;
            if (hash[pos] == 0) {
                hash[pos] = key;
                flag = true;
                break;
            }
        }
        if (!flag) printf("%d cannot be inserted.\n", key);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &key);
        for (int j = 0; j <= size; j++) {
            cnt++;
            int pos = (key + j * j) % size;
            if (hash[pos] == 0 || hash[pos] == key) break;
        }
    }
    printf("%.1f", cnt * 1.0 / m);
    return 0;
}
/*
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
*/