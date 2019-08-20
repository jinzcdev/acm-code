// https://pintia.cn/problem-sets/994805342720868352/problems/994805482919673856
#include <cstdio>
#include <cstring>
// #include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int maxn = 10010;
vector<int> G[maxn];
bool visited[maxn];
int n, maxDepth = 0, maxH = 0;
// vector<int> ans;
set<int> ans;       // 使用集合存放数据, 自动增序列, 省去升序代码

// 从某一点开始深搜遍历, 记录最深的深度
void DFS(int u, int depth){
    visited[u] = true;
    if (depth > maxDepth){
        maxDepth = depth;
    }
    for (int i = 0; i < G[u].size(); i++){
        if (!visited[G[u][i]]){
            DFS(G[u][i], depth + 1);
        }
    }
}

int main(){
    int v1, v2;
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++){
        scanf("%d%d", &v1, &v2);
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }
    int k = 0;
    for (int u = 1; u <= n; u++){       // 从第一个结点开始遍历
        if (!visited[u]){
            k++;
            DFS(u, 1);
        }
    }
    if (k > 1){                             // 判断是否是树
        printf("Error: %d components\n", k);
    } else if (k == 1) {                    // 树,从所有结点开始遍历,得到使得树高最大的结点
        for (int u = 1; u <= n; u++){
            maxDepth = 0;
            memset(visited, false, sizeof(visited));
            DFS(u, 1);                      // 根节点深度为1
            if (maxDepth > maxH) {
                ans.clear();
                ans.insert(u);
                maxH = maxDepth;
            } else if (maxDepth == maxH) {
                ans.insert(u);
            }
        }
        // sort(ans.begin(), ans.end());  // 升序结点编号
        for (set<int>::iterator it = ans.begin(); it != ans.end(); it++){
            printf("%d\n", *it);
        }
    }
    return 0;
}

/*
3
4
5

5
-------
1 3
1 4
2 5
3 4

Error: 2 components
*/