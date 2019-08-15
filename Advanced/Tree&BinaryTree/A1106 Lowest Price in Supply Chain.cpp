// https://pintia.cn/problem-sets/994805342720868352/problems/994805362341822464
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
vector<int> tree[maxn];         // 不含数据域,简易表示树结构
int n;
double p, r;

int minDepth = maxn, cnt = 0;   // 记录最小深度(即从供应商到销售商的转售次数)
void DFS(int root, int depth){
    if (tree[root].size() == 0){
        if (depth < minDepth){
            minDepth = depth;
            cnt = 1;
        } else if (depth == minDepth){
            cnt++;
        }
        return;
    }
    for (int i = 0; i < tree[root].size(); i++){
        DFS(tree[root][i], depth + 1);
    }
}

int main(){
    scanf("%d%lf%lf", &n, &p, &r);
    int k, child;
    for (int i = 0; i < n; i++){
        scanf("%d", &k);
        for (int j = 0; j < k; j++){
            scanf("%d", &child);
            tree[i].push_back(child);
        }
    }
    DFS(0, 0);  // 从根结点开始深度优先搜索
    printf("%.4f %d\n", p * pow(1 + r / 100, minDepth), cnt);
    return 0;
}