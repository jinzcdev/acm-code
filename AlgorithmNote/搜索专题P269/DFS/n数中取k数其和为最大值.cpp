#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 10;

int nums[maxn];
int n, k;
vector<int> ans, temp;
int maxSum = -1;

int cnt = 0;
void DFS(int index, int nowK, int sum){
    if (nowK == k){
        if (sum > maxSum){
            ans = temp;
            maxSum = sum;
        }
        return;
    }
    if (index < n){
        temp.push_back(nums[index]);
        DFS(index + 1, nowK + 1, sum + nums[index]);
        temp.pop_back();
        DFS(index + 1, nowK, sum);
    }
}

int main(){
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%d",nums + i);
    }
    DFS(0, 0, 0);
    for (int i = 0; i < ans.size(); i++){
        printf("%d ", ans[i]);
    }
    return 0;
}