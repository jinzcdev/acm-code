#include <bits/stdc++.h>
using namespace std;
/*vector<int> mergeSort(vector<int> arr, int left, int right) {
    if (left == right) {
        vector<int> v(1);
        v[0] = arr[left];
        return v;
    }
    int mid = left + (right - left) / 2;
    vector<int> lv = mergeSort(arr, left, mid);
    vector<int> rv = mergeSort(arr, mid + 1, right);
    vector<int> ans(lv.size() + rv.size());
    int pos = 0, i = 0, j = 0;
    while (i < lv.size() && j < rv.size()) {
        ans[pos++] = lv[i] <= rv[j] ? lv[i++] : rv[j++];
    }
    while (i < lv.size()) ans[pos++] = lv[i++];
    while (j < rv.size()) ans[pos++] = rv[j++];
    return ans;
}*/

void mergeSort(vector<int> &arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    vector<int> temp(right - left + 1);
    int pos = 0, i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        temp[pos++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    }
    while (i <= mid) temp[pos++] = arr[i++];
    while (j <= right) temp[pos++] = arr[j++];
    for (int k = left; k <= right; k++) arr[k] = temp[k - left];
}

void insertSort(vector<int> v) {
    if (v.size() == 0) return;
    for (int i = 1; i < v.size(); i++) {
        int pos = i - 1, k = i;
        while (pos >= 0 && v[k] < v[pos]) {
            swap(v[k], v[pos]);
            k = pos--;
        }
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << "Initial sequence: \t";
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
    // vector<int> ans = 
    mergeSort(v, 0, v.size() - 1);
    cout << "Result after sorting: \t";
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    // insertSort(v);
    return 0;
}