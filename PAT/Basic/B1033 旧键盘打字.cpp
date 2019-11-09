// https://pintia.cn/problem-sets/994805260223102976/problems/994805288530460672
/* Method 1:
#include <iostream>
#include <cctype>
using namespace std;
int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    bool bk[256];
    for (int i = 0; i < s1.length(); i++) {
        bk[s1[i]] = true;
        if (isupper(s1[i])) bk[tolower(s1[i])] = true;
    }
    if (bk['+']) {
        for (int i = 0; i < 26; i++) {
            bk['A' + i] = true;
        }
    }
    for (int i = 0; i < s2.length(); i++) {
        if (!bk[s2[i]]) cout << s2[i];
    }
    return 0;
}
*/

#include <iostream>
#include <cctype>
using namespace std;
int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for (int i = 0; i < s2.length(); i++) {
        if (s1.find(toupper(s2[i])) != string::npos) continue;
        if (isupper(s2[i]) && s1.find('+') != string::npos) continue;
        cout << s2[i];
    }
    return 0;
}