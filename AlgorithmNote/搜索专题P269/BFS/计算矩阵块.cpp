/*
给出一个N×M矩阵,对于矩阵元素(x,y)称其上下左右四个位置(x,y+1),(x,y-1),(x+1,y),(x-1,y)是"相邻"的。
如果矩阵中有若干个1是相邻的(不必两两相邻),那么称这些1就构成了一个"块",求矩阵中块的个数。
 */

#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 100;

struct node {
    int x, y;
} Node;

int n, m;
int matrix[maxn][maxn] = {0};
bool inq[maxn][maxn] = {false};
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

bool judge(int x, int y){
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    if (matrix[x][y] == 0 || inq[x][y] == true) return false;
    return true;
}

void BFS(int x, int y){
    queue<node> Q;
    Node.x = x;
    Node.y = y;
    Q.push(Node);
    inq[x][y] = true;
    while (!Q.empty()){
        node top = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++){
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if (judge(newX, newY)){
                Node.x = newX;
                Node.y = newY;
                Q.push(Node);
                inq[newX][newY] = true;
            }
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            scanf("%d", &matrix[x][y]);   
        }
    }
    int ans = 0;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            if (matrix[x][y] == 1 && inq[x][y] == false){
                ans++;
                BFS(x, y);
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}

/*
6 7
0 1 1 1 0 0 1
0 0 1 0 0 0 0
0 0 0 0 1 0 0
0 0 0 1 1 1 0
1 1 1 0 1 0 0
1 1 1 1 0 0 0
4
*/