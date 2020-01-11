// https://pintia.cn/problem-sets/994805260223102976/problems/994805273883951104
#include <stdio.h>
#include <string.h>
char hand[15][10], eye[15][10], mouth[15][10];
int num[3] = {0};
int main() {
    char str[110];
    for (int i = 0; i < 3; i++) {
        fgets(str, sizeof(str), stdin);
        int len = strlen(str);
        str[--len] = '\0';
        int cnt = 1, left, right;  // cnt记录表情序号, 从索引号1开始
        for (int j = 0; j < len; j++) {
            if (str[j] == '[') left = j + 1;
            if (str[j] == ']') {
                right = j - 1;
                if (i == 0) strncpy(hand[cnt++], str + left, right - left + 1);
                else if (i == 1) strncpy(eye[cnt++], str + left, right - left + 1);
                else strncpy(mouth[cnt++], str + left, right - left + 1);
                num[i]++;
            }
        }
    }
    int k;
    scanf("%d", &k);
    int ans[5];
    while (k--) {
        bool flag = 1;
        for (int i = 0; i < 5; i++) {
            scanf("%d", &ans[i]);
            int j = i > 2 ? 5 - i - 1 : i;
            if (ans[i] > num[j] || ans[i] < 1) flag = 0;    // 输入的序号大于最大值或者小于1, 则为错误
        }
        if (!flag) printf("Are you kidding me? @\\/@\n");
        else printf("%s(%s%s%s)%s\n", hand[ans[0]], eye[ans[1]], mouth[ans[2]], eye[ans[3]], hand[ans[4]]);
    }
    return 0;
}

/*
输入样例：
[╮][╭][o][~\][/~]  [<][>]
 [╯][╰][^][-][=][>][<][@][⊙]
[Д][▽][_][ε][^]  ...
4
1 1 2 2 2
6 8 1 5 5
3 3 4 3 3
2 10 3 9 3

输出样例：
╮(╯▽╰)╭
<(@Д=)/~
o(^ε^)o
Are you kidding me? @\/@
*/