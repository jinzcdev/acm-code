// https://pintia.cn/problem-sets/1146683407522816000/problems/1192048454400258048
#include <iostream>
using namespace std;
int main() {
    int d, cnt = 0;
    while (scanf("%d", &d) != EOF) {
        cnt++;
        if (d == 250) {
            printf("%d", cnt);
            return 0;
        }
    }
    return 0;
}