#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 20;
vector<int> temp, ans;
int n, k, x, maxSumSqu = -1, A[maxn];

void DFS(int index, int nowK, int sum, int sumSqu){
    if (nowK == k && sum == x){
        if (sumSqu > maxSumSqu){
            maxSumSqu = sumSqu;
            ans = temp;
        }
        return;
    }
    if (index == n || nowK > k || sum > x) return;
    temp.push_back(A[index]);
    DFS(index + 1, nowK + 1, sum + A[index], sumSqu + A[index] * A[index]);
    temp.pop_back();
    DFS(index + 1, nowK, sum, sumSqu);
}

int main(){
    scanf("%d%d%d", &n, &k, &x); 
    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    DFS(0, 0, 0, 0);
    for (vector<int>::iterator it = ans.begin(); it < ans.end(); it++){
        printf("%d", *it);
        if (it < ans.end() - 1) printf(" ");
    }
    return 0;
}

/*
6 2 6
2 3 3 1 4 5
*/