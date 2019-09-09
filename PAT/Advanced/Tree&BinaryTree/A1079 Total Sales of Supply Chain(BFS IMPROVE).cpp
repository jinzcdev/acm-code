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