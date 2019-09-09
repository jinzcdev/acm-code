// https://pintia.cn/problem-sets/994805342720868352/problems/994805444361437184
#include <cstdio>
const int maxn = 100010;
int num[maxn], exist[maxn] = {0};
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", num + i);
        exist[num[i]]++;            // 记录所有数出现的次数
    }
    for (int i = 0; i < n; i++){
        if (exist[num[i]] == 1){    // 第一个只出现一次的数即为Unique
            printf("%d", num[i]);
            return 0;
        }
    }
    printf("None");
    return 0;
}