// https://pintia.cn/problem-sets/15/problems/841
#include <iostream>
#include <vector>
using namespace std;
struct node {
    char msg[15];
    int prior;  // priority
};
vector<node*> heap;  //地址传递减少开销
int len = 0;
void downAdjust(int low, int high) {
    int i = low, j = i * 2;
    while (j <= high) {
        if (j + 1 <= high && heap[j + 1]->prior < heap[j]->prior) j = j + 1;
        if (heap[i]->prior <= heap[j]->prior) break;
        swap(heap[i], heap[j]);
        i = j;
        j = i * 2;
    }
}
void upAdjust(int low, int high) {
    int i = high, j = i / 2;
    while (j >= low) {
        if (heap[j]->prior <= heap[i]->prior) break;
        swap(heap[j], heap[i]);
        i = j;
        j = i / 2;
    }
}
node* deleteMin() {
    node* root = heap[1];
    heap[1] = heap[len--];
    downAdjust(1, len);
    return root;
}
void insertHeap(node* Node) {
    heap[++len] = Node;
    upAdjust(1, len);
}
int main() {
    int n;
    char cmd[5];
    scanf("%d", &n);
    heap.resize(n + 1);
    for (int i = 0; i < n; i++) {
        scanf("%s", cmd);
        if (cmd[0] == 'G') {
            if (len == 0)
                printf("EMPTY QUEUE!\n");
            else {
                node* top = deleteMin();
                printf("%s\n", top->msg);
            }
        } else {
            node* Node = new node;
            scanf("%s%d", Node->msg, &Node->prior);
            insertHeap(Node);
        }
    }
    return 0;
}