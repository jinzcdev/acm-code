// https://pintia.cn/problem-sets/994805342720868352/problems/994805376476626944
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
vector<int> child[maxn];            // 树结构中不含数据域, 简略写法

int n, cnt = 0;
double p, r, maxDepth = 0;          // 记录最大深度(即销售价格的最大乘方次数)
void DFS(int root, int depth){
    if (child[root].size() == 0){   // 到达叶子结点
        if (depth > maxDepth){
            maxDepth = depth;
            cnt = 1;
        } else if (depth == maxDepth){
            cnt++;                  // 含有最大销售额的零售商个数加1
        }
        return;
    }
    for (int i = 0; i < child[root].size(); i++){
        DFS(child[root][i], depth + 1);
    }
}

int main(){
    scanf("%d%lf%lf", &n, &p, &r);
    int root, parent;
    for (int i = 0; i < n; i++){
        scanf("%d", &parent);
        if (parent != -1){
            child[parent].push_back(i);
        } else {
            root = i;
        }
    }
    DFS(root, 0);
    printf("%.2f %d", p * pow(1 + r / 100, maxDepth), cnt);
    return 0;
}