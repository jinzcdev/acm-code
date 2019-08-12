// http://codeup.cn/problem.php?cid=100000608&pid=2
#include <cstdio>
const int maxn = 30;
int n, k;
int nums[maxn];
int ans[maxn] = {0};

bool isPrime(int x){
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++){
        if (x % i == 0) return false;
    }
    return true;
}

int sumP = 0;
void DFS(int index, int cnt){
    if (cnt == k){
        int sum = 0;
        for (int i = 0; i < k; i++){
            sum += ans[i];
        }
        if (isPrime(sum))
            sumP++;
    }
    for (int i = index; i < n; i++){
        ans[cnt] = nums[i];
        DFS(i + 1, cnt + 1);
    }
}

int main(){
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%d", nums + i);
    }
    DFS(0, 0);
    printf("%d", sumP);
    return 0;
}