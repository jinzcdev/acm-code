#include <cstdio>
#include <cstring>
const int maxn = 1010;

int main(){
    char a[maxn];
    int b, r, ans[maxn];
    scanf("%s %d", a, &b);
    int len = strlen(a), cnt = 0, num = 0;  // num是每一次计算时与除数做运算的数字
    for (int i = 0; i < len; i++){
        num = 10 * num + (a[i] - '0');      // 前面的结果*10加上当前数字得到新的运算数
        ans[cnt++] = num / b;               // 除以除数得到当前位上的结果
        num = num % b;                      // 对除数取余得到差值
    }
   
    int i = 0;
    while(cnt > 1 && ans[i] == 0)   // 结果超过两位数时,找到第一个不为0的数(前面多余的0不作输出)
        i++;
    for ( ; i < cnt; i++){
        printf("%d", ans[i]);
    }
    printf(" %d", num);
    
    return 0;
}