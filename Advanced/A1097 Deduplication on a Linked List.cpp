// https://pintia.cn/problem-sets/994805342720868352/problems/994805369774129152
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct node{
    int address, data, next;
    int order, flag;            // -1:无效结点, 0:重复的结点 1:去重后的初始结点
} L[maxn];
bool isExist[maxn];

bool cmp(node a, node b){
    if (a.flag != b.flag)
        return a.flag > b.flag;
    else
        return a.order < b.order;
}

int main(){
    memset(isExist, false, sizeof(isExist));    // 默认为false(未出现过该结点)
    for (int i = 0; i < maxn; i++){
        L[i].flag = -1;                         // 默认全都无效结点
        L[i].order = maxn;                      // 所有元素序号设为最大值
    }
    int begin, n;
    scanf("%d%d", &begin, &n);
    for (int i = 0; i < n; i++){
        int address;
        scanf("%d", &address);
        scanf("%d%d", &L[address].data, &L[address].next);
        L[address].address = address;
    }

    int cnt = 0, cntRemoved = 0;    // 结点总数, 需要被移除的结点个数
    for (int p = begin; p != -1; p = L[p].next){
        int data = L[p].data >= 0 ? L[p].data : -L[p].data;
        if (!isExist[data]){
            isExist[data] = true;
            L[p].flag = 1;
        } else {
            L[p].flag = 0;
            cntRemoved++;
        }
        L[p].order = cnt++;
    }

    sort(L, L + maxn, cmp);
    for (int i = 0; i < cnt; i++){
        if (i == cnt - cntRemoved - 1 || i == cnt - 1){
            printf("%05d %d -1\n", L[i].address, L[i].data);
        }else{
            printf("%05d %d %05d\n", L[i].address, L[i].data, L[i + 1].address);
        }
    }
    
    return 0;
}

/*
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
 */