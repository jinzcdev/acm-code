// https://pintia.cn/problem-sets/994805342720868352/problems/994805372601090048
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
vector<int> e[N];
int maxCnt = -1, level = -1;
unordered_map<int, int> cnt;
void dfs(int u, int depth) {
    if (++cnt[depth] > maxCnt) {
        maxCnt = cnt[depth];
        level = depth;
    }
    if (e[u].size() == 0) return;
    for (auto it : e[u]) dfs(it, depth + 1);
}
int main() {
    int n, m, k, u, v;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &u, &k);
        while (k--) {
            scanf("%d", &v);
            e[u].push_back(v);
        }
    }
    dfs(1, 1);
    printf("%d %d\n", maxCnt, level);
    return 0;
}

/*
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 110;
vector<int> tree[maxn];
int n, m;
int hashTable[maxn] = {0}, maxDepth = 0;    // hashTable存放每一辈的人数,索引号为辈分号

void DFS(int root, int depth){
    hashTable[depth]++;
    if (depth > maxDepth){
        maxDepth = depth;
    }
    for (int i = 0; i < tree[root].size(); i++){
        DFS(tree[root][i], depth + 1);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    int parent, num, child;
    for (int i = 0; i < m; i++){
        scanf("%d%d", &parent, &num);           // 读入父结点索引与其孩子个数
        for (int j = 0; j < num; j++){
            scanf("%d", &child);
            tree[parent].push_back(child);
        }
    }
    DFS(1, 1);
    int maxValue = 0, maxGen;
    for (int i = 1; i <= maxDepth; i++){
        if (hashTable[i] > maxValue){
            maxValue = hashTable[i];
            maxGen = i;
        }
    }
    printf("%d %d\n", maxValue, maxGen);
    return 0;
}
*/