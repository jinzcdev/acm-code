// http://codeup.cn/problem.php?cid=100000609&pid=1
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 10;
struct node {
    int x, y; 
} Node, U, A;

int n = 8, m = 8;
char matrix[maxn][maxn];
bool inp[maxn][maxn] = {false};
int X[9] = {0, 0, 0, 1, -1, 1, 1, -1, -1};
int Y[9] = {0, 1, -1, 0, 0, 1, -1, 1, -1};
vector<node> v;

bool test(int x, int y){
    if (x < 0 || x >= 8 || y < 0 || y >= 8) return false;
    if ((matrix[x][y] =='S') || (x >= 1 && matrix[x - 1][y] == 'S')) return false;
    if (inp[x][y] == true) return false;
    return true;
}

bool BFS(){
    queue<node> q;
    q.push(U);
    while (!q.empty()){
        node top = q.front();
        q.pop();
        if (top.x == A.x && top.y == A.y){
            return true;
        }
        for (int i = 0; i < 9; i++){
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if (test(newX, newY)){
                Node.x = newX;
                Node.y = newY;
                q.push(Node);
                inp[newX][newY] = true;
                for (vector<node>::iterator it = v.begin(); it < v.end(); it++){
                    
                }
                for (int i = 0; i < v.size(); i++){
                    matrix[v[i].x][v[i].x] = '.';
                    if (v[i].x + 1 < n){
                        matrix[v[i].x + 1][v[i].x] = 'S';                        
                    }
                }
            }
        }
        
    }
    return false;
}

int main(){
    U.x = n - 1; U.y = 0;
    A.x = 0; A.y = m - 1;
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++){
        for (int x = 0; x < n; x++){
            getchar();
            for (int y = 0; y < m; y++){
                scanf("%c", &matrix[x][y]);
                if (matrix[x][y] == 'S'){
                    node newNode;
                    newNode.x = x;
                    newNode.y = y;
                    v.push_back(newNode);
                }
            }
            matrix[x][m] = '\0';
        }
        if (i < T - 1)
            getchar();
        if (BFS()){
            printf("Case #%d: Yes\n", i + 1);
        } else {
            printf("Case #%d: No\n", i + 1);
        }
    }
    
    return 0;
}


/*
2
.......A
........
........
........
........
........
........
U.......

.......A
........
........
........
........
.S......
S..SSSSS
U.......
*/
