// https://pintia.cn/problem-sets/994805342720868352/problems/994805528788582400

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

/*#include <cstdio>
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
}*/

// https://pintia.cn/problem-sets/994805342720868352/problems/994805528788582400
#include <iostream>
#include <stack>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    a += b;
    if (a < 0) {
        printf("-");
        a = -a;
    }
    if (a < 1000) {
        printf("%d", a);
        return 0;
    }
    stack<char> s;
    int cnt = 0;
    while (a != 0) {
        s.push(a % 10 + '0');
        if (++cnt % 3 == 0) s.push(',');
        a /= 10;
    }
    if (cnt % 3 == 0) s.pop();
    while (!s.empty()) {
        printf("%c", s.top());
        s.pop();
    }
    return 0;
}