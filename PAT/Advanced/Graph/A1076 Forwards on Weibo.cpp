// https://pintia.cn/problem-sets/994805342720868352/problems/994805392092020736
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
vector<int> e[N];
int n, l, k, temp;
int bfs(int u) {
    queue<int> q;
    q.push(u);
    int ans = 0, depth[N] = {0};
    bool inq[N] = {false};
    inq[u] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        ans++;
        if (depth[now] >= l) continue;
        for (auto it : e[now]) {
            if (!inq[it]) {
                q.push(it);
                depth[it] = depth[now] + 1;
                inq[it] = true;
            }
        }
    }
    return ans;
}
int main() {
    scanf("%d%d", &n, &l);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &temp);
            e[temp].push_back(i);
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &temp);
        printf("%d\n", bfs(temp) - 1);
    }
    return 0;
}

/*
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1010;
struct node {
    int id;
    int layer;
} start, user;
vector<node> G[maxn];           // 邻接表存储图
int n, L;
bool inq[maxn];                 // 标记结点是否已入队

int BFS(int s){                 // s -- start: 层序遍历起始结点
    int ans = 0;                // 重置转发次数
    // memset(inq, false, sizeof(inq));  重置inq为false以做下一次的遍历,
谨慎使用memset函数 for (int i = 1; i <= n; i++){ inq[i] = false;
    }
    queue<node> q;
    start.id = s;
    start.layer = 1;
    q.push(start);
    while (!q.empty()){
        node now = q.front();
        q.pop();
        int parent = now.id;
        inq[parent] = true;
        for (int i = 0; i < G[parent].size(); i++){
            node next = G[parent][i];
            next.layer = now.layer + 1;
            // 起始结点层号为1, L为间接转发的记录层数, 例:L=2,
则记录2,3层结点数(即1,2的连接结点数) if (!inq[next.id] && now.layer <= L){
                q.push(next);
                inq[next.id] = true;
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    scanf("%d%d",&n, &L);
    int m, id, k;
    for (int i = 1; i <= n; i++){
        scanf("%d", &m);
        user.id = i;
        user.layer = 1;
        for (int j = 0; j < m; j++){
            scanf("%d", &id);
            G[id].push_back(user);
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        scanf("%d", &id);
        printf("%d\n", BFS(id));
    }
    return 0;
}


Sample Input:
7 3
3 2 3 4     // 表示1号用户关注了2,3,4号
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6

Sample Output:
4
5

*/