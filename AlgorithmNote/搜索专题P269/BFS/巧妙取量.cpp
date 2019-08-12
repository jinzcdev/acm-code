// http://codeup.cn/problem.php?cid=100000609&pid=4
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1000000;

struct node {
    int container[3];   // 三个容器的当前水量 0:a, 1:b, 2:c
    int step;           // 当前倒水的次数
    int from;           // 标记从哪一容器倒水给另外两个容器, 编号:0,1,2
} Node, S;

int volumn[3];      // 三个容器的容量 0:a, 1:b, 2:c
bool inp[maxn] = {false};
int minCnt = maxn;
int k;

int hashFunc(node N){
    int id = 0;
    for (int i = 0; i < 3; i++){
        id = id * 100 + N.container[i];
    }
    return id;
}

// 倒水
node water(node N, int to){
    node newNode = N;
    int temp = newNode.container[newNode.from] + newNode.container[to];
    if (temp >= volumn[to]){
        newNode.container[to] = volumn[to];
        newNode.container[newNode.from] = temp - volumn[to];
    } else {
        newNode.container[to] = temp;
        newNode.container[newNode.from] = 0;
    }
    newNode.step++;
    newNode.from = to;
    return newNode;
}

int BFS(){
    queue<node> q;
    S.container[0] = volumn[0];
    S.container[1] = 0;
    S.container[2] = 0;
    S.step = 0;
    S.from = 0;
    q.push(S);
    while (!q.empty()){
        node top = q.front();
        q.pop();
        if (top.container[0] == k || top.container[1] == k || top.container[2] == k){
            return top.step;
        }
        for (int i = 0; i < 3; i++){
            if (top.from != i){
                node N = water(top, i);
                int id = hashFunc(N);
                if (!inp[id]){
                    q.push(N);
                    inp[id] = true;
                }
            }
        }
    }
    return -1;
}

int main(){
    // scanf("%d%d%d%d", &volumn[0], &volumn[1], &volumn[2], &k);
    volumn[0] = 10;
    volumn[1] = 7;
    volumn[2] = 3;
    k = 5;
    int ans = BFS();
    if (ans != -1){
        printf("yes\n%d", ans);
    } else {
        printf("no\n");
    }
    return 0;
}