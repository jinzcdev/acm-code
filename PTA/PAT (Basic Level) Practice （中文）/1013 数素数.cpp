// https://pintia.cn/problem-sets/994805260223102976/problems/994805309963354112
#include <cstdio>
bool isPrime(int x){
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++){
        if (x % i == 0) return false;
    }
    return true;
}

int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    int num = n - m + 1, p = 1, cnt = 0;    // num为一共要输出的素数总数
    while (cnt < m - 1){                    // 使p从第m个数开始
        if (isPrime(p++))
            cnt++;
    }
    cnt = 0;
    int cntP = 0;           // 标记素数的个数, 每到10次, 重新置0
    while (cnt < num){
        if (isPrime(p)){
            printf("%d", p);
            if (++cntP < 10 && cnt < num - 1) printf(" ");  // 10个素数之内且未到最后一个素数则输出空格
            else {
                printf("\n");
                cntP = 0;
            }
            cnt++;
        }
        p++;                // 用以遍历所有数也取出素数
    }
    return 0;
}