#include <bits/stdc++.h>
int n = 8;
using namespace std;
int a[] = {3, 5, 10, 15, 21, 30, 36, 40};
void solve(int x) {
    int left = 0, right = n - 1, mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (a[mid] >= x) right = mid;
        else left = mid + 1;
    }
    if (a[left] == x) printf("%s\n", a[left] == x ? "Yes" : "No");
}

int binarySearch(int x) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (a[mid] < x) left = mid + 1;
        else if (a[mid] > x) right = mid - 1;
        else break;
    }
    return -1;
}
int main() {
    int x;
    while (true) {
        scanf("%d", &x);
        solve(x);
    }
    return 0;
}