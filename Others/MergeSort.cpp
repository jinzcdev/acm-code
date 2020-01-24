/**
 * Merge Sort (Divide and Conquer)
 */
#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &a, vector<int> &temp, int left, int leftEnd,
           int right) {
    int i = left, j = leftEnd + 1, tempPos = left;
    while (i <= leftEnd && j <= right) {
        if (a[i] <= a[j])
            temp[tempPos++] = a[i++];
        else
            temp[tempPos++] = a[j++];
    }
    while (i <= leftEnd) temp[tempPos++] = a[i++];
    while (j <= right) temp[tempPos++] = a[j++];
    for (int k = left; k <= right; k++) {
        a[k] = temp[k];
    }
}
void mergeSort(vector<int> &a, vector<int> &temp, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(a, temp, left, mid);
        mergeSort(a, temp, mid + 1, right);
        merge(a, temp, left, mid, right);
    }
}
void mergeSort(vector<int> &a) {
    vector<int> temp(a.size());
    mergeSort(a, temp, 0, a.size() - 1);
}
void printArr(vector<int> &arr) {
    for (auto it : arr) {
        cout << it << " ";
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergeSort(arr);
    printArr(arr);
    return 0;
}