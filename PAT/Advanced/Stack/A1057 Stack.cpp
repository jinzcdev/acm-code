// https://pintia.cn/problem-sets/994805342720868352/problems/994805417945710592
#include <iostream>
#include <stack>
#define lowbit(x) ((x) & (-x))
using namespace std;
const int maxn = 100010;
int c[maxn] = {0};
stack<int> s;
void add(int x, int v) {
    while (x < maxn) {
        c[x] += v;
        x += lowbit(x);
    }
}
int getSum(int x) {
    int sum = 0;
    while (x >= 1) {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}
void PeekMedian() {
    int left = 1, right = maxn, mid, k = (s.size() + 1) / 2;
    while (left < right) {
        mid = (left + right) / 2;
        if (getSum(mid) >= k) right = mid;
        else left = mid + 1;
    }
    printf("%d\n", left);
}
int main() {
    int n, k;
    scanf("%d", &n);
    char op[15];
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (op[1] == 'u') {
            scanf("%d", &k);
            s.push(k);
            add(k, 1);
        } else if (op[1] == 'o') {
            if (s.empty()) printf("Invalid\n");
            else {
                add(s.top(), -1);
                printf("%d\n", s.top());
                s.pop();
            }
        } else {
            if (s.empty()) printf("Invalid\n");
            else PeekMedian();
        }
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010, N = 316;
int block[N] = {0}, table[MAXN] = {0};
stack<int> s;
int PeekMedian(int k) {
    int sum = 0, i = 0;
    while (sum + block[i] < k) sum += block[i++];
    int num = i * N;
    while (sum + table[num] < k) sum += table[num++];
    return num;
}
void Push(int x) {
    s.push(x);
    block[x / N]++;
    table[x]++;
}
void Pop() {
    int top = s.top();
    s.pop();
    block[top / N]--;
    table[top]--;
    printf("%d\n", top);
}
int main() {
    int n, x;
    scanf("%d", &n);
    char cmp[15];
    while (n--) {
        scanf("%s", cmp);
        if (cmp[1] == 'u') {
            scanf("%d", &x);
            Push(x);
        } else {
            if (s.empty()) printf("Invalid\n");
            else if (cmp[1] == 'o') Pop();
            else {
                int len = s.size();
                printf("%d\n", PeekMedian(len % 2 ? (len + 1) / 2 : len / 2));
            }
        }
    }
    return 0;
}
*/