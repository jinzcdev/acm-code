#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
    int n, v;
};
int n, k, m;
bool flag;
vector<node> ans;

bool cmp(node a, node b) {
    if (a.n != b.n) return a.n < b.n;
    return a.v < b.v;
}

bool isPrime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int getDigitSum(int x) {
    int sumD = 0;
    while (x != 0) {
        sumD += x % 10;
        x /= 10;
    }
    return sumD;
}

void dfs(int number, int numDigit, int sumD) {
    if (sumD > m) return;
    if (sumD + 9 * (k - numDigit) < m) return;
    if (numDigit == k) {
        if (sumD != m) return;
        int n = getDigitSum(number + 1);
        int x = gcd(m, n);
        if (x > 2 && isPrime(x)) {
            ans.push_back({n,number});
        }
        return;
    }
    for (int i = 0; i <= 9; i++) {
        dfs(number * 10 + i, numDigit + 1, sumD + i);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Case %d\n", i);
        scanf("%d%d", &k, &m);
        ans.clear();
        for (int j = 1; j <= 9; j++) {
            dfs(j, 1, j);
        }
        if (ans.size() == 0) {
            printf("No Solution\n");
        } else {
            sort(ans.begin(), ans.end(), cmp);
            for (auto it : ans) {
                printf("%d %d\n", it.n, it.v);
            }
        }
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
bool isprime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
bool cmp(pii &a, pii &b) {
    return tie(a.first, a.second) < tie(b.first, b.second);
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int getsum(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int main() {
    int n, k, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Case %d\n", i);
        scanf("%d%d", &k, &m);
        vector<pii> ans;
        int minA = pow(10, k - 2), maxA = pow(10, k - 1) - 1;
        for (int j = minA; j <= maxA; j++) {
            int a = j * 10 + 9;
            int tmpN = getsum(a + 1), tmpM = getsum(a), x = gcd(tmpM, tmpN);
            if (tmpM == m && x > 2 && isprime(x)) ans.push_back({tmpN, a});
        }
        if (ans.size() == 0) {
            printf("No Solution\n");
            continue;
        }
        sort(ans.begin(), ans.end(), cmp);
        for (const auto &it : ans) printf("%d %d\n", it.first, it.second);
    }
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
struct node {
    int n, v;
};
int n, k, m;
vector<node> ans;
bool cmp(node a, node b) { return a.n != b.n ? a.n < b.n : a.v < b.v; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
bool isPrime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int getDigitSum(int x) {
    int sumD = 0;
    while (x != 0) {
        sumD += x % 10;
        x /= 10;
    }
    return sumD;
}
void dfs(int number, int numDigit, int sumD) {
    if (sumD > m) return;
    if (sumD + 9 * (k - numDigit) < m) return;
    if (numDigit == k) {
        if (sumD != m) return;
        int n = getDigitSum(number + 1);
        int x = gcd(m, n);
        if (x > 2 && isPrime(x)) ans.push_back({n, number});
        return;
    }
    for (int i = 0; i <= 9; i++)
        dfs(number * 10 + i, numDigit + 1, sumD + i);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Case %d\n", i);
        scanf("%d%d", &k, &m);
        ans.clear();
        for (int j = 1; j <= 9; j++) dfs(j, 1, j);
        if (ans.size() == 0) printf("No Solution\n");
        else {
            sort(ans.begin(), ans.end(), cmp);
            for (auto it : ans)
                printf("%d %d\n", it.n, it.v);
        }
    }
    return 0;
}
