// https://pintia.cn/problem-sets/994805342720868352/problems/994805388447170560
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
struct node{
    int amount;                 // 零售商销售总额(仅在叶子结点中有意义)
    vector<int> child;
} Node[maxn];
int n;
double p, r, ans = 0.0;

void DFS(int root, int depth){         // 深度优先计算总销售额
    if (Node[root].child.size() == 0){  // 叶子结点(即零售商)
        ans += pow(1 + r / 100, depth) * Node[root].amount;
        return;
    }
    for (int i = 0; i < Node[root].child.size(); i++){
        DFS(Node[root].child[i], depth + 1);
    }
}

int main(){
    int k, child;
    scanf("%d %lf %lf", &n, &p, &r);
    for (int i = 0; i < n; i++){
        scanf("%d", &k);
        if (k == 0){            // 叶结点标志
            scanf("%d", &Node[i].amount);
        } else {
            for (int j = 0; j < k; j++){
                scanf("%d", &child);
                Node[i].child.push_back(child);
            }
        }
    }
    DFS(0, 0);
    printf("%.1f\n", p * ans);
    return 0;
}

/*
// https://pintia.cn/problem-sets/994805342720868352/problems/994805388447170560
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 100010;
struct {
    int amount;                 // 零售商销售总额(仅在叶子结点中有意义)
    int depth;                 // 结点高度记录从供应商到经销商或零售商的转售次数.
    vector<int> child;
} node[maxn];

vector<int> retailer;           // 记录哪些结点是零售商(即叶子结点)

void BFS(int root){             // 层序遍历销售树以计算各结点深度.
    queue<int> q;
    q.push(root);
    node[root].depth = 0;
    while (!q.empty()){
        int now = q.front();
        q.pop();
        for (int i = 0; i < node[now].child.size(); i++){
            q.push(node[now].child[i]);
            node[node[now].child[i]].depth = node[now].depth + 1;
        }
    }
}

int main(){
    int n, k, child;
    double p, r;
    scanf("%d %lf %lf", &n, &p, &r);
    for (int i = 0; i < n; i++){
        scanf("%d", &k);
        if (k == 0){
            scanf("%d", &child);
            retailer.push_back(i);              // 是零售商存入容器中
            node[i].amount = child;
        } else {
            for (int j = 0; j < k; j++){
                scanf("%d", &child);
                node[i].child.push_back(child);
            }
        }
    }
    BFS(0);
    double sum = 0.0;
    for (int i = 0; i < retailer.size(); i++){      // 计算各个零售商的销售额
        int index = retailer[i];
        sum += pow(1 + r / 100, node[index].depth) * node[index].amount;
    }
    printf("%.1f\n", p * sum);
    return 0;
}

/////////////////////////////////

// https://pintia.cn/problem-sets/994805342720868352/problems/994805388447170560
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 100010;
struct {
    int amount;                 // 零售商销售总额(仅在叶子结点中有意义)
    int depth;                 // 结点高度记录从供应商到经销商或零售商的转售次数.
    vector<int> child;
} node[maxn];

double p, r, ans = 0.0;
void BFS(int root){             // 层序遍历销售树以计算各结点深度.
    queue<int> q;
    q.push(root);
    node[root].depth = 0;
    while (!q.empty()){
        int now = q.front();
        q.pop();
        if (node[now].child.size() == 0){
            ans += pow(1 + r / 100, node[now].depth) * node[now].amount;
        } else {
            for (int i = 0; i < node[now].child.size(); i++){
                q.push(node[now].child[i]);
                node[node[now].child[i]].depth = node[now].depth + 1;
            }
        }
    }
}

int main(){
    int n, k, child;
    scanf("%d %lf %lf", &n, &p, &r);
    for (int i = 0; i < n; i++){
        scanf("%d", &k);
        if (k == 0){
            scanf("%d", &child);
            node[i].amount = child;
        } else {
            for (int j = 0; j < k; j++){
                scanf("%d", &child);
                node[i].child.push_back(child);
            }
        }
    }
    BFS(0);         // 根节点开始层序遍历
    printf("%.1f\n", p * ans);
    return 0;
}
*/