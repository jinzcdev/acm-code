// http://codeup.cn/problem.php?cid=100000608&pid=1
#include <cstdio>
const int maxn = 30;
bool visit[maxn] = {false};
int ans[maxn] = {0};
int n, r;

void DFS(int index, int cnt){
    if (cnt == r){
        for (int i = 0; i < r; i++){
            printf("%d", ans[i]);
            if(i < r - 1) printf(" ");
        }
        printf("\n");
    }
    for (int i = index; i <= n; i++){
        ans[cnt] = i;
        DFS(i + 1, cnt + 1);
    }   
}

int main(){
    scanf("%d%d", &n, &r);
    DFS(1, 0);
    return 0;
}