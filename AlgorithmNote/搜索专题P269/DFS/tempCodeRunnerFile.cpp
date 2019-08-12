// http://codeup.cn/problem.php?cid=100000608&pid=3
#include <cstdio>
#include <cmath>
const int maxn = 20;
int ans[maxn];
bool visited[maxn] = {false};
int n, cnt = 0;

void DFS(int index){
    if (index == n){
        bool flag = true;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if (fabs(i - j) == fabs(ans[i] - ans[j]))
                    flag = false;
            }
        }
        if (flag){
            for (int i = 0; i < n; i++){
                printf("%d", ans[i]);
                if (i < n - 1) printf(" ");
            }
            printf("\n");
        }
        return;
    }
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            ans[index] = i;
            visited[i] = true;
            DFS(index + 1);
            visited[i] = false;
        }
    }
}

int main(){
    scanf("%d", &n);
    DFS(0);
    return 0;
}