#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
vector<int> heap;
bool isMaxHeap(int i) {
    if (i > n || i * 2 > n) return true;
    if (heap[i] < heap[i * 2] || (i * 2 + 1 <= n && heap[i] < heap[i * 2 + 1]))
        return false;
    return isMaxHeap(i * 2) && isMaxHeap(i * 2 + 1);
}
bool isMinHeap(int i) {
    if (i > n || i * 2 > n) return true;
    if (heap[i] > heap[i * 2] || (i * 2 + 1 <= n && heap[i] > heap[i * 2 + 1]))
        return false;
    return isMinHeap(i * 2) && isMinHeap(i * 2 + 1);
}
void postOrder(int i) {
    if (i > n) return;
    postOrder(i * 2);
    postOrder(i * 2 + 1);
    printf("%d", heap[i]);
    if (++cnt < n) printf(" ");
}
int main() {
    cin >> m >> n;
    heap.resize(n + 1);
    for (int i = 0; i < m; i++) {
        for (int i = 1; i <= n; i++) scanf("%d", &heap[i]);
        // if (isMaxHeap(1)) printf("Max Heap\n");
        // else if (isMinHeap(1)) printf("Min Heap\n");
        // else printf("Not Heap\n");
        bool ismax = true, ismin = true;
        for (int j = 2; j <= n; j++) {
            if (heap[j / 2] < heap[j]) ismax = false;
            if (heap[j / 2] > heap[j]) ismin = false;
        }
        if (ismax) printf("Max Heap\n");
        else if (ismin) printf("Min Heap\n");
        else printf("Not Heap\n");
        cnt = 0;
        postOrder(1);
        printf("\n");
    }
    return 0;
}