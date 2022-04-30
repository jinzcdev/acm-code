// https://pintia.cn/problem-sets/994805046380707840/problems/994805143738892288
#include <cstdio>
#include <cstring>
int arr[10] = {0};

int convert(char ch){
    return ch - '0';
}

int main(){
    char str[1010];
    scanf("%s",str);
    int len = strlen(str);
    for(int i = 0;i < len;i++){
        int n = convert(str[i]);
        arr[n]++;
    }

    for(int i = 0;i < 10;i++){
        if(arr[i] != 0)
            printf("%d:%d\n",i,arr[i]);
    }
}