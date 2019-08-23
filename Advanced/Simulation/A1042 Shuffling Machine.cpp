// https://pintia.cn/problem-sets/994805342720868352/problems/994805442671132672
#include <cstdio>
const int maxn = 60;
char color[6] = "SHCDJ";
int card[maxn], temp[maxn], next[maxn];
int main(){
    for (int i = 1; i <= 54; i++){
        card[i] = i;                // 初始化当前牌编号从1-54, 便于获取花色是牌值
    }
    int k;
    scanf("%d", &k);
    for (int i = 1; i <= 54; i++){
        scanf("%d", &next[i]);
    }
    while (k--){
        for (int i = 1; i <= 54; i++){
            temp[next[i]] = card[i];    // 按顺序移动到新的暂存数组中
        }
        for (int i = 1; i <= 54; i++){
            card[i] = temp[i];          // 重新复制到原card数组中已做下一次的洗牌
        }
    }
    for (int i = 1; i <= 54; i++){
        printf("%c%d", color[(card[i] - 1) / 13], (card[i] - 1) % 13 + 1);
        if (i < 54) printf(" ");
    }
    return 0;
}