// https://pintia.cn/problem-sets/994805342720868352/problems/994805419468242944
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1010;
struct mouse {
    int weight;
    int R;
} mouse[maxn];
int main(){
    int np, ng, order;
    scanf("%d%d", &np, &ng);
    for (int i = 0; i < np; i++) {
        scanf("%d", &mouse[i].weight);
    }
    queue<int> q;
    for (int i = 0; i < np; i++) {
        scanf("%d", &order);
        q.push(order);
    }
    int temp = np, group;
    while (q.size() != 1) {
        if (temp % ng == 0) group = temp / ng;
        else group = temp / ng + 1;
        for (int i = 0; i < group; i++) {       // 选出每组中质量最大的老鼠
            int k = q.front();
            for (int j = 0; j < ng; j++) {
                if (i * ng + j >= temp) break;  // 超出该轮参赛选手总数,退出
                if (mouse[q.front()].weight > mouse[k].weight) {
                    k = q.front();
                }
                mouse[q.front()].R = group + 1; // 该轮老鼠的排名为group+1
                q.pop();
            }
            q.push(k);          // 本轮胜出者进入下一轮比赛
        }
        temp = group;           // 本轮组数即为下一轮比赛的人数
    }
    mouse[q.front()].R = 1;     // 第一名选手单独设置排名
    for (int i = 0; i < np; i++) {
        if (i != 0) printf(" ");
        printf("%d", mouse[i].R);
    }
    return 0;
}