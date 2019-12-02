// https://pintia.cn/problem-sets/994805342720868352/problems/994805345732378624
#include <iostream>
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
}