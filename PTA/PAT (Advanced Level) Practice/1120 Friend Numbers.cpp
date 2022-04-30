// https://pintia.cn/problem-sets/994805342720868352/problems/994805352925609984
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 40;

bool existed[maxn] = {false};       // 标记friendID是否出现过
vector<int> ans;

bool cmp(int a, int b){
    return a < b;
}

int getSum(int x){
    int sum = 0;
    while (x != 0){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main(){
    int n, x, temp, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        temp = getSum(x);
        if (!existed[temp]){                    // 总数和未出现过,添加至容器中
            ans.push_back(temp);
            existed[temp] = true;
            cnt++;
        }
    }
    sort(ans.begin(), ans.begin() + cnt, cmp);  // 对结果进行升序排序
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++){
        printf("%d", ans[i]);
        if (i < cnt - 1) printf(" ");
    }
    return 0;
}