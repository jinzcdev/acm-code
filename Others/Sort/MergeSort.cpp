#include <bits/stdc++.h>
using namespace std;
// 80ms
void MergeSort(vector<int> &a, int left, int right, int tmp[]) {
    if (left == right) return;
    int mid = (left + right) / 2;
    MergeSort(a, left, mid, tmp);
    MergeSort(a, mid + 1, right, tmp);
    int i = left, j = mid + 1, pos = left;
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) tmp[pos++] = a[i++];
        else tmp[pos++] = a[j++];
    }
    while (i <= mid) tmp[pos++] = a[i++];
    while (j <= right) tmp[pos++] = a[j++];
    for (int k = left; k <= right; k++) a[k] = tmp[k];
}
int main() {
    int n, tmp[100000];
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    MergeSort(a, 0, n - 1, tmp);
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    return 0;
}