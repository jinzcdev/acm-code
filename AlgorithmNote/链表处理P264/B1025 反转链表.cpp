// https://pintia.cn/problem-sets/994805260223102976/problems/994805296180871168
#include <cstdio>
using namespace std;
const int maxn = 100010;
int n, begin, k;

struct node {
    int data;
    int next;
} L[maxn];

int reverse(int k, int head){
    int temp = head;
    int last = L[head].next;
    int p = L[last].next;
    int cnt = 0, t = 0;
    while (p != -1 && cnt < n - n % k - 1){
        L[last].next = L[p].next;
        L[p].next = L[head].next;
        L[head].next = p;
        p = L[last].next;
        cnt++;
        t++;
        if (t == k - 1){
            head = last;
            last = L[head].next;
            if (last == -1) break;
            p = L[last].next;
            t = 0;
        }
    }
    return L[temp].next;
}

int main(){
    scanf("%d%d%d", &begin, &n, &k);
    // head.next = begin;      // 创建头结点便于对链表首部做插入或删除操作.
    int head = 10009;           // 创建一个头结点
    L[head].next = begin;
    for (int i = 0; i < n; i++){
        int pos;
        scanf("%d", &pos);
        scanf("%d%d", &L[pos].data, &L[pos].next);
    }
    int p = L[head].next;
    if (k != 1){
        p = reverse(k, head);
    }
  
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
33333 6 2
00000 1 11111
11111 2 22222
22222 3 -1
33333 4 44444
44444 5 55555
55555 6 -1

00100 6 2
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218


00100 6 1
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218


00100 3 2
00100 1 00200
00200 2 00300
00300 3 -1
*/