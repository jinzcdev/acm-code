/**
 * 依次给出n个正整数A1，A2，… ，An，将这n个数分割成m段，
 * 每一段内的所有数的和记为这一段的权重， m段权重的最大值记为本次分割的权重。
 * 问所有分割方案中分割权重的最小值是多少？
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int splitArray(vector<int>& nums, int m) {
    ll left = 0, right = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        right += nums[i];
        if (left < nums[i]) left = nums[i];
    }
    ll ans = right;
    while (left <= right) {
        ll mid = (left + right) >> 1;
        ll sum = 0;
        int cnt = 1;
        for (int i = 0; i < n; i++) {
            if (sum + nums[i] > mid) {
                cnt++;
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }
        if (cnt <= m) {
            ans = min(ans, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> nums(n);
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    printf("%d", splitArray(nums, m));
    return 0;
}

/*
int splitArray(vector<int>& nums, int m) {
    int n = nums.size();
    vector<vector<int>> f(n + 1, vector<int>(m + 1, INT_MAX));
    vector<int> sub(n + 1, 0);
    for (int i = 0; i < n; i++) {
        sub[i + 1] = sub[i] + nums[i];
    }
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < i; k++) {
                f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
            }
        }
    }
    return f[n][m];
}
*/