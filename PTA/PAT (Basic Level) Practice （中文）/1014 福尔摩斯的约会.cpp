// https://pintia.cn/problem-sets/994805260223102976/problems/994805308755394560
#include <bits/stdc++.h>
using namespace std;
char week[][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main() {
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    char a, b;
    int pos = 0, mm;
    for (; pos < s1.size() && pos < s2.size(); pos++) {
        if (s1[pos] == s2[pos] && (s1[pos] >= 'A' && s1[pos] <= 'G')) {
            a = s1[pos];
            break;
        }
    }
    pos++;
    for (; pos < s1.size() && pos < s2.size(); pos++) {
        if (s1[pos] == s2[pos] &&
            (isdigit(s1[pos]) || (s1[pos] >= 'A' && s1[pos] <= 'N'))) {
            b = s1[pos];
            break;
        }
    }
    for (int i = 0; i < s3.size() && i < s4.size(); i++) {
        if (s3[i] == s4[i] && isalpha(s3[i])) {
            mm = i;
            break;
        }
    }
    printf("%s ", week[a - 'A']);
    if (isdigit(b)) printf("%02d", b - '0');
    else printf("%02d", b - 'A' + 10);
    printf(":%02d", mm);
    return 0;
}