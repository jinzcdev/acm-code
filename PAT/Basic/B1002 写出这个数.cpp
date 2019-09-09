// https://pintia.cn/problem-sets/994805260223102976/problems/994805324509200384
#include <cstdio>
#include <cstring>
const int maxn = 110;
char n[maxn];
char change[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int ans[10] = {0};

int main(){
    scanf("%s", n);
    int len = strlen(n), num = 0, sum = 0;
    for (int i = 0; i < len; i++)
        sum += n[i] - '0';

    // 逐位取数
    while (sum != 0){
        ans[num++] = sum % 10;
        sum = sum / 10;
    }
    // 逆序输出数字
    for (int i = num - 1; i >= 0; i--){
        printf("%s", change[ans[i]]);
        if (i != 0)
            printf(" ");    // 最后不输出空格
    }
    return 0;
}