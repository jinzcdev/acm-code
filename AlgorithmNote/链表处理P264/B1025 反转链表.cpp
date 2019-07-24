// https://pintia.cn/problem-sets/994805260223102976/problems/994805296180871168
#include <cstdio>
using namespace std;
const int maxn = 100010;
int n, first, k;

struct node {
    int data;
    int next;
} L[maxn];

int head;

void reverse(int k){
    int cnt = 0;
    int last = L[head].next;
    int p = L[last].next;
    bool flag = true;p
    while (n >= k){
        L[last].next = L[p].next;
        L[p].next = L[head].next;
        L[head].next = p;
        p = L[last].next;
        cnt++;
        if (cnt == k - 1){
            if (flag){
                first = L[head].next;
                flag = false;
            }
            head = last;
            p = L[L[head].next].next;
            n = n - k;
        }
    }
}

int main(){
    scanf("%d%d%d", &first, &n, &k);
    // head.next = first;      // 创建头结点便于对链表首部做插入或删除操作.
    head = 10009;
    L[head].next = first;
    for (int i = 0; i < n; i++){
        int pos;
        scanf("%d", &pos);
        scanf("%d%d", &L[pos].data, &L[pos].next);
    }

    if (k != 1){
        reverse(k);
    }

    printf("-----------\n");

    int p = first;
    while (p != -1){
        printf("%05d %d ", p, L[p].data);
        if (L[p].next == -1){
            printf("-1");
        }else{
            printf("%05d\n", L[p].next);
        }
        p = L[p].next;
    }

    return 0;
}


/*
00100 6 3
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
*/