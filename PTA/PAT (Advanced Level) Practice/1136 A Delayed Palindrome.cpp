
// https://pintia.cn/problem-sets/994805342720868352/problems/994805345732378624
#include <bits/stdc++.h>
using namespace std;
bool ispali(char* s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++)
        if (s[i] != s[len - i - 1]) return false;
    return true;
}
char ans[1010];
void add(char* a, char* b) {
    int lena = strlen(a), lenb = strlen(b), carry = 0, len = 0, i = 0;
    for (; i < lena; i++) {
        int temp = (a[i] - '0') + (b[i] - '0') + carry;
        ans[len++] = temp % 10 + '0';
        carry = temp / 10;
    }
    if (carry != 0) ans[len++] = carry + '0';
    ans[len] = '\0';
    reverse(ans, ans + len);
}
int main() {
    char a[1010], b[1010];
    scanf("%s", a);
    int cnt = 0;
    if (ispali(a)) {
        printf("%s is a palindromic number.\n", a);
        return 0;
    }
    while (true) {
        strcpy(b, a);
        reverse(b, b + strlen(b));
        add(a, b);
        printf("%s + %s = %s\n", a, b, ans);
        if (ispali(ans)) {
            printf("%s is a palindromic number.\n", ans);
            break;
        }
        if (++cnt == 10) {
            printf("Not found in 10 iterations.\n");
            break;
        }
        strcpy(a, ans);
    }
    return 0;
}
/*#include <iostream>
#include <algorithm>
using namespace std;
string reverseNumber(string number) {
    reverse(number.begin(), number.end());
    return number;
}

bool isPld (string str){
    int len = str.size();
    for (int i = 0; i < len; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

string getSum(string number, string rnumber) {
    string sum = number;
    int k = 0, len = number.size();
    for (int i = len - 1; i >= 0; i--) {
        int rs = (number[i] - '0') + (rnumber[i] - '0') + k;
        sum[i] = rs % 10 + '0';
        k = rs / 10;
    }
    if (k != 0) sum = "1" + sum;
    return sum;
}

int main() {
    string number;
    cin >> number;
    if (isPld(number)) {
        cout << number << " is a palindromic number.\n";
    } else {
        int cnt = 0;
        while (!isPld(number)) {
            if (cnt++ == 10) {
                printf("Not found in 10 iterations.\n");
                return 0;
            }
            string rnumber = reverseNumber(number);
            printf("%s + %s = ", number.c_str(), rnumber.c_str());
            number = getSum(number, rnumber);
            printf("%s\n", number.c_str());
        }
        printf("%s is a palindromic number.\n", number.c_str());
    }
    return 0;
}*/

/*
#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string str) {
    for (int i = 0; i < str.length() / 2; i++)
        if (str[i] != str[str.length() - i - 1]) return false;
    return true;
}
string sumStr(string str) {
    string ans = str;
    reverse(ans.begin(), ans.end());
    printf("%s + %s = ", str.c_str(), ans.c_str());
    int carry = 0;
    for (int i = str.length() - 1; i >= 0; i--) {
        int temp = (str[i] - '0') + (ans[i] - '0') + carry;
        ans[i] = temp % 10 + '0';
        carry = temp / 10;
    }
    if (carry != 0) ans = "1" + ans;
    cout << ans << endl;
    return ans;
}
void solve(string str, int cnt) {
    if (isPalindrome(str)) {
        printf("%s is a palindromic number.\n", str.c_str());
        return;
    }
    if (cnt == 10) {
        printf("Not found in 10 iterations.\n");
        return;
    }
    solve(sumStr(str), cnt + 1);
}
int main() {
    string str;
    cin >> str;
    solve(str, 0);
    return 0;
}
*/