#include <cstdio>
bool isPrime(int x){
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++){
        if (x % i == 0) return false;
    }
    return true;
}
int isSexy(int n){
    if (isPrime(n) && isPrime(n - 6)) return n - 6;
    else if (isPrime(n) && isPrime(n + 6)) return n + 6;
    return -1;
}

int main(){
    int n;
    scanf("%d", &n);
    int ans = isSexy(n);
    if (ans != -1){
        printf("Yes\n%d", ans);
    } else {
        n++;
        while (isSexy(n) == -1) {
            n++;
        }
        printf("No\n%d", n);
    }
    return 0;
}