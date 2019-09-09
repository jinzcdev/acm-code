// https://pintia.cn/problem-sets/994805342720868352/problems/994805424153280512
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 110;
struct node {
    int weight;
    vector<int> child;
} Node[maxn];

bool cmp(int a, int b){
    return Node[a].weight > Node[b].weight;
}

int n, m, s;
int path[maxn];
void DFS(int root, int numNode, int sum){
    if (sum > s) return;                    // 权值和大于要求权值, 返回上层
    if (sum == s){
        if (Node[root].child.size() != 0)
            return;                         // 权值符合, 但当前非叶子结点, 返回上层
        for (int i = 0; i < numNode; i++){
            printf("%d", Node[path[i]].weight);
            if (i < numNode - 1) printf(" ");
        }
        printf("\n");
    }
    for (int i = 0; i < Node[root].child.size(); i++){
        path[numNode] = Node[root].child[i];
        DFS(Node[root].child[i], numNode + 1, sum + Node[Node[root].child[i]].weight);   
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < n; i++){
        scanf("%d", &Node[i].weight);
    }
    int parent, child, k;
    for (int i = 0; i < m; i++){
        scanf("%d%d", &parent, &k);
        for (int j = 0; j < k; j++){
            scanf("%d", &child);
            Node[parent].child.push_back(child);
            sort(Node[parent].child.begin(), Node[parent].child.end(), cmp); // 对孩子做排序(权值较小在前)
        }
    }
    path[0] = 0;                    // 第一个路径为0 (rootIndex = 0)
    DFS(0, 1, Node[0].weight);      // 从根结点开始深度优先搜索, 初始的结点数为1, 权值和为根结点权值
    return 0;
}