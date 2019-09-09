// https://pintia.cn/problem-sets/994805342720868352/problems/994805514284679168
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int dp[maxn], A[maxn];
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", A + i);
    }
    dp[0] = A[0];
    int left, right;
    for (int i = 1; i < n; i++){
        dp[i] = max(dp[i - 1] + A[i], A[i]);
        if (dp[i - 1] > A[i]) {
            right = i - 1;
        } else {
            left = i;
        }
    }
    int k = 0;
    for (int i = 1; i < n; i++){
        if (dp[i] > dp[k]) {
            k = i;
        }
    }
    printf("%d %d %d\n", dp[k], A[left], A[right]);
    return 0;
}