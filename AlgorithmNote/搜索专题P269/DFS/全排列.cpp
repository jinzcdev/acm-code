// http://codeup.cn/problem.php?cid=100000608&pid=0
#include <cstdio>
const int maxn = 15;
int isVisit[maxn] = {false}; 
int ans[maxn] = {0};
int n;

void DFS(int cnt){
    if (cnt == n){
        for (int i = 0; i < n; i++){
            printf("%d", ans[i]);
            if (i < n) printf(" ");
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++){
        if (!isVisit[i]){
            ans[cnt] = i;
            isVisit[i] = true;
            DFS(cnt + 1);
            isVisit[i] = false;
        }
    }
}

int main(){
    scanf("%d", &n);
    DFS(0);
    return 0;
}