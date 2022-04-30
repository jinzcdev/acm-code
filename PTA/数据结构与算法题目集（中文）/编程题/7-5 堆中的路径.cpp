// https://pintia.cn/api/problem-sets/15/problems/713
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int heap[N], len = 0;
void insertHeap(int x) {
    heap[++len] = x;
    for (int i = len, j = i / 2; j >= 1 && heap[i] < heap[j]; i = j, j /= 2) swap(heap[i], heap[j]);
}
int main() {
    int n, m, temp;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        insertHeap(temp);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &temp);
        printf("%d", heap[temp]);
        for (int j = temp / 2; j >= 1; j /= 2) {
            printf(" %d", heap[j]);
        }
        printf("\n");
    }
    return 0;
}