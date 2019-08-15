// https://pintia.cn/problem-sets/994805342720868352/problems/994805495863296000
#include <cstdio>
const int maxn = 15;

bool isPrime(int x){
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++){
        if (x % i == 0) return false;
    }
    return true;
}

int reverse(int n, int d){
    int cnt = 0, number[maxn];
    while (n != 0){                 // 循环转为D进制数
        number[cnt++] = n % d;
        n /= d;
    }
    int sum = 0;
    for (int i = 0; i < cnt; i++){  // 得到的数组为逆序结果, 题目要求反转, 恰好略过此步骤
        sum = sum * d + number[i];
    }
    return sum;
}

int main(){
    int n, d;
    while(scanf("%d%d", &n, &d) != EOF){
        if (n < 0) break;
        if (isPrime(n) && isPrime(reverse(n, d))){
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}