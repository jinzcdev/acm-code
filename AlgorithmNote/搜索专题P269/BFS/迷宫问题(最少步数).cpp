/*
> 给定一个 n*m的大小的迷宫,其中"*"号代表不可通过的城墙壁,而"."代表平地,S代表起点,T代表终点. 
移动过程中,如果当前位置是(x,y)(下标从0开始),且每次只能往上下左右(x,y+1),(x,y-1),(x-1,y),(x+1,y)四个位置的平地,
求从起点S到达终点T的最少步数.
*/

#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 100;
struct node {
    int x, y;
    int step;
} S, T, Node;

int n, m;
char matrix[maxn][maxn];
bool inq[maxn][maxn] = {false};
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

bool test(int x, int y){
    if (x < 0 || x > n || y < 0 || y > m) return false;
    if (matrix[x][y] == '*' || inq[x][y] == true) return false;
    return true;
}

int BFS(){
    queue<node> Q;
    Q.push(S);
    while (!Q.empty()){
        node top = Q.front();
        Q.pop();
        if (top.x == T.x && top.y == T.y){
            return top.step;
        }
        for (int i = 0; i < 4; i++){
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if (test(newX, newY)){
                Node.x = newX;
                Node.y = newY;
                Node.step = top.step + 1;
                Q.push(Node);
                inq[newX][newY] = true;
            }
        }
    }
    return -1;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int x = 0; x < n; x++){
        getchar();
        for (int y = 0; y < m; y++){
            scanf("%c", &matrix[x][y]);
        }
        matrix[x][m] = '\0';
    }
    scanf("%d%d%d%d", &S.x, &S.y, &T.x, &T.y);
    S.step = 0;
    printf("%d\n", BFS());
    return 0;
}

/*
5 5
.....
.*.*.
.*S*.
.***.
...T*
2 2 4 3
*/