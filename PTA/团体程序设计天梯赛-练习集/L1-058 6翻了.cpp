// https://pintia.cn/problem-sets/994805046380707840/problems/1111914599408664577
#include <cstdio>
int main() {
    char ch;
    int cnt = 0;
    while (scanf("%c", &ch) != EOF) {
        if (ch != '6') {
            if (cnt > 0) {
                if (cnt <= 3) for (int i = 0; i < cnt; i++) printf("6");
                else printf("%d", cnt <= 9 ? 9 : 27);
            }
            printf("%c", ch);
            cnt = 0;
        } else
            cnt++;
    }
    return 0;
}