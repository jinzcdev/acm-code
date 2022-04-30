// https://pintia.cn/problem-sets/15/problems/713
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int heap[N], len = 0;
void insertHeap(int x) {
    int hole = ++len;
    for (; x < heap[hole / 2]; hole /= 2) heap[hole] = move(heap[hole / 2]);
    heap[hole] = move(x);
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
        for (int j = temp; j >= 1; j /= 2) {
            printf("%d", heap[j]);
            if (j != 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
vector<int> heap;
int len = 0;
void upAdjust(int low, int high) {
    int i = high, j = i / 2;
    while (j >= low) {
        if (heap[i] >= heap[j]) break;
        swap(heap[i], heap[j]);
        i = j;
        j = i / 2;
    }
}
void insertHeap(int x) {
    heap[++len] = x;
    upAdjust(1, len);
}
int main() {
    int n, m, a, pos;
    scanf("%d%d", &n, &m);
    heap.resize(n + 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        insertHeap(a);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &pos);
        for (int j = pos; j >= 1; j /= 2) {
            printf("%d", heap[j]);
            if (j != 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
*/