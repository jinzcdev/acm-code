#include <bits/stdc++.h>
using namespace std;
vector<int> heap;
int n;
void downAdjust(int low, int high) {
    int i = low, j = 2 * i;
    while (j <= high) {
        if (j + 1 <= high && heap[j] < heap[j + 1]) j++;
        if (heap[j] <= heap[i]) break;
        swap(heap[i], heap[j]);
        i = j;  // i与j元素交换，以j作为根的堆根节点改变需要重新调整，即向下调整(downAdjust)
        j = i * 2;
    }
}
void upAdjust(int low, int high) {
    int i = high, j = i / 2;
    while (j >= low) {
        if (heap[j] >= heap[i]) break;
        swap(heap[j], heap[i]);
        i = j;
        j = i / 2;
    }
}
void createHeap() {
    for (int i = n / 2; i >= 1; i--) {
        downAdjust(i, n);
    }
}
void deleteMax() {
    heap[1] = heap[n--];
    downAdjust(1, n);
}
void insertHeap(int x) {
    heap[++n] = x;
    upAdjust(1, n);
}
void heapSort() {
    createHeap();  // 建堆，创建大顶堆，各结点其孩子仍然无序
    for (int i = n; i > 1; i--) {
        swap(heap[i], heap[1]);  // 将堆顶元素(最大值)与最后一个元素交换
        downAdjust(1, i - 1);  // 将堆重新调整
    }
}
bool isMaxHeap() {
    for (int i = 2; i <= n; i++)
        if (heap[i / 2] < heap[i]) return false;
    return true;
}
bool isMinHeap() {
    for (int i = 2; i <= n; i++)
        if (heap[i / 2] > heap[i]) return false;
    return true;
}
bool isMaxHeapByRecursion(int i) {
    if (i > n || i * 2 > n) return true;
    if (heap[i] < heap[i * 2] || (i * 2 + 1 <= n && heap[i] < heap[i * 2 + 1]))
        return false;
    return isMaxHeapByRecursion(i * 2) && isMaxHeapByRecursion(i * 2 + 1);
}
bool isMinHeapByRecursion(int i) {
    if (i > n || i * 2 > n) return true;
    if (heap[i] > heap[i * 2] || (i * 2 + 1 <= n && heap[i] > heap[i * 2 + 1]))
        return false;
    return isMinHeapByRecursion(i * 2) && isMinHeapByRecursion(i * 2 + 1);
}
int main() {
    cin >> n;
    heap.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> heap[i];
    }
    heapSort();
    for (int i = 1; i <= n; i++) {
        cout << heap[i] << " ";
    }
    return 0;
}