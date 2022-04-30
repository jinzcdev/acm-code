// https://pintia.cn/problem-sets/994805342720868352/problems/994805373582557184
#include <cstdio>
const int MOD = 1000000007;
int main() {
    char ch;
    int cnt = 0, cntP = 0, cntPA = 0;
    while ((ch = getchar()) != '\n') {
        if (ch == 'P') cntP++;
        else if (ch == 'A') cntPA += cntP;  // 碰到'A'表明可以产生P个PA组合
        else cnt = (cnt + cntPA) % MOD;     // 那么碰到'T'后则能产生PA个PAT组合
    }
    printf("%d", cnt);
    return 0;
}