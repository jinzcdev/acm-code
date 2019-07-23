#include <cstdio>
const int maxn = 15000;
bool ans[maxn];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        int x = i / 2 + i / 3 + i / 5;
        ans[x] = true;
    }
    int cnt = 0;
    for (int i = 0; i < maxn; i++){
        if (ans[i])
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}