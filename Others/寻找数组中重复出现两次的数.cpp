#include <bits/stdc++.h>
using namespace std;
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;
    for (auto it : nums) {
        it = abs(it);
        if (it > nums.size()) continue;     // 过滤大于n的数(即nums的size)
        if (nums[it - 1] < 0) ans.push_back(it);
        else nums[it - 1] *= -1;
    }
    for (int i = 0; i < nums.size(); i++) nums[i] = abs(nums[i]);   // 重新置为正数
    for (auto it : nums) {
        it = abs(it);
        if (it <= nums.size()) continue;    // 过滤小于等于n的数
        int pos = (it - 1) % nums.size();
        if (nums[pos] < 0) ans.push_back(it);
        else nums[pos] *= -1;
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    vector<int> ans = findDuplicates(v);
    for (auto it : ans) printf("%d ", it);
    return 0;
}

/*
输入样例1:
10
1 12 12 2 2 6 7 18 3 3
输出:
2 3 12

输入样例2:
8 
1 10 10 2 2 5 6 5
输出:
2 5 10

输入样例3:
8
1 1 2 4 5 6 10 10
输出:
1 10

*/ 