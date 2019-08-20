// https://pintia.cn/problem-sets/994805342720868352/problems/994805487143337984
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int n, b;
    scanf("%d%d", &n, &b);
    vector<int> ans;    // 省去计算转换后的长度, 用vector存储转换结果
    while (n != 0){     // 将n转为b进制数
        ans.push_back(n % b);
        n /= b;
    }
    int i = 0, len = ans.size();
    while (i < len / 2 && ans[i] == ans[len - i - 1]){
        i++;
    }
    if (i == len / 2){
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    for (int i = len - 1; i >= 0; i--){
        printf("%d", ans[i]);
        if (i > 0) printf(" ");
    }
    return 0;
}

/*
27 2

Yes
1 1 0 1 1
---------
121 5

No
4 4 1
*/