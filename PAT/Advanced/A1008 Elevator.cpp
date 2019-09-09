// https://pintia.cn/problem-sets/994805342720868352/problems/994805511923286016
#include <cstdio>
int main(){
    int n;
    scanf("%d", &n);
    int now = 0, to;
    int total = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &to);
        if (to > now){
            total += (to - now) * 6;
        }else{
            total += (now - to) * 4;
        }
        total += 5;
        now = to;
    }
    printf("%d", total);
    return 0;
}