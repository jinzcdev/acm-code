/**
 * 树状数组动态查询第k小的数.
 */
#include <iostream>
#include <vector>
#define lowbit(x) ((x) & (-x))
using namespace std;
const int N = 1025;
int c[N] = {0};

void add(int x, int v);
int getSum(int x);
int getKthLeast(int k);

int main() {
    int n, k, temp, cnt = 0;
    while (true) {
        while (cin >> temp, temp != -1) {
            add(temp, 1);
        }
        printf("Input the k to search: ");
        scanf("%d", &k);
        if (k != -1) {
            printf("The k-th least number is %d\n", getKthLeast(k));
            break;
        } else continue;
    }
    return 0;
}

void add(int x, int v) {
    for (int i = x; i < N; i += lowbit(i)) c[i] += v;
}

int getSum(int x) {
    if (x < 1) return 0;
    else return c[x] + getSum(x - lowbit(x));
}

int getKthLeast(int k) {
    int left = 1, right = N - 1, mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (getSum(mid) >= k) right = mid;
        else left = mid + 1;
    }
    return left;
}

// for (int i = 1; i <= 16; i++) printf("%d ", getSum(i));

/*
int getSum(int x) {
    int sum = 0;
    while (x >= 1) {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}
*/