// http://codeup.cn/problem.php?cid=100000608&pid=4
#include <cstdio>
#include <stack>
using namespace std;
const int maxn = 20;
int ans[maxn] = {0};
int ins[maxn] = {false};
int n, cnt = 0;
stack<int> s;

void DFS(int index){
    if (s.size() == n){
        cnt++;
        return;
    }
    for (int x = 1; x <= n; x++){
        if (!ins[x]){
            s.push(x);
            ins[x];
            
        }
    }
    
}

int main(){
    scanf("%d", &n);
    // DFS();
    return 0;
}