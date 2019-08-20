// https://pintia.cn/problem-sets/994805342720868352/problems/994805500414115840
#include <cstdio>
const int maxn = 1010;
int G[maxn][maxn], visited[maxn];
int n, m, k;
int main(){
    int v1, v2, city;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++){
        scanf("%d%d", &v1, &v2);
        G[v1][v2] = G[v2][v1] = 1;  // v1,v2间存在边, 由于不含边权, 故可在矩阵中标记任意正数(此处记为1)
    }
    for (int i = 0; i < k; i++){
        scanf("%d", &city);
        // printf("%d\n", DFSTraverse(city));
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