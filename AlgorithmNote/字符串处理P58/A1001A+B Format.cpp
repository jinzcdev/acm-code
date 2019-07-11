/*
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int sum = a + b;
    if(sum < 0) printf("-");
    string s_sum = to_string(abs(sum));
    int len = s_sum.length();
    int temp = len % 3;
    int i;
    for (i = 0; i < temp; i++){
        printf("%c",s_sum[i]);
    }
    if(temp != 0 && len > 3) printf(",");

    int count = 0;
    for ( ; i < len; i++){
        if(count % 3 == 0 && count != 0) printf(",");
        printf("%c",s_sum[i]);
        count++;
    }
    return 0;
}
*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1000010;
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int sum = a + b;
    if(sum < 0){
        printf("-");
        sum = -sum;
    }
    int ans[maxn],len = 0;
    if(sum == 0) ans[len++] = 0;
    while(sum != 0){
        ans[len++] = sum % 10;
        sum = sum / 10;
    }
    for (int i = len - 1; i >= 0; i--){
        printf("%d",ans[i]);
        if(i > 0 && i % 3 == 0) printf(",");
    }
    return 0;
}