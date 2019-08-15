// https://pintia.cn/problem-sets/994805342720868352/problems/994805389634158592
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 10010;
bool hashTable[maxn] = {false};

bool isPrime(int x){
    if (x <= 1) return false;
    int sqr = (int)sqrt(x * 1.0);
    for (int i = 2; i <= sqr; i++){
        if (x % i == 0) return false;
    }
    return true;
}

int main(){
    int TSize, n;
    scanf("%d%d", &TSize, &n);
    while (!isPrime(TSize)){        // 找到从当前数开始第一个素数
        TSize++;
    }
    int x, key;
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        key = x % TSize;
        if (!hashTable[key]){
            printf("%d", key);
            hashTable[key] = true;
        } else {
            int step;
            for (step = 1; step < TSize; step++){   // 二次方探查法 x+1^2, x+2^2, ...
                key = (x + step * step) % TSize;
                if (!hashTable[key]){
                    printf("%d", key);
                    hashTable[key] = true;          // 标记该key已存在
                    break;                          // 得到新的key退出循环
                }
            }
            if (step >= TSize){
                printf("-");                        // 全部探查完未找到解决冲突后的新key
            }
        }
        if (i < n - 1) printf(" ");
    }
    return 0;
}