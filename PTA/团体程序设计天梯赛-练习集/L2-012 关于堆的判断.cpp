#include <bits/stdc++.h>
using namespace std;
vector<int> heap;
int len = 0;
void insert(int x) {
    int hole = ++len;
    for (; hole > 1 && heap[hole / 2] > x; hole /= 2)
        heap[hole] = move(heap[hole / 2]);
    heap[hole] = move(x);
}
int main() {
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    heap.resize(n + 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        insert(a);
    }
    unordered_map<int, int> pos;
    for (int i = 1; i <= n; i++) pos[heap[i]] = i;
    char temp[10];
    for (int i = 0; i < m; i++) {
        scanf("%d %s", &a, temp);
        if (strcmp(temp, "and") == 0) {
            scanf("%d %*s %*s", &b);
            printf("%c\n", pos[a] / 2 == pos[b] / 2 ? 'T' : 'F');
        } else {
            scanf("%*s %s", temp);
            if (strcmp(temp, "root") == 0) printf("%c\n", a == heap[1] ? 'T' : 'F');
            else {
                scanf("%*s %d", &b);
                if (strcmp(temp, "parent") == 0) printf("%c\n", pos[a] == pos[b] / 2 ? 'T' : 'F');
                else printf("%c\n", pos[b] == pos[a] / 2 ? 'T' : 'F');
            }
        }
    }
    return 0;
}