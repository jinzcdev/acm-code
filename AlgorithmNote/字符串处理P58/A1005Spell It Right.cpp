#include <cstdio>
#include <cstring>
const int maxn = 110;
char digit[][6] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main(){
    char n[maxn];
    scanf("%s",n);
    int len = strlen(n);
    int sum = 0;
    for (int i = 0; i < len; i++){
        sum += n[i] - '0';
    }
    if(sum == 0){
        printf("zero");
        return 0;
    }

    int ans[5],k = 0;
    while(sum != 0){
        ans[k++] = sum % 10;
        sum = sum / 10;
    }

    for (int i = k - 1; i >= 0; i--){
        printf("%s",digit[ans[i]]);
        if(i > 0) printf(" ");
    }    
    return 0;
}