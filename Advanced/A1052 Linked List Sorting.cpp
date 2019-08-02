// https://pintia.cn/problem-sets/994805342720868352/problems/994805425780670464
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct node{
    int address, data, next;
    bool flag;
} L[maxn];

bool cmp(node a, node b){
    if (!a.flag || !b.flag){
        return a.flag > b.flag;     // 标记过的元素放到数组前端
    }else{
        return a.data < b.data;     // 均为有效结点则数值较小者排在前
    }
}

int main(){
    for (int i = 0; i < maxn; i++){
        L[i].flag = false;
    }
    int n, begin;
    scanf("%d%d", &n, &begin);
    for (int i = 0; i < n; i++){
        int address;
        scanf("%d", &address);
        scanf("%d%d", &L[address].data, &L[address].next);
        L[address].address = address;
    }
    int cnt = 0;
    for (int p = begin; p != -1; p = L[p].next){    // 输出的数据中存在无效结点, 通过flag标记是否有效
        L[p].flag = true;
        cnt++;
    }

    if (cnt == 0){          // 特殊情况, 直接输出结果
        printf("0 -1");
    }else{
        sort(L, L + maxn, cmp);
        printf("%d %05d\n", cnt, L[0].address);
        for (int i = 0; i < cnt; i++){
            if (i < cnt - 1){
                printf("%05d %d %05d\n", L[i].address, L[i].data, L[i + 1].address);
            }else{
                printf("%05d %d -1", L[i].address, L[i].data);
            }
        }
    }
    return 0;
}

/*
bool flag = false;
for (int i = 0; i < cnt; i++){
    if (!flag){
        printf("%05d %d ", L[i].address, L[i].data);
        flag = true;
    }else{
        printf("%05d\n%05d %d ", L[i].address, L[i].address, L[i].data);
    }
}
 */