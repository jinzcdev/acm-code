// https://pintia.cn/problem-sets/994805342720868352/problems/994805390896644096
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 256;
int minLen = 256;   // 记录可能的最长公共后缀位数

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    char str[100][maxn];
    int len;
    for (int i = 0; i < n; i++){
        fgets(str[i],sizeof(str[i]) + 2,stdin);
        len = strlen(str[i]);
        str[i][--len] = '\0';
        reverse(str[i],str[i] + len);
        if(len < minLen) minLen = len;
    }

    int same = -1,cnt;
    char ans[maxn];
    for (int i = 0; i < minLen; i++){
        cnt = 0;
        char c = str[0][i];
        for (int j = 1; j < n; j++){
            if(c == str[j][i])
                cnt++; 
        }
        if(cnt == n - 1){
            same = i;
        }else{
            break;
        }
    }

    if(same >= 0)
        for (int i = same; i >= 0; i--){
            printf("%c",str[0][i]);
        }
    else
        printf("nai");
    return 0;
}