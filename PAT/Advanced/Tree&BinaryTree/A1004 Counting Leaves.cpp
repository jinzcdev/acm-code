// https://pintia.cn/problem-sets/994805342720868352/problems/994805521431773184
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 110;
vector<int> tree[maxn];
int n, m;

int ans[maxn] = {0}, maxDepth = 1;  // ans记录每一层的叶子结点数, 索引号为层数

void DFS(int root, int depth){
    if (tree[root].size() == 0){
        ans[depth]++;
        if (depth > maxDepth){
            maxDepth = depth;       // 记录该树的最大层数
        }
        return;
    }
    for (int i = 0; i < tree[root].size(); i++){
        DFS(tree[root][i], depth + 1);
    }
}

int h[maxn] = {0};  // 记录各结点深度(即层数)
void BFS(int root){
    queue<int> q;
    q.push(root);
    h[root] = 1;    // 初始化根结点的高度为 1
    while (!q.empty()){
        int front = q.front();
        q.pop();
        if (tree[front].size() == 0){
            ans[h[front]]++;
        }
        maxDepth = max(h[front], maxDepth);
        for (int i = 0; i < tree[front].size(); i++){
            h[tree[front][i]] = h[front] + 1;
            q.push(tree[front][i]);
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    int k, parent, child;
    for (int i = 0; i < m; i++){
        scanf("%d%d", &parent, &k);
        for (int j = 0; j < k; j++){
            scanf("%d", &child);
            tree[parent].push_back(child);
        }
    }
    DFS(1, 1);      // Solution 1: 根结点开始深度优先搜索, 第一层深度为1
    // BFS(1);      // Solution 2: 根结点开始广度优先搜索, root = 1
    for (int i = 1; i <= maxDepth; i++){
        printf("%d", ans[i]);
        if (i < maxDepth) printf(" ");
    }
    return 0;
}


/*
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 110;
vector<int> G[N];
int leaf[N] = {0};
int max_h = 1;

void DFS(int index,int h){
    max_h = max(h,max_h);
    if(G[index].size() == 0){
        leaf[h]++;
        return;
    }
    for(int i = 0; i < G[index].size(); i++){
        DFS(G[index][i],h + 1);
    }
}

int main(){
    int n,m,parent,child,k;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < m; i++){
        scanf("%d%d",&parent,&k);
        while(k--){
            scanf("%d",&child);
            G[parent].push_back(child);
        }
    }
    DFS(1,1);
    printf("%d",leaf[1]);
    for(int i = 2;i <= max_h; i++)
        printf(" %d",leaf[i]);
    return 0;
}
*/