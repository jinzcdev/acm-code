// https://pintia.cn/problem-sets/1203317812083417088/problems/1203317880077287426
#include <iostream>
#include <map>
using namespace std;
int main() {
    int cntStr[10] = {0}, len = 0, cnt = 0;
    char ch;
    while (scanf("%c", &ch), ch != '\n') {
        switch (ch) {
            case 'S': cntStr[0]++; break;
            case 't': cntStr[1]++; break;
            case 'r': cntStr[2]++; break;
            case 'i': cntStr[3]++; break;
            case 'n': cntStr[4]++; break;
            case 'g': cntStr[5]++; break;
            default: break;
        }
    }
    for (int i = 0; i < 6; i++) len += cntStr[i];
    string str = "String";
    for (int i = 0; i < 6; ) {
        ch = str[i];
        if (cntStr[i]-- > 0) {
            printf("%c", ch);
            cnt++;
        }
        if (cnt == len) break;
        if (++i == 6) i = 0;
    }
    return 0;
}