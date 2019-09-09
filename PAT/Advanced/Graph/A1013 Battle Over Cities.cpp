// https://pintia.cn/problem-sets/994805342720868352/problems/994805500414115840
#include <cstdio>
const int maxn = 1010;
int G[maxn][maxn], visited[maxn];
int n, m, k;

void DFS(int u, int city){
    // if (u == city) return;
    visited[u] = true;                  // 标记当前结点为已访问
    for (int v = 1; v <= n; v++){
        // 访问所有相连且未被访问过的结点, 由于被占领城市不可达, 故当前结点不是被占领城市时才可访问
        if (G[u][v] > 0 && !visited[v] && v != city){ // 此处的v!=city可与首行中的注释代码替换
            DFS(v, city);
        }
    }
}

int DFSTraverse(int city){
    int ans = 0;
    for (int i = 1; i <= n; i++){
        visited[i] = false;
    }
    for (int i = 1; i <= n; i++){
        if (i == city) continue;    // 别占领的城市已从图中脱离, 故直接跳过此结点
        if (!visited[i]){           // if块的执行次数即连通子图的个数
            ans++;
            DFS(i, city);
        }
    }
    return ans - 1;                 // 连通子图个数-1得到可使其连通的边数
}

int main(){
    int v1, v2, city;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++){
        scanf("%d%d", &v1, &v2);
        G[v1][v2] = G[v2][v1] = 1;  // v1,v2间存在边, 由于不含边权, 故可在矩阵中标记任意正数(此处记为1)
    }
    for (int i = 0; i < k; i++){
        scanf("%d", &city);
        printf("%d\n", DFSTraverse(city));
    }
    return 0;
}

/*
Sample Input:
3 2 3
1 2
1 3
1 2 3

Sample Output:
1
0
0
*/