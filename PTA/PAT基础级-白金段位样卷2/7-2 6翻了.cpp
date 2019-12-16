// https://pintia.cn/problem-sets/1146683407522816000/problems/1192048511707033600
#include <iostream>
using namespace std;
int main() {
    string str;
    getline(cin, str);
    int cnt = 0;
    bool flag = false;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '6') {
            cnt++;
            flag = true;
        } else {
            if (flag) {
                if (cnt <= 3) for (int j = 0; j < cnt; j++) printf("6");
                else if (cnt <= 9) printf("9");
                else printf("27");
                cnt = 0;
                flag = false;
            }
            printf("%c", str[i]);
        }
    }
    if (flag) {
        if (cnt <= 3) for (int j = 0; j < cnt; j++) printf("6");
        else if (cnt <= 9) printf("9");
        else printf("27");
    }
    return 0;
}