#include <bits/stdc++.h>
using namespace std;
// 传入的right应为实际右界+1，有可能不存在这个数
int BinarySearch(vector<int> &a, int left, int right, int x) {
    int mid;
    while (left < right) {
        mid = (right + left) / 2;
        if (a[mid] >= x) right = mid;
        else left = mid + 1;
    }
    return left;
}

// 6200ms
void InsertSort(vector<int> &a, int n) {
    for (int i = 0; i < n; i++) {
        int tmp = a[i], j = i - 1;
        for (; j >= 0 && a[j] > tmp; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = tmp;
    }
}

// 2400ms
void BinaryInsertSort(vector<int> &a, int n) {
    for (int i = 0; i < n; i++) {
        // int tmp = a[i], pos = lower_bound(a.begin(), a.begin() + i, a[i]) - a.begin();
        int tmp = a[i], pos = BinarySearch(a, 0, i, a[i]);
        for (int j = i; j > pos; j--) {
            a[j] = a[j - 1];
        }
        a[pos] = tmp;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    InsertSort(a, n);
    //     BinaryInsertSort(a, n);
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    return 0;
}