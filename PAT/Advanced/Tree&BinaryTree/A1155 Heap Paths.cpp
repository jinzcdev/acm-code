// https://pintia.cn/problem-sets/994805342720868352/problems/1071785408849047552
#include <bits/stdc++.h>
using namespace std;
vector<int> heap, path;
int n;
void dfs(int i) {
    if (i > n) return;
    if (i * 2 > n) {
        path.push_back(heap[i]);
        for (int i = 0; i < path.size(); i++) {
            if (i != 0) printf(" ");
            printf("%d", path[i]);
        }
        printf("\n");
        path.pop_back();
        return;
    }
    path.push_back(heap[i]);
    dfs(i * 2 + 1);
    dfs(i * 2);
    path.pop_back();
}
int main() {
    scanf("%d", &n);
    heap.resize(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &heap[i]);
    dfs(1);
    bool isMaxHeap = true, isMinHeap = true;
    for (int i = 2; i <= n; i++) {
        if (heap[i] > heap[i / 2]) isMaxHeap = false;
        if (heap[i] < heap[i / 2]) isMinHeap = false;
    }
    if (isMaxHeap) printf("Max Heap\n");
    else if (isMinHeap) printf("Min Heap\n");
    else printf("Not Heap\n");
    return 0;
}

/*
bool isMaxHeap(int i) {
    if (i > n || i * 2 > n) return true;  // 空树或者没有孩子结点为true
    if ((heap[i * 2] > heap[i]) || (i * 2 + 1 <= n && heap[i * 2 + 1] > heap[i])) return false;
    return isMaxHeap(i * 2) && isMaxHeap(i * 2 + 1);
}
bool isMinHeap(int i) {
    if (i > n || i * 2 > n) return true;  // 空树或者没有孩子结点为true
    if ((heap[i * 2] < heap[i]) || (i * 2 + 1 <= n && heap[i * 2 + 1] < heap[i])) return false;
    return isMinHeap(i * 2) && isMinHeap(i * 2 + 1);
}
*/

/*
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1010;
int Node[maxn], level[maxn], n, pos = 1;
vector<int> path;
int numPath = 0, numMax = 0, numMin = 0;
bool invalid = false;

bool inc() {
    for (int i = path.size() - 1; i >= 1; i--) {
        if (Node[path[i]] > Node[path[i - 1]]) {
            return false;
        }
    }
    return true;
}

bool dec() {
    for (int i = path.size() - 1; i >= 1; i--) {
        if (Node[path[i]] < Node[path[i - 1]]) {
            return false;
        }
    }
    return true;
}

void DFS(int root) {
    path.push_back(root);
    if (root * 2 > n) {
        for (int i = 0; i < path.size(); i++) {
            if (i != 0) printf(" ");
            printf("%d", Node[path[i]]);
        }
        printf("\n");
        if (inc()) numMax++;
        else if (dec()) numMin++;
        else invalid = true;
        numPath++;
        path.pop_back();
        return;
    }
    if (root * 2 + 1 <= n) DFS(root * 2 + 1);
    if (root * 2 <= n) DFS(root * 2);
    path.pop_back();
}

void levelOrder(int root){
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        Node[now] = level[pos++];
        if (now * 2 <= n) q.push(now * 2);
        if (now * 2 + 1 <= n) q.push(now * 2 + 1);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", level + i);
    }
    levelOrder(1);
    DFS(1);
    if (numMax == numPath) printf("Max Heap\n");
    else if (numMin == numPath) printf("Min Heap\n");
    else printf("Not Heap\n");
    return 0;
}
*/