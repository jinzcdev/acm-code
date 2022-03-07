#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int heap[N], n;
void downAdjust(int low, int high) {
    int i = low, j = i * 2;
    while (j <= high) {
        if (j + 1 <= high && heap[j + 1] > heap[j]) j++;
        if (heap[i] >= heap[j]) break;
        swap(heap[i], heap[j]);
        i = j;
        j = i * 2;
    }
}
void upAdjust(int low, int high) {
    int i = high, j = i / 2;
    while (j >= low) {
        if (heap[i] <= heap[j]) break;
        swap(heap[i], heap[j]);
        i = j;
        j = i / 2;
    }
}
void insertHeap(int x) {
    heap[++n] = x;
    upAdjust(1, n);
}
int deleteMax() {
    int root = heap[1];
    heap[1] = heap[n--];
    downAdjust(1, n);
    return root;
}
void createHeap() {
    for (int i = n / 2; i >= 1; i--) {
        downAdjust(i, n);
    }
}
void heapSort() {
    createHeap();
    for (int i = n; i > 1; i--) {
        swap(heap[1], heap[i]);
        downAdjust(1, i - 1);
    }
}
int main() {
    int a;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &heap[i]);
    }
    heapSort();
    for (int i = 1; i <= n; i++) {
        printf("%d ", heap[i]);
    }
    return 0;
}