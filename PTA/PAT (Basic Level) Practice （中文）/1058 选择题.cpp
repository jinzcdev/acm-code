// https://pintia.cn/problem-sets/994805260223102976/problems/994805270356541440
#include <stdio.h>
#include <string.h>
struct {
    int score, cntOpt, rightNum, cntWrong;
    char ans[10];
} ques[1010];
char ch;
int n, m, rightNum, cntWrong = 0, len = 0;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &ques[i].score, &ques[i].cntOpt, &ques[i].rightNum);
        for (int j = 0; j < ques[i].rightNum; j++) scanf(" %c", &ques[i].ans[j]);
        ques[i].cntWrong = 0;
    }
    getchar();
    for (int i = 0; i < n; i++) {
        int grade = 0;
        for (int j = 0; j < m; j++) {
            int pos = 0;
            char choose[10] = "";
            scanf("(%d", &rightNum);
            if (rightNum == ques[j].rightNum) {
                while ((ch = getchar()) != ')') {
                    if (ch == ' ') continue;
                    else choose[pos++] = ch;
                }
                if (strcmp(choose, ques[j].ans) == 0) grade += ques[j].score;
                else ques[j].cntWrong++;
            } else {
                ques[j].cntWrong++;
                while ((ch = getchar()) != ')');
            }
            if (ques[j].cntWrong > cntWrong) cntWrong = ques[j].cntWrong;
            getchar();
        }
        printf("%d\n", grade);
    }
    if (cntWrong == 0) printf("Too simple");
    else {
        printf("%d", cntWrong);
        for (int j = 0; j < m; j++) {
            if (cntWrong == ques[j].cntWrong) printf(" %d", j + 1);
        }
    }
    return 0;
}
