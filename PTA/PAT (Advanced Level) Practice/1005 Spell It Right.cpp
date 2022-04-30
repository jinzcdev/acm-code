// https://pintia.cn/problem-sets/994805342720868352/problems/994805519074574336
#include <iostream>
using namespace std;
char change[10][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main() {
    char ch;
    int temp = 0;
    while ((ch = getchar()) != '\n') temp += ch - '0';
    string number = to_string(temp);
    for (int i = 0; i < number.size(); i++) {
        if (i != 0) printf(" ");
        printf("%s", change[number[i] - '0']);
    }
    return 0;
}
/*
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
    while(sum){
        ans[k++] = sum % 10;
        sum = sum / 10;
    }
    for (int i = k - 1; i >= 0; i--){
        printf("%s",digit[ans[i]]);
        if(i > 0) printf(" ");
    }    
    return 0;
}
*/