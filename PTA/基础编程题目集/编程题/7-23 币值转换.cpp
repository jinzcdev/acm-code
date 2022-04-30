// https://pintia.cn/problem-sets/14/problems/803
// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     int a;
//     cin >> a;

// }

#include <stdio.h>
#include <string.h>

char number[10] = {'a', 'a', 'S', 'B', 'Q', 'W', 'S', 'B', 'Q', 'Y'};
char money[10];
int main() {
    scanf("%s", money);
    int len = strlen(money);
    if (len == 1)
        printf("%c", money[0] - '0' + 97);
    else {
        for (int i = 0; i < len; i++) {
            if (money[i] != '0')
                printf("%c%c", money[i] - '0' + 97, number[len - i]);
            else if (i < len - 1 && i != len - 5 && money[i] - '0' == 0 &&
                     money[i + 1] - '0' != 0)
                printf("%c", money[i] - '0' + 97);
            else if (len > 5 && i == len - 5 && money[i] - '0' == 0) {
                if (len == 9 && money[i] - '0' == 0 && money[2] - '0' == 0 &&
                    money[3] - '0' == 0) {
                } else
                    printf("W");
            }
        }
    }
    printf("\n");
    return 0;
}