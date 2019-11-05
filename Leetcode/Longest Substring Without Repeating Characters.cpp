// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
#include <iostream>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> us;
    int left = 0, right = 0, len = s.length(), ans = 0;
    while (left < len && right < len) {
        if (us.find(s[right]) != us.end()) {
            us.erase(s[left++]);
        } else {
            us.insert(s[right++]);
            ans = max(ans, right - left);
        }
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s);
    return 0;
}