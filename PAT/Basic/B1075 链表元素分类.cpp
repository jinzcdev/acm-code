// https://pintia.cn/problem-sets/994805260223102976/problems/994805262953594880
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100010, sortNum = 3;
struct node {
    int address, data, next;
} L[maxn];
int main() {
    vector<int> v[sortNum];  // 分别存放负数, [0,k]之间的数, 大于k的数
    int begin, n, k;
    scanf("%d%d%d", &begin, &n, &k);
    for (int i = 0; i < n; i++) {
        int address;
        scanf("%d", &address);
        scanf("%d%d", &L[address].data, &L[address].next);
        L[address].address = address;
    }
    int p = begin;
    while (p != -1) {  // 遍历链表将3类结点地址分别存入对应的vector
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
            } else {
                printf("%05d\n%05d %d ", v[i][j], v[i][j], L[v[i][j]].data);
            }
        }
    }
    printf("-1");
    return 0;
}