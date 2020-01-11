// https://pintia.cn/problem-sets/994805260223102976/problems/994805300404535296
#include <cstdio>
#include <cstring>
char n[1010];
int ans[10] = {0};
int main() {
    scanf("%s", n);
    int len = strlen(n);
    for (int i = 0; i < len; i++) ans[n[i] - '0']++;
    for (int i = 0; i < 10; i++) {
        if (ans[i] != 0) {
            printf("%d:%d\n", i, ans[i]);
        }
    }
    return 0;
}
/*
#include <cstdio>
#include <cstring>
int main() {
    char str[1010];
    gets(str);
    int len = strlen(str);

    int count[10] = {0};
    for(int i = 0; i < len; i++) {
        count[str[i] - '0']++;
    }

    for(int i = 0; i < 10; i++) {
        if(count[i] != 0){
            printf("%d:%d\n", i, count[i]);
        }
    }
    return 0;
}
*/