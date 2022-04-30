// https://pintia.cn/problem-sets/994805260223102976/problems/994805277847568384
#include <cstdio>
int main(){
    int n, cntA = 0, cntB = 0;
    int jia, yi, jiaNum, yiNum;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d%d%d", &jia, &jiaNum, &yi, &yiNum);
        int ans = jia + yi;
        if (jiaNum == ans && yiNum != ans) cntB++;
        else if (jiaNum != ans && yiNum == ans) cntA++;
    }
    printf("%d %d", cntA, cntB);
    return 0;
}