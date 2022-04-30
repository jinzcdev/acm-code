// https://pintia.cn/problem-sets/994805260223102976/problems/994805313708867584
#include <stdio.h>
int main() {
    int k, e, cnt = 0;
    while (scanf("%d%d", &k, &e) != EOF) {
        if (e != 0) {
            if (cnt++) printf(" ");
            printf("%d %d", k * e, e - 1);
        }
    }
    if (cnt == 0) printf("0 0");
    return 0;
}
/*
#include <stdio.h>
int main() {
    int e, k, cnt = 0, num[1010] = {0};
    while (scanf("%d%d", &k, &e) != EOF) {
        num[e] = k;
        if (e != 0) cnt++;
    }
    if (cnt == 0) printf("0 0");
    else {
        for (int i = 1000; i >= 1; i--) {
            if (num[i] != 0) {
                printf("%d %d", i * num[i], i - 1);
                if (--cnt != 0) printf(" ");
            }
        }
    }
    return 0;
}

#include <stdio.h>
int main() {
    int nums[80], len = 0, cntValid = 0;
    while ((scanf("%d", &nums[len++])) != EOF);
    for (int i = 0; i < len; i += 2) {
        nums[i] *= nums[i + 1];
        if (nums[i + 1] != 0) nums[i + 1]--;
        if (nums[i] != 0) cntValid++;
    }
    int flag = 0, cnt = 0;
    for (int i = 0; i < len; i += 2){
        if (nums[i] != 0) {
            printf("%d %d", nums[i], nums[i + 1]);
            flag = 1;
            if (++cnt < cntValid) printf(" ");
        }
    }
    if (!flag) printf("0 0");
    return 0;
}
*/