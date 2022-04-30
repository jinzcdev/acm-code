// https://pintia.cn/problem-sets/994805342720868352/problems/994805449625288704
#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b) { return a + b < b + a; }
void mergeSort(vector<string> &arr, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    vector<string> temp(right - left + 1);
    int i = left, j = mid + 1, pos = 0;
    while (i <= mid && j <= right)
        arr[i] + arr[j] < arr[j] + arr[i] ? temp[pos++] = arr[i++] : temp[pos++] = arr[j++];
    while (i <= mid) temp[pos++] = arr[i++];
    while (j <= right) temp[pos++] = arr[j++];
    for (int k = left; k <= right; k++) arr[k] = temp[k - left];
}
int main() {
    int n;
    cin >> n;
    string ans = "";
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), cmp);
    // mergeSort(v, 0, n - 1);
    for (int i = 0; i < n; i++) ans += v[i];
    while (ans.size() != 0 && ans[0] == '0') ans.erase(0, 1);
    if (ans.size() == 0) cout << 0;
    else cout << ans;
    return 0;
}