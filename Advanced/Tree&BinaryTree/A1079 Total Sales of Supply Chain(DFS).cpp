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