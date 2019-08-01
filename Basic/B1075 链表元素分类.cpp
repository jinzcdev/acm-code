// https://pintia.cn/problem-sets/994805260223102976/problems/994805262953594880
// Method 0:
#include <cstdio>
const int maxn = 100010;
struct node {
    int address, data, next;
} L[maxn];

void reverse(int head, int k){
    int temp = head;
    int last = L[head].next;
    if (last == -1)
        return;
    int p = L[last].next;
    int cnt = 0;            // 反转链表的前 k 个元素, cnt作计数
    while (p != -1 && ++cnt < k){
        L[last].next = L[p].next;
        L[p].next = L[head].next;
        L[head].next = p;
        p = L[last].next;
    }
}

int main(){
    int begin, n, k;
    scanf("%d%d%d", &begin, &n, &k);
    for (int i = 0; i < n; i++){
        int address;
        scanf("%d", &address);
        scanf("%d%d", &L[address].data, &L[address].next);
        L[address].address = address;
    }

    // 将所有负值结点移至链表最前端
    int head1 = maxn - 1, head2 = maxn - 2;     // 作为头结点指针
    L[head1].next = begin;                      // 头指针后继指针指向第一个链表结点
    L[head2].next = -1;                         // head2 新建链表的头指针
    int p = head1, q = L[head1].next, r = head2;
    int cnt = 0, last;
    bool flag = true;
    while (q != -1){
        if (L[q].data < 0){
            if (q == L[head1].next){    // 解决第一个元素为负数的时该节点指向本身进入死循环
                p = q;
                q = L[p].next;
            }else{
                L[p].next = L[q].next;
                L[q].next = L[head1].next;
                L[head1].next = q;
                q = L[p].next;
            }
            cnt++;
        }else if (L[q].data > k){       // data大于k的元素移至另一链表中
            L[p].next = L[q].next;
            L[q].next = -1;
            L[r].next = q;
            r = q;
            q = L[p].next;
        }else {                         // 向后遍历链表
            p = q;
            q = L[p].next;
        }
        if (L[p].next == -1){           // 保存主链表的最后一个节点指针以做链接
            last = p;
        }
    }

    L[last].next = L[head2].next;
    reverse(head1, cnt);

    p = L[head1].next;
    while (p != -1){
        printf("%05d %d ", p, L[p].data);
        if (L[p].next != -1){
            printf("%05d\n", L[p].next);
        }else {
            printf("-1");
        }
        p = L[p].next;
    }

    return 0;
}


// ---------------------------------------

// Method 1:
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100010, sortNum = 3;

struct node {
    int address, data, next;
} L[maxn];

int main(){
    vector<int> v[sortNum];   // 分别存放负数, [0,k]之间的数, 大于k的数
    int begin, n, k;
    scanf("%d%d%d", &begin, &n, &k);
    for (int i = 0; i < n; i++){
        int address;
        scanf("%d", &address);
        scanf("%d%d", &L[address].data, &L[address].next);
        L[address].address = address;
    }
    int p = begin;
    while (p != -1){    // 遍历链表将3类结点地址分别存入对应的vector
        if (L[p].data < 0) v[0].push_back(p);
        else if (L[p].data <= k) v[1].push_back(p);
        else v[2].push_back(p);
        p = L[p].next;
    }

    bool flag = false;
    for (int i = 0; i < sortNum; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (!flag) {
                printf("%05d %d ", v[i][j], L[v[i][j]].data);
                flag = true;
            }else {
                printf("%05d\n%05d %d ", v[i][j], v[i][j], L[v[i][j]].data);
            }
        }
    }
    printf("-1");
    return 0;
}



/*
00100 10 18
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
33333 2 -1
99999 5 68237
27777 11 48652
12309 7 33218
---------
00100 4 7
00100 7 00200
00200 1 00300
00300 -4 00400
00400 4 -1
---------
00100 3 3
00100 -2 00200
00200 2 00300
00300 -3 -1
---------
00100 3 3
00100 -2 00200
00200 2 00300
00300 -4 -1

-------------

00100 10 10
66666 17 11111
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218

*/


/*
int len = 3;
for (int i = 0; i < len; i++){
    for (int j = 0; j < v[i].size(); j++){
        if (j < v[i].size())
            printf("%05d %d ", v[i][j].address, v[i][j].data);
        if (j < v[i].size() - 1)
            printf("%05d\n", v[i][j + 1].address);
        else if (i < len - 1 && v[i + 1].size() > 0)
            printf("%05d\n", v[i + 1][0].address);
    }
}
 */