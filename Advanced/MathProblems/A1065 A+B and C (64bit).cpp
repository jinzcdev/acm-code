// https://pintia.cn/problem-sets/994805342720868352/problems/994805406352654336
/**
 * 题目给定的数值范围为8字节, 刚好与long long类型匹配,
 * 但两数相加减存在溢出的情况, 于是如果a,b均为正但a+b<0则说明溢出,a+b的实际大小必定>c, a,b均为负的情况与此相同.
 */ 
#include <cstdio>
int main(){
    int n;
    long long a, b, c, sum;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%lld%lld%lld", &a, &b, &c);
        sum = a + b;
        if (a > 0 && b > 0 && sum < 0) {
            printf("Case #%d: true\n", i);
        } else if (a < 0 && b < 0 && sum >= 0) {
            printf("Case #%d: false\n", i);            
        } else if (a + b > c) {
            printf("Case #%d: true\n", i);
        } else {
            printf("Case #%d: false\n", i);            
        }
    }
    return 0;
}

/*
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0

Case #1: false
Case #2: true
Case #3: false
*/